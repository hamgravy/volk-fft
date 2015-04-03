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
#ifndef INCLUDED_volk_fft_generics_H
#define INCLUDED_volk_fft_generics_H


#include <stdio.h>
//#include <math.h>
//#include <inttypes.h>
#include "volk_fft/kissfft.hh"
#include <volk_fft/volk_fft_typedefs.h>
#include "dsp/NE10_fft.h"
#include "NE10_dsp.h"


void generic_32ic_fft_32ic(lv_32sc_t* bVector, const lv_32sc_t* aVector, unsigned int num_points);
void generic_32fc_fft_32fc(lv_32fc_t* bVector, const lv_32fc_t* aVector, unsigned int num_points);

#endif /* INCLUDED_volk_fft_generics_H */
