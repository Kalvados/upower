/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2008 Richard Hughes <richard@hughsie.com>
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

#if !defined (__UPOWER_H_INSIDE__) && !defined (UP_COMPILATION)
#error "Only <devicekit-power.h> can be included directly."
#endif

#ifndef __DKP_STATS_OBJ_H__
#define __DKP_STATS_OBJ_H__

#include <glib.h>
#include <devkit-power-gobject/dkp-enum.h>

G_BEGIN_DECLS

typedef struct
{
	gdouble			 value;
	gdouble			 accuracy;
} DkpStatsObj;

typedef DkpStatsObj UpStatsObj;

#define up_stats_obj_create		dkp_stats_obj_create

DkpStatsObj	*dkp_stats_obj_new		(void);
gboolean	 dkp_stats_obj_free		(DkpStatsObj		*obj);
DkpStatsObj	*dkp_stats_obj_copy		(const DkpStatsObj	*cobj);
DkpStatsObj	*dkp_stats_obj_create		(gdouble		 value,
						 gdouble		 accuracy);
DkpStatsObj	*dkp_stats_obj_from_string	(const gchar		*text);
gchar		*dkp_stats_obj_to_string	(const DkpStatsObj	*obj);

G_END_DECLS

#endif /* __DKP_STATS_OBJ_H__ */

