#include <stdio.h>
#include <xmmintrin.h>

#define M_CHECK_ALIGNMENT(lObject, luAlignment) \
{ \
    assert( (luAlignment) ); \
    assert( ( (luAlignment) & ( (luAlignment) - 1 ) ) == 0 ); \
    assert( (reinterpret_cast<intptr_t>( &(lObject) ) & ( (luAlignment) - 1 )) == 0 ); \
}

int main()
{
  static float lafResult[] = { 0.0f, 0.0f, 0.0f, 0.0f};
  __m128 lvfA = _mm_set_ps( 1.0f, 2.0f, 3.0f, 4.0f );
  __m128 lvfB = _mm_set_ps( 2.0f, 3.0f, 4.0f, 5.0f );
  __m128 lvfA_mult_B = _mm_mul_ps( lvfA, lvfB );

  _mm_store_ps( lafResult, lvfA_mult_B );

  printf( "%f, %f, %f, %f\n", lafResult[0], lafResult[1], lafResult[2], lafResult[3]);
}
