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
#include <string.h>

OIL_DEFINE_CLASS(splat_u8,"uint8_t *dest, int dstr, uint8_t *s1_1, int n");
OIL_DEFINE_CLASS(splat_u32,"uint32_t *dest, int dstr, uint32_t *s1_1, int n");
OIL_DEFINE_CLASS(splat_u8_ns,"uint8_t *dest, uint8_t *s1_1, int n");
OIL_DEFINE_CLASS(splat_u32_ns,"uint32_t *dest, uint32_t *s1_1, int n");


static void splat_u8_ref (uint8_t *dest, int dstr, uint8_t *param, int n)
{
  int i;
  for(i=0;i<n;i++){
    OIL_GET(dest,i*dstr, uint8_t) = *param;
  }
}
OIL_DEFINE_IMPL_REF(splat_u8_ref, splat_u8);

static void splat_u32_ref (uint32_t *dest, int dstr, uint32_t *param, int n)
{
  int i;
  for(i=0;i<n;i++){
    OIL_GET(dest,i*dstr, uint32_t) = *param;
  }
}
OIL_DEFINE_IMPL_REF(splat_u32_ref, splat_u32);


static void splat_u8_ns_ref (uint8_t *dest, uint8_t *param, int n)
{
  int i;
  for(i=0;i<n;i++){
    dest[i] = *param;
  }
}
OIL_DEFINE_IMPL_REF(splat_u8_ns_ref, splat_u8_ns);

static void splat_u32_ns_ref (uint32_t *dest, uint32_t *param, int n)
{
  int i;
  for(i=0;i<n;i++){
    dest[i] = *param;
  }
}
OIL_DEFINE_IMPL_REF(splat_u32_ns_ref, splat_u32_ns);




static void splat_u32_unroll2 (uint32_t *dest, int dstr, uint32_t *param, int n)
{
  int i;
  if (n&1) {
    *dest = *param;
    OIL_INCREMENT(dest,dstr);
  }
  n >>= 1;
  for(i=0;i<n;i++){
    *dest = *param;
    OIL_INCREMENT(dest,dstr);
    *dest = *param;
    OIL_INCREMENT(dest,dstr);
  }
}
OIL_DEFINE_IMPL(splat_u32_unroll2, splat_u32);

static void splat_u32_ns_unroll2 (uint32_t *dest, uint32_t *param, int n)
{
  int i;
  if (n&1) {
    *dest = *param;
    dest++;
  }
  n >>= 1;
  for(i=0;i<n;i++){
    *dest = *param;
    dest++;
    *dest = *param;
    dest++;
  }
}
OIL_DEFINE_IMPL(splat_u32_ns_unroll2, splat_u32_ns);

static void splat_u32_ns_unroll4 (uint32_t *dest, uint32_t *param, int n)
{
  int i;
  while (n&3) {
    *dest = *param;
    dest++;
    n--;
  }
  n >>= 2;
  for(i=0;i<n;i++){
    dest[0] = *param;
    dest[1] = *param;
    dest[2] = *param;
    dest[3] = *param;
    dest+=4;
  }
}
OIL_DEFINE_IMPL(splat_u32_ns_unroll4, splat_u32_ns);

static void splat_u8_ns_memset (uint8_t *dest, uint8_t *param, int n)
{
  memset (dest, *param, n);
}
OIL_DEFINE_IMPL(splat_u8_ns_memset, splat_u8_ns);

static void splat_u8_ns_int (uint8_t *dest, uint8_t *param, int n)
{
  int p;
  while(n&3) {
    *dest = *param;
    dest++;
    n--;
  }
  n >>= 2;
  p = (*param<<24) | (*param<<16) | (*param<<8) | (*param);
  while(n>0){
    *(uint32_t *)dest = p;
    dest+=4;
    n--;
  }
}
OIL_DEFINE_IMPL(splat_u8_ns_int, splat_u8_ns);


