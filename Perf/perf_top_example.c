#include <stdio.h>
#include <unistd.h>


double compute_pi_baseline( size_t N);

int main()
{

    printf("pid : %d\n", getpid());
    /*	printf("\n\npi = %f\n",compute_pi_baseline(500000));*/
    compute_pi_baseline(5000000);
    return 0;
}

double compute_pi_baseline( size_t N)
{

    double pi = 0.0;
    double dt = 1.0 / N;
    size_t i;

    for( i = 0; i < N ; i++) {
        double x = (double) i / N;
        pi += dt / (1.0 + x * x);
    }

    return pi * 4.0;
}
