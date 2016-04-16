#include <stdio.h>

#ifdef SIMD

#include <emmintrin.h>

__m128d A,B,C,D;
#endif

double dot_data4( double * v1, double * v2)
{
#ifdef SIMD
 double result[2];
 A = _mm_loadu_pd( v1);
 B = _mm_loadu_pd( v2);
 C = _mm_mul_pd( A, B);
 A = _mm_loadu_pd( v1+2);
 B = _mm_loadu_pd( v2+2);
 _mm_prefetch( v1+4, _MM_HINT_NTA);
 _mm_prefetch( v2+4, _MM_HINT_NTA);
 D = _mm_mul_pd( A, B);
 C = _mm_add_pd( C, D);
 return C[0]+C[1];

#else
  double result = 0;
  result += v1[0] * v2[0];
  result += v1[1] * v2[1];
  result += v1[2] * v2[2];
  result += v1[3] * v2[3];

  return result;
#endif
}

int main(){

  double a;
#ifdef SIMD
  double * data = (double *) malloc ( 40000000 * sizeof(double));
#else
  double * data = (double *) malloc ( 40000000 * sizeof(double));
#endif
  int i;
  for( i = 0; i < 40000000; i+=4 )
  {
    data[i] = 1.3;
    data[i+1] = 2.3;
    data[i+2] = 3.3;
    data[i+3] = 4.3;
  }
  for( i = 0; i < 5000000; i++)
    a = dot_data4( data + i, data +i+4) + dot_data4(data + i, data +i+4);
  printf("ans = %lf\n", a);
  return 0;
}



