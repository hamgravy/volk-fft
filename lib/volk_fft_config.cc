
#include <volk_fft_config.h>

void fftalloc(fftarch* fft_conf, const char* arch, const volk_fft_inputsig* inputsig, const int vlen, const bool isinverse){
    fft_conf->size = vlen;
    fft_conf->isinverse = isinverse; 
    fft_conf->arch = (char *)arch;

    fft_conf->cfg_float32 = NULL;
    fft_conf->cfg_int32 = NULL;
    //fft_conf->generic_arch_cfg_int32 = NULL;
    //fft_conf->generic_arch_cfg_int16 = NULL;

    if (strcmp(arch,"generic") == 0){   
		fft_conf->cfg_float32 = ne10_fft_alloc_c2c_float32_c(vlen);

	

/*
        if (inputsig->is_float){ 
            //printf("allocating kissfft float\n");    
            fft_conf->generic_arch_cfg_float = kiss_fft_alloc_float(vlen, (char) isinverse, 0, 0);
            //printf("allocated kissfft float\n");
        }else{
            if (inputsig->size == 4){
                //printf("allocating kissfft int32\n");
                fft_conf->generic_arch_cfg_int32 = kiss_fft_alloc_int32(vlen, (char) isinverse, 0, 0);                
                //printf("allocated kissfft int32\n");
            }else if (inputsig->size == 2){
                //printf("allocating kissfft int16\n");
                fft_conf->generic_arch_cfg_int16 = kiss_fft_alloc_int16(vlen, (char) isinverse, 0, 0);
                //printf("allocated kissfft int16\n");
            }else{
                //throw "non-standard size input fft input signature size requested";
            }        
        }        
*/
    }else if (strcmp(arch,"neon") == 0) {
    }else{
        //throw "unsupported fft arch requested"; 
    }      

}
