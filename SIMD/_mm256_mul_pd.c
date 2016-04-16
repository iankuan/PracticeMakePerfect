#include <stdio.h>
#include <immintrin.h>
/*Maybe i don't have 256bit method*/
int main()
{
  double _4dResult[4] = { 0.0, 0.0, 0.0, 0.0};
  __m256 m256_4d_A =  _mm256_set_pd(1.0, 2.0, 3.0, 4.0);
  __m256 m256_4d_B = _mm256_set_pd( 2.0, 3.0, 4.0, 5.0);
  __m256 m256_Rt = _mm256_mul_pd ( m256_4d_A , m256_4d_B);
  _mm256_store_pd( 4dResult, m256_Rt);

  printf("%lf, %lf, %lf, %lf\n", _4dResult[0], _4dResult[1], _4dResult[2], _4dResult[3]);

 }

