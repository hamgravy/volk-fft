#ifndef VOLK_FFT_CONFIG_H
#define VOLK_FFT_CONFIG_H


//#include <arm_neon.h>


//#include <kissfft/kissfft_float/kiss_fft_float.h>
//#include <kissfft/kissfft_int32/kiss_fft_int32.h>
//#include <kissfft/kissfft_int16/kiss_fft_int16.h>
#include <stdio.h>
#include <stdbool.h>
#include <volk_fft/volk_fft.h>
#include <cstring>
#include "dsp/NE10_fft.h"
#include "NE10_dsp.h"



//#if defined(__arm__)
//#include <Ne10/NE10.h>

//#endif


typedef struct{
    int size;
    bool isinverse;
    char* arch;
	ne10_fft_cfg_float32_t cfg_float32;
	ne10_fft_cfg_int32_t cfg_int32;
//    kiss_fft_cfg_float generic_arch_cfg_float;
//    kiss_fft_cfg_int32 generic_arch_cfg_int32;
//    kiss_fft_cfg_int16 generic_arch_cfg_int16;

//#if defined(__arm__)
//    ne10_fft_cfg_float32_t neon_arch_cfg_float;
//    ne10_fft_cfg_int32_t neon_arch_cfg_int32;
//    ne10_fft_cfg_int16_t neon_arch_cfg_int16;
//#endif    

} fftarch;

typedef struct {
    bool is_float;
    int size;
} volk_fft_inputsig;

void fftalloc(fftarch* fft_conf, const char* arch, const volk_fft_inputsig* inputsig, const int vlen, const bool isinverse);



#endif //VOLK_FFT_CONFIG_H
