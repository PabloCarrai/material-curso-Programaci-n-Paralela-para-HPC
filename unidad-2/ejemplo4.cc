#include <stdio.h>
#include <omp.h>


int main() {   
    #pragma omp parallel
    {
        int id=omp_get_thread_num();
        int total=omp_get_num_threads();
        int paralelo=omp_in_parallel();
            
        #pragma omp master
        {
            printf("Soy el hilo %d de %d  \n",id,total);
            if (paralelo==1)
               printf("En region paralela  \n");
        }
    }
    if (omp_in_parallel())
        printf("Todavia en paralelo  \n");
    else
        printf("Region paralela finalizada  \n");    
    return 0;
}