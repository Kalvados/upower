/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2008 David Zeuthen <davidz@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <linux/fs.h>
#include <sys/ioctl.h>
#include <glib.h>

#include "sysfs-utils.h"

double
sysfs_get_double (const char *dir, const char *attribute)
{
	double result;
	char *contents;
	char *filename;

	result = 0.0;
	filename = g_build_filename (dir, attribute, NULL);
	if (g_file_get_contents (filename, &contents, NULL, NULL)) {
		result = atof (contents);
		g_free (contents);
	}
	g_free (filename);


	return result;
}

gboolean
sysfs_file_contains (const char *dir, const char *attribute, const char *string)
{
	gboolean result;
	char *filename;
	char *s;

	result = FALSE;

	filename = g_build_filename (dir, attribute, NULL);
	if (g_file_get_contents (filename, &s, NULL, NULL)) {
		result = (strstr(s, string) != NULL);
		g_free (s);
	}
	g_free (filename);

	return result;
}

char *
sysfs_get_string (const char *dir, const char *attribute)
{
	char *result;
	char *filename;

	result = NULL;
	filename = g_build_filename (dir, attribute, NULL);
	if (!g_file_get_contents (filename, &result, NULL, NULL)) {
		result = g_strdup ("");
	}
	g_free (filename);

	return result;
}

int
sysfs_get_int (const char *dir, const char *attribute)
{
	int result;
	char *contents;
	char *filename;

	result = 0;
	filename = g_build_filename (dir, attribute, NULL);
	if (g_file_get_contents (filename, &contents, NULL, NULL)) {
		result = atoi (contents);
		g_free (contents);
	}
	g_free (filename);

	return result;
}

guint
sysfs_get_hex (const char *dir, const char *attribute)
{
	guint result;
	char *contents;
	char *filename;

	result = 0;
	filename = g_build_filename (dir, attribute, NULL);
	if (g_file_get_contents (filename, &contents, NULL, NULL)) {
		result = strtol (contents, (char **) NULL, 16);
		g_free (contents);
	}
	g_free (filename);

	return result;
}

gboolean
sysfs_get_bool (const char *dir, const char *attribute)
{
	gboolean result = FALSE;
	char *contents;
	char *filename;

	result = 0;
	filename = g_build_filename (dir, attribute, NULL);
	if (g_file_get_contents (filename, &contents, NULL, NULL)) {
		g_strdelimit (contents, "\n", '\0');
		if (g_strcmp0 (contents, "1") == 0)
			result = TRUE;
		g_free (contents);
	}
	g_free (filename);

	return result;
}

guint64
sysfs_get_uint64 (const char *dir, const char *attribute)
{
	guint64 result;
	char *contents;
	char *filename;

	result = 0;
	filename = g_build_filename (dir, attribute, NULL);
	if (g_file_get_contents (filename, &contents, NULL, NULL)) {
		result = atoll (contents);
		g_free (contents);
	}
	g_free (filename);


	return result;
}

gboolean
sysfs_file_exists (const char *dir, const char *attribute)
{
	gboolean result;
	char *filename;

	result = FALSE;
	filename = g_build_filename (dir, attribute, NULL);
	if (g_file_test (filename, G_FILE_TEST_EXISTS)) {
		result = TRUE;
	}
	g_free (filename);

	return result;
}

char *
_dupv8 (const char *s)
{
	const char *end_valid;

	if (!g_utf8_validate (s,
			     -1,
			     &end_valid)) {
		g_warning ("The string '%s' is not valid UTF-8. Invalid characters begins at '%s'", s, end_valid);
		return g_strndup (s, end_valid - s);
	} else {
		return g_strdup (s);
	}
}

char *
sysfs_resolve_link (const char *dir, const char *attribute)
{
	char *full_path;
	char link_path[PATH_MAX];
	char resolved_path[PATH_MAX];
	ssize_t num;
	gboolean found_it;

	found_it = FALSE;

	full_path = g_build_filename (dir, attribute, NULL);

	//egg_warning ("attribute='%s'", attribute);
	//egg_warning ("full_path='%s'", full_path);
	num = readlink (full_path, link_path, sizeof (link_path) - 1);
	if (num != -1) {
		char *absolute_path;

		link_path[num] = '\0';

		//egg_warning ("link_path='%s'", link_path);
		absolute_path = g_build_filename (dir, link_path, NULL);
		//egg_warning ("absolute_path='%s'", absolute_path);
		if (realpath (absolute_path, resolved_path) != NULL) {
			//egg_warning ("resolved_path='%s'", resolved_path);
			found_it = TRUE;
		}
		g_free (absolute_path);
	}
	g_free (full_path);

	if (found_it)
		return g_strdup (resolved_path);
	else
		return NULL;
}
