#include "qa_utils.h"

#include <volk_fft/volk_fft.h>

#include <boost/assign/list_of.hpp>
#include <vector>

// macros for initializing volk_fft_test_case_t. Maccros are needed to generate
// function names of the pattern kernel_name_*

// for puppets we need to get all the func_variants for the puppet and just
// keep track of the actual function name to write to results
#define VOLK_INIT_PUPP(func, puppet_master_func, test_params)\
    volk_fft_test_case_t(func##_get_func_desc(), (void(*)())func##_manual, std::string(#func),\
    std::string(#puppet_master_func), test_params)

#define VOLK_INIT_TEST(func, test_params)\
    volk_fft_test_case_t(func##_get_func_desc(), (void(*)())func##_manual, std::string(#func),\
    test_params)

std::vector<volk_fft_test_case_t> init_test_list(volk_fft_test_params_t test_params)
{

    // Some kernels need a lower tolerance
    volk_fft_test_params_t test_params_inacc = volk_fft_test_params_t(1e-3, test_params.scalar(),
            test_params.vlen(), test_params.iter(), test_params.benchmark_mode(), test_params.kernel_regex());


    volk_fft_test_params_t test_params_fft = volk_fft_test_params_t(1e-3, test_params.scalar(),
            16, 4, test_params.benchmark_mode(), test_params.kernel_regex());


    std::vector<volk_fft_test_case_t> test_cases = boost::assign::list_of
        (VOLK_INIT_TEST(volk_fft_32f_null_32f, test_params))
        (VOLK_INIT_TEST(volk_fft_32fc_fft_32fc, test_params_fft))
        (VOLK_INIT_TEST(volk_fft_32ic_fft_32ic, test_params_fft))
        (VOLK_INIT_TEST(volk_fft_16ic_fft_16ic, test_params_fft))
        ;

    return test_cases;
}
