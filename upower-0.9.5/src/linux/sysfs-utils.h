/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 8 -*-
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

#ifndef __SYSFS_UTILS_H__
#define __SYSFS_UTILS_H__

#include <glib.h>

double    sysfs_get_double    (const char *dir, const char *attribute);
gboolean  sysfs_file_contains (const char *dir, const char *attribute, const char *string);
char     *sysfs_get_string    (const char *dir, const char *attribute);
int       sysfs_get_int       (const char *dir, const char *attribute);
guint     sysfs_get_hex       (const char *dir, const char *attribute);
gboolean  sysfs_get_bool      (const char *dir, const char *attribute);
guint64   sysfs_get_uint64    (const char *dir, const char *attribute);
gboolean  sysfs_file_exists   (const char *dir, const char *attribute);
char     *sysfs_resolve_link  (const char *dir, const char *attribute);

char *_dupv8 (const char *s);

#endif /* __SYSFS_UTILS_H__ */
