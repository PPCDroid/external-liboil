/*
 * LIBOIL - Library of Optimized Inner Loops
 * Copyright (c) 2001,2003,2004 David A. Schleef <ds@schleef.org>
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <liboil/liboilfunction.h>

#include <math.h>
#include <string.h>
#include <stdlib.h>



#define CONV_DEFINE_REF_CAST(desttype,srctype) \
static void conv_ ## desttype ## _ ## srctype ## _ref ( \
	type_ ## desttype *dest,	\
	int dest_stride,		\
	type_ ## srctype *src,		\
	int src_stride, int n)	 	\
{					\
	int i;				\
	for(i=0;i<n;i++){		\
		OIL_GET(dest,i*dest_stride, type_ ## desttype) = \
			OIL_GET(src,i*src_stride, type_ ## srctype);	\
	}				\
}					\
OIL_DEFINE_CLASS(conv_ ## desttype ## _ ## srctype,	\
	"type_" #desttype " *dest, "	\
	"int dstr, "			\
	"type_" #srctype " *src, "	\
	"int sstr, int n");	 	\
OIL_DEFINE_IMPL_REF(conv_ ## desttype ## _ ## srctype ## _ref,	\
	conv_ ## desttype ## _ ## srctype)

#define CONV_DEFINE_FLOAT_REF(desttype,srctype) \
static void conv_ ## desttype ## _ ## srctype ## _ref ( \
	type_ ## desttype *dest,	\
	int dest_stride,		\
	type_ ## srctype *src,		\
	int src_stride, int n) 		\
{					\
	int i;				\
	for(i=0;i<n;i++){		\
		OIL_GET(dest,i*dest_stride, type_ ## desttype) =		\
			rint(OIL_GET(src,i*src_stride, type_ ## srctype));	\
	}				\
}					\
OIL_DEFINE_CLASS(conv_ ## desttype ## _ ## srctype,	\
	"type_" #desttype " *dest, "	\
	"int dstr, "			\
	"type_" #srctype " *src, "	\
	"int sstr, int n");	 	\
OIL_DEFINE_IMPL_REF(conv_ ## desttype ## _ ## srctype ## _ref,	\
	conv_ ## desttype ## _ ## srctype)

CONV_DEFINE_REF_CAST(s8,u8);
CONV_DEFINE_REF_CAST(s8,s16);
CONV_DEFINE_REF_CAST(s8,u16);
CONV_DEFINE_REF_CAST(s8,s32);
CONV_DEFINE_REF_CAST(s8,u32);
CONV_DEFINE_FLOAT_REF(s8,f32);
CONV_DEFINE_FLOAT_REF(s8,f64);

CONV_DEFINE_REF_CAST(u8,s8);
CONV_DEFINE_REF_CAST(u8,s16);
CONV_DEFINE_REF_CAST(u8,u16);
CONV_DEFINE_REF_CAST(u8,s32);
CONV_DEFINE_REF_CAST(u8,u32);
CONV_DEFINE_FLOAT_REF(u8,f32);
CONV_DEFINE_FLOAT_REF(u8,f64);

CONV_DEFINE_REF_CAST(s16,s8);
CONV_DEFINE_REF_CAST(s16,u8);
CONV_DEFINE_REF_CAST(s16,u16);
CONV_DEFINE_REF_CAST(s16,s32);
CONV_DEFINE_REF_CAST(s16,u32);
CONV_DEFINE_FLOAT_REF(s16,f32);
CONV_DEFINE_FLOAT_REF(s16,f64);

CONV_DEFINE_REF_CAST(u16,s8);
CONV_DEFINE_REF_CAST(u16,u8);
CONV_DEFINE_REF_CAST(u16,s16);
CONV_DEFINE_REF_CAST(u16,s32);
CONV_DEFINE_REF_CAST(u16,u32);
CONV_DEFINE_FLOAT_REF(u16,f32);
CONV_DEFINE_FLOAT_REF(u16,f64);

CONV_DEFINE_REF_CAST(s32,s8);
CONV_DEFINE_REF_CAST(s32,s16);
CONV_DEFINE_REF_CAST(s32,u8);
CONV_DEFINE_REF_CAST(s32,u16);
CONV_DEFINE_REF_CAST(s32,u32);
CONV_DEFINE_FLOAT_REF(s32,f32);
CONV_DEFINE_FLOAT_REF(s32,f64);

CONV_DEFINE_REF_CAST(u32,s8);
CONV_DEFINE_REF_CAST(u32,s16);
CONV_DEFINE_REF_CAST(u32,u8);
CONV_DEFINE_REF_CAST(u32,u16);
CONV_DEFINE_REF_CAST(u32,s32);
CONV_DEFINE_FLOAT_REF(u32,f32);
CONV_DEFINE_FLOAT_REF(u32,f64);

CONV_DEFINE_REF_CAST(f32,s8);
CONV_DEFINE_REF_CAST(f32,s16);
CONV_DEFINE_REF_CAST(f32,u8);
CONV_DEFINE_REF_CAST(f32,u16);
CONV_DEFINE_REF_CAST(f32,s32);
CONV_DEFINE_REF_CAST(f32,u32);
CONV_DEFINE_REF_CAST(f32,f64);

CONV_DEFINE_REF_CAST(f64,s8);
CONV_DEFINE_REF_CAST(f64,u8);
CONV_DEFINE_REF_CAST(f64,s16);
CONV_DEFINE_REF_CAST(f64,u16);
CONV_DEFINE_REF_CAST(f64,s32);
CONV_DEFINE_REF_CAST(f64,u32);
CONV_DEFINE_REF_CAST(f64,f32);




#define CLIPCONV_DEFINE_BOTH_REF(desttype,srctype) \
static void clipconv_ ## desttype ## _ ## srctype ## _ref ( \
	type_ ## desttype *dest,	\
	int dest_stride,		\
	type_ ## srctype *src,		\
	int src_stride, int n)		\
{					\
	int i;				\
	type_ ## srctype x;		\
	for(i=0;i<n;i++){		\
		x = OIL_GET(src,i*src_stride, type_ ## srctype);			\
		if(x<type_min_ ## desttype) x=type_min_ ## desttype;	\
		if(x>type_max_ ## desttype) x=type_max_ ## desttype;	\
		OIL_GET(dest,i*dest_stride, type_ ## desttype) = x;			\
	}				\
}					\
OIL_DEFINE_CLASS(clipconv_ ## desttype ## _ ## srctype,	\
	"type_" #desttype " *dest, "	\
	"int dstr, "			\
	"type_" #srctype " *src, "	\
	"int sstr, int n");	 	\
OIL_DEFINE_IMPL_REF(clipconv_ ## desttype ## _ ## srctype ## _ref,	\
	clipconv_ ## desttype ## _ ## srctype)

#define CLIPCONV_DEFINE_UPPER_REF(desttype,srctype) \
static void clipconv_ ## desttype ## _ ## srctype ## _ref ( \
	type_ ## desttype *dest,	\
	int dest_stride,		\
	type_ ## srctype *src,		\
	int src_stride, int n)		\
{					\
	int i;				\
	type_ ## srctype x;		\
	for(i=0;i<n;i++){		\
		x = OIL_GET(src,i*src_stride, type_ ## srctype);			\
		if(x>type_max_ ## desttype) x=type_max_ ## desttype;	\
		OIL_GET(dest,i*dest_stride, type_ ## desttype) = x;			\
	}				\
}					\
OIL_DEFINE_CLASS(clipconv_ ## desttype ## _ ## srctype,	\
	"type_" #desttype " *dest, "	\
	"int dstr, "			\
	"type_" #srctype " *src, "	\
	"int sstr, int n");	 	\
OIL_DEFINE_IMPL_REF(clipconv_ ## desttype ## _ ## srctype ## _ref,	\
	clipconv_ ## desttype ## _ ## srctype)

#define CLIPCONV_DEFINE_LOWER_REF(desttype,srctype) \
static void clipconv_ ## desttype ## _ ## srctype ## _ref ( \
	type_ ## desttype *dest,	\
	int dest_stride,		\
	type_ ## srctype *src,		\
	int src_stride, int n)		\
{					\
	int i;				\
	type_ ## srctype x;		\
	for(i=0;i<n;i++){		\
		x = OIL_GET(src,i*src_stride, type_ ## srctype);			\
		if(x<type_min_ ## desttype) x=type_min_ ## desttype;	\
		OIL_GET(dest,i*dest_stride, type_ ## desttype) = x;			\
	}				\
}					\
OIL_DEFINE_CLASS(clipconv_ ## desttype ## _ ## srctype,	\
	"type_" #desttype " *dest, "	\
	"int dstr, "			\
	"type_" #srctype " *src, "	\
	"int sstr, int n");	 	\
OIL_DEFINE_IMPL_REF(clipconv_ ## desttype ## _ ## srctype ## _ref,	\
	clipconv_ ## desttype ## _ ## srctype)

#define CLIPCONV_DEFINE_FLOAT_REF(desttype,srctype) \
static void clipconv_ ## desttype ## _ ## srctype ## _ref ( \
	type_ ## desttype *dest,	\
	int dest_stride,		\
	type_ ## srctype *src,		\
	int src_stride, int n)		\
{					\
	int i;				\
	type_ ## srctype x;		\
	for(i=0;i<n;i++){		\
		x = OIL_GET(src,i*src_stride, type_ ## srctype);			\
		if(x<type_min_ ## desttype) x=type_min_ ## desttype;	\
		if(x>type_max_ ## desttype) x=type_max_ ## desttype;	\
		OIL_GET(dest,i*dest_stride, type_ ## desttype) = rint(x);		\
	}				\
}					\
OIL_DEFINE_CLASS(clipconv_ ## desttype ## _ ## srctype,	\
	"type_" #desttype " *dest, "	\
	"int dstr, "			\
	"type_" #srctype " *src, "	\
	"int sstr, int n");	 	\
OIL_DEFINE_IMPL_REF(clipconv_ ## desttype ## _ ## srctype ## _ref,	\
	clipconv_ ## desttype ## _ ## srctype)

/* clip upper */
CLIPCONV_DEFINE_UPPER_REF(s8,u8);
CLIPCONV_DEFINE_UPPER_REF(s8,u16);
CLIPCONV_DEFINE_UPPER_REF(s8,u32);
CLIPCONV_DEFINE_UPPER_REF(u8,u32);
CLIPCONV_DEFINE_UPPER_REF(u8,u16);
CLIPCONV_DEFINE_UPPER_REF(s16,u16);
CLIPCONV_DEFINE_UPPER_REF(s16,u32);
CLIPCONV_DEFINE_UPPER_REF(s32,u32);
CLIPCONV_DEFINE_UPPER_REF(u16,u32);

