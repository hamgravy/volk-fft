/* -*- c++ -*- */
/*
 * Copyright 2014 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include "volk_fft/volk_fft_generics.h"

#ifndef INCLUDED_volk_fft_32ic_fft_32ic_a_H
#define INCLUDED_volk_fft_32ic_fft_32ic_a_H

#ifdef LV_HAVE_GENERIC

static inline void
volk_fft_32ic_fft_32ic_generic(lv_32sc_t* bVector, const lv_32sc_t* aVector, unsigned int num_points)
{
	generic_32ic_fft_32ic(bVector, aVector, num_points);
}
#endif /* LV_HAVE_GENERIC */

#endif /* INCLUDED_volk_fft_32ic_fft_32ic_u_H */
