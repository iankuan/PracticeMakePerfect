#include <stdio.h>
#include <emmintrin.h>

int main()
{
  double * d = ( double *) malloc( 2*sizeof(double));
  __m128d a = _mm_set_pd( 1, 2);
  __m128d b = _mm_set_pd( 3, 4);
  /*__m128d c = _mm_mul_pd( a, b);*/
  __m128d c = _mm_add_pd( a, b);
  _mm_store_pd( d, c);
  
  printf("%lf, %lf\n", d[0], d[1]);

  return 0;
}
