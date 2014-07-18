#include <stdio.h>
#include <time.h>

int main(void)
{
    struct timespec t;
    clock_gettime(CLOCK_REALTIME, &t);
    printf("%.9Lf\n", (long double)(t.tv_sec + t.tv_nsec*0.000000001));
    return 0;
}