/* clip both */
CLIPCONV_DEFINE_BOTH_REF(s8,s16);
CLIPCONV_DEFINE_BOTH_REF(s8,s32);
CLIPCONV_DEFINE_BOTH_REF(u8,s16);
CLIPCONV_DEFINE_BOTH_REF(u8,s32);
CLIPCONV_DEFINE_BOTH_REF(s16,s32);
CLIPCONV_DEFINE_BOTH_REF(u16,s32);

/* clip lower */
CLIPCONV_DEFINE_LOWER_REF(u8,s8);
CLIPCONV_DEFINE_LOWER_REF(u16,s16);
CLIPCONV_DEFINE_LOWER_REF(u32,s32);

/* clip both, float */
CLIPCONV_DEFINE_FLOAT_REF(s8,f32);
CLIPCONV_DEFINE_FLOAT_REF(s8,f64);
CLIPCONV_DEFINE_FLOAT_REF(u8,f32);
CLIPCONV_DEFINE_FLOAT_REF(u8,f64);
CLIPCONV_DEFINE_FLOAT_REF(s16,f32);
CLIPCONV_DEFINE_FLOAT_REF(s16,f64);
CLIPCONV_DEFINE_FLOAT_REF(u16,f32);
CLIPCONV_DEFINE_FLOAT_REF(u16,f64);
CLIPCONV_DEFINE_FLOAT_REF(s32,f32);
CLIPCONV_DEFINE_FLOAT_REF(s32,f64);
CLIPCONV_DEFINE_FLOAT_REF(u32,f32);
CLIPCONV_DEFINE_FLOAT_REF(u32,f64);




