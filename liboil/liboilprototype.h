/* liboil - Library of Optimized Inner Loops
 * Copyright (C) 2003,2004  David A. Schleef <ds@schleef.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of version 2.1 of the GNU Lesser General
 * Public License as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307 USA.
 */

#ifndef _LIBOIL_PROTOTYPE_H_
#define _LIBOIL_PROTOTYPE_H_

typedef struct _OilParameter OilParameter;
struct _OilParameter {
  char *type;
  int ptr;
  char *name;
};

typedef struct _OilPrototype OilPrototype;
struct _OilPrototype {
  int n_params;
  OilParameter *params;
};

enum{
  OIL_TYPE_UNKNOWN,
  OIL_TYPE_s8,
  OIL_TYPE_u8,
  OIL_TYPE_s16,
  OIL_TYPE_u16,
  OIL_TYPE_s32,
  OIL_TYPE_u32,
  OIL_TYPE_f32,
  OIL_TYPE_f64,
};


OilPrototype *oil_prototype_from_string (const char *s);
char *oil_prototype_to_string (OilPrototype *proto);
void oil_prototype_free (OilPrototype *proto);
void oil_prototype_append_param (OilPrototype *proto, OilParameter *param);


#endif
