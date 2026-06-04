#include <cstdio>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        printf("Antes de la barrera - thread %d\n", tid);
        #pragma omp barrier
        printf("Después de la barrera - thread %d\n", tid);
    }
    return 0;
}
