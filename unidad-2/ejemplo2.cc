#include <stdio.h>
#include <omp.h>


int main()
{
    omp_set_num_threads(3);
    #pragma omp parallel
    {
        printf("Soy el thread %d de  %d \n",omp_get_thread_num(),omp_get_num_threads());
    }
    return 0;
}