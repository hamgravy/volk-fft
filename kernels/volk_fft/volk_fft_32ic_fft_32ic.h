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
#include "dsp/NE10_fft.h"
#include "NE10_dsp.h"

#ifndef INCLUDED_volk_fft_32ic_fft_32ic_a_H
#define INCLUDED_volk_fft_32ic_fft_32ic_a_H

#ifdef LV_HAVE_GENERIC

static inline void
volk_fft_32ic_fft_32ic_generic(lv_32sc_t* bVector, const lv_32sc_t* aVector, unsigned int num_points)
{
	ne10_fft_cfg_int32_t cfg_int32;
	cfg_int32 = ne10_fft_alloc_c2c_int32_c(num_points);

    ne10_int32_t* in_generic = (ne10_int32_t*) aVector;
    ne10_int32_t* out_generic = (ne10_int32_t*) bVector; 
    const ne10_int32_t isscaled = 1;
	const ne10_int32_t isinverse = 0;

    ne10_fft_c2c_1d_int32_c( (ne10_fft_cpx_int32_t*) out_generic, \
                                (ne10_fft_cpx_int32_t*) in_generic, \
                                cfg_int32, \
                                isinverse, \
                                isscaled);

    int ii;
    printf("x=[");
    for (ii=0; ii < num_points; ii++){
	    printf("%d+%di;",(int32_t)in_generic[ii*2],(int32_t)in_generic[(ii*2)+1]);
    }
    printf("];\n");
    printf("y=[");
    for (ii=0; ii < num_points; ii++){
	    printf("%d+%di;",(int32_t)out_generic[ii*2],(int32_t)out_generic[(ii*2)+1]);
    }
    printf("];\n\n");
}
#endif /* LV_HAVE_GENERIC */

#endif /* INCLUDED_volk_fft_32ic_fft_32ic_u_H */
