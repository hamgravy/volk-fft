#ifndef INCLUDED_VOLK_PREFS_H
#define INCLUDED_VOLK_PREFS_H

#include <volk_fft/volk_fft_common.h>
#include <stdlib.h>

__VOLK_DECL_BEGIN

typedef struct volk_fft_arch_pref
{
    char name[128];   //name of the kernel
    char impl_a[128]; //best aligned impl
    char impl_u[128]; //best unaligned impl
} volk_fft_arch_pref_t;

////////////////////////////////////////////////////////////////////////
// get path to volk_fft_config profiling info;
// returns \0 in the argument on failure.
////////////////////////////////////////////////////////////////////////
VOLK_API void volk_fft_get_config_path(char *);

////////////////////////////////////////////////////////////////////////
// load prefs into global prefs struct
////////////////////////////////////////////////////////////////////////
VOLK_API size_t volk_fft_load_preferences(volk_fft_arch_pref_t **);

__VOLK_DECL_END

#endif //INCLUDED_VOLK_PREFS_H
