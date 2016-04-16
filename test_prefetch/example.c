#include <stdio.h>
#include <emmintrin.h>

int main(){

  __m128 lvfA = _mm_set_ps( 1.0f, 2.0f, 3.0f, 4.0f );
  __m128 lvfB = _mm_set_ps( 5.0f, 6.0f, 7.0f, 8.0f );

  __m128 lvfResult = _mm_shuffle_ps( lvfA, lvfB, _MM_SHUFFLE( 0, 1, 0, 1 ) );

  printf( "%f, %f, %f, %f\n", lvfResult[0], lvfResult[1],
  lvfResult[2], lvfResult[3] );
}
