/*
 * LIBOIL - Library of Optimized Inner Loops
 * Copyright (c) 2003,2004 David A. Schleef <ds@schleef.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _LIBOIL_PARAMETER_H_
#define _LIBOIL_PARAMETER_H_

#include <liboil/liboiltypes.h>

enum _OilType {
  OIL_TYPE_UNKNOWN = 0,
  OIL_TYPE_INT,
  OIL_TYPE_s8,
  OIL_TYPE_u8,
  OIL_TYPE_s16,
  OIL_TYPE_u16,
  OIL_TYPE_s32,
  OIL_TYPE_u32,
  OIL_TYPE_f32,
  OIL_TYPE_f64,
  OIL_TYPE_s8p,
  OIL_TYPE_u8p,
  OIL_TYPE_s16p,
  OIL_TYPE_u16p,
  OIL_TYPE_s32p,
  OIL_TYPE_u32p,
  OIL_TYPE_f32p,
  OIL_TYPE_f64p,
};

enum _OilArgType {
  OIL_ARG_UNKNOWN = 0,
  OIL_ARG_N,
  OIL_ARG_M,
  OIL_ARG_DEST1,
  OIL_ARG_DSTR1,
  OIL_ARG_DEST2,
  OIL_ARG_DSTR2,
  OIL_ARG_SRC1,
  OIL_ARG_SSTR1,
  OIL_ARG_SRC2,
  OIL_ARG_SSTR2,
  OIL_ARG_SRC3,
  OIL_ARG_SSTR3,
  OIL_ARG_SRC4,
  OIL_ARG_SSTR4,
  OIL_ARG_SRC5,
  OIL_ARG_SSTR5,
  OIL_ARG_INPLACE1,
  OIL_ARG_ISTR1,
  OIL_ARG_INPLACE2,
  OIL_ARG_ISTR2,

  OIL_ARG_LAST
};

struct _OilParameter {
  char *type_name;
  char *parameter_name;

  int order;
  OilType type;

  int direction;
  int is_stride;
  int index;
  int prestride_length;
  int prestride_var;
  int poststride_length;
  int poststride_var;

  OilArgType parameter_type;

  void *ptr;
  unsigned long value;
  int size;
};

#endif
