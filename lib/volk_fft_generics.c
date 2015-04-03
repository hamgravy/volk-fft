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
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
#include "volk_fft/volk_fft_generics.h"

void generic_32ic_fft_32ic(lv_32sc_t* bVector, const lv_32sc_t* aVector, unsigned int num_points){
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
    
	return;

}

void generic_32fc_fft_32fc(lv_32fc_t* bVector, const lv_32fc_t* aVector, unsigned int num_points){
    typedef kissfft<float> FFT_float;
    typedef std::complex<float> cpx_type_float;

	cpx_type_float* inbuf = (cpx_type_float*) aVector;
	cpx_type_float* outbuf = (cpx_type_float*) bVector;
	
	FFT_float fft(num_points,false);
	fft.transform(inbuf,outbuf);

    printf("x=[");
    for (int k1=0;k1<num_points;++k1) {
		printf("%f+%fi;",inbuf[k1].real(),inbuf[k1].imag());
	}
    printf("];\n");

	printf("y=[");
    for (int k1=0;k1<num_points;++k1) {
		printf("%f+%fi;",outbuf[k1].real(),outbuf[k1].imag());
	}
    printf("];\n\n");
	return;
}

