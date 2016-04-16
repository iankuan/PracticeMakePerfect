#include <immintrin.h>
#include <stdint.h>

double compute_pi(size_t dt)
{
    double pi = 0.0;
    double delta = 1.0 / dt;
    register __m256d ymm0, ymm1, ymm2, ymm3, ymm4;                                                                          
    ymm0 = _mm256_set1_pd(1.0);
    ymm1 = _mm256_set1_pd(delta);
    ymm2 = _mm256_set_pd(delta * 3, delta * 2, delta * 1, 0.0);
    ymm4 = _mm256_setzero_pd();

    for (int i = 0; i <= dt - 4; i += 4) {
        ymm3 = _mm256_set1_pd(i * delta);
        ymm3 = _mm256_add_pd(ymm3, ymm2);
        ymm3 = _mm256_mul_pd(ymm3, ymm3);
        ymm3 = _mm256_add_pd(ymm0, ymm3);
        ymm3 = _mm256_div_pd(ymm1, ymm3);
        ymm4 = _mm256_add_pd(ymm4, ymm3);
    }
    double tmp[4] __attribute__((aligned(32)));
    _mm256_store_pd(tmp, ymm4);
    pi += tmp[0] + tmp[1] + tmp[2] + tmp[3];

    return pi * 4.0;
}