#if 0
void conv_double_float_dstr(double *dest, float *src, int n, int dstr)
{
	int i;
	void *d = dest;
	for(i=0;i<n;i++){
		(*(double *)d)=*src++;
		d += dstr;
	}
}

void conv_float_double_sstr(float *dest, double *src, int n, int sstr)
{
	int i;
	void *s = src;

	for(i=0;i<n;i++){
		*dest++ = *(double *)s;
		s += sstr;
	}
}
#endif

#ifdef unused
static int get_type(const char *s)
{
	static const char *typenames[8] = { "_s8", "_u8", "_s16", "_u16",
		"_s32", "_u32", "_f32", "_f64" };
	int i;

	for(i=0;i<8;i++){
		if(strncmp(s, typenames[i], strlen(typenames[i]))==0){
			return i;
		}
	}

	return 0;
}
#endif

#ifdef unused
static void conv_test(OilFunctionClass *klass, OilFunctionImpl *impl)
{
	int n_iter = 100;
	int length = 100;
	int typesizes[8] = { 1, 1, 2, 2, 4, 4, 4, 8 };
	const char *s;
	int type1, type2;
	void *src;
	void *dest;
	OilProfile prof;
	int n;

	//printf("  testing %s\n", klass->name);

	s = strchr(klass->name, '_');
	type1 = get_type(s);

	s = strchr(s+1, '_');
	type2 = get_type(s);

	//printf("  types %d %d\n", type1, type2);

	dest = malloc(n_iter * typesizes[type1]);
	src = malloc(n_iter * typesizes[type2]);

	memset(src,0,n_iter * typesizes[type2]);
#if 0
	dest = malloc(n_iter * 8);
	src = malloc(n_iter * 8);
#endif

	oil_profile_init(prof);
	for(n=0;n<n_iter;n++){
		oil_profile_start(prof);
		((void (*)(void *, int, void *, int, int))impl->func)
			(dest, typesizes[type1], src, typesizes[type2], length);
		oil_profile_stop(prof);
	}

	//oil_profile_print(prof);

	impl->prof = prof.tmin;

	free(dest);
	free(src);
}
#endif
