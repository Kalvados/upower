/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2008 David Zeuthen <davidz@redhat.com>
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

#ifndef __DKP_ENUM_H__
#define __DKP_ENUM_H__

#include <glib.h>

G_BEGIN_DECLS

typedef enum {
	DKP_DEVICE_TYPE_UNKNOWN,
	DKP_DEVICE_TYPE_LINE_POWER,
	DKP_DEVICE_TYPE_BATTERY,
	DKP_DEVICE_TYPE_UPS,
	DKP_DEVICE_TYPE_MONITOR,
	DKP_DEVICE_TYPE_MOUSE,
	DKP_DEVICE_TYPE_KEYBOARD,
	DKP_DEVICE_TYPE_PDA,
	DKP_DEVICE_TYPE_PHONE,
	DKP_DEVICE_TYPE_LAST
} DkpDeviceType;

typedef enum {
	DKP_DEVICE_STATE_UNKNOWN,
	DKP_DEVICE_STATE_CHARGING,
	DKP_DEVICE_STATE_DISCHARGING,
	DKP_DEVICE_STATE_EMPTY,
	DKP_DEVICE_STATE_FULLY_CHARGED,
	DKP_DEVICE_STATE_PENDING_CHARGE,
	DKP_DEVICE_STATE_PENDING_DISCHARGE,
	DKP_DEVICE_STATE_LAST
} DkpDeviceState;

typedef enum {
	DKP_DEVICE_TECHNOLOGY_UNKNOWN,
	DKP_DEVICE_TECHNOLOGY_LITHIUM_ION,
	DKP_DEVICE_TECHNOLOGY_LITHIUM_POLYMER,
	DKP_DEVICE_TECHNOLOGY_LITHIUM_IRON_PHOSPHATE,
	DKP_DEVICE_TECHNOLOGY_LEAD_ACID,
	DKP_DEVICE_TECHNOLOGY_NICKEL_CADMIUM,
	DKP_DEVICE_TECHNOLOGY_NICKEL_METAL_HYDRIDE,
	DKP_DEVICE_TECHNOLOGY_LAST
} DkpDeviceTechnology;

typedef enum {
	DKP_QOS_TYPE_UNKNOWN,
	DKP_QOS_TYPE_NETWORK,
	DKP_QOS_TYPE_CPU_DMA,
	DKP_QOS_TYPE_LAST
} DkpQosType;

const gchar	*dkp_device_type_to_text	(DkpDeviceType		 type_enum);
const gchar	*dkp_device_state_to_text	(DkpDeviceState		 state_enum);
const gchar	*dkp_device_technology_to_text	(DkpDeviceTechnology	 technology_enum);
DkpDeviceType	 dkp_device_type_from_text	(const gchar		*type);
DkpDeviceState	 dkp_device_state_from_text	(const gchar		*state);
DkpDeviceTechnology dkp_device_technology_from_text (const gchar	*technology);
const gchar	*dkp_qos_type_to_text		(DkpQosType		 type);
DkpQosType	 dkp_qos_type_from_text		(const gchar		*type);

G_END_DECLS

#endif /* __DKP_ENUM_H__ */

