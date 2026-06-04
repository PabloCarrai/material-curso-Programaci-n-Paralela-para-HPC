#include <stdio.h>
#include <omp.h>


int main()
{
    #pragma omp parallel
    {
        int tid=omp_get_thread_num();
        printf("Hola Mundo soy thread=%d\n",tid);
    }
    return 0;
}