#include <stdio.h>
#include <time.h>

long double get_nanosec() {
    struct timespec t;
    clock_gettime(CLOCK_REALTIME, &t);
    return (long double)(t.tv_sec + t.tv_nsec*0.000000001);
}
int main(void)
{
    int i;
    for (i = 0; i<100;i++) {
        printf("%Lf\n", get_nanosec());
    }
    return 0;
}
