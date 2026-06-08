#include <stdio.h>
#include <omp.h>

int main(){
    #pragma omp parallel sections
    {
        #pragma omp section
        { printf("Tarea 1 ejecutada por thread %d\n",omp_get_thread_num()); }

        #pragma omp section
        { printf("Tarea 2 ejecutada por thread %d\n",omp_get_thread_num()); }
        
        #pragma omp section
        { printf("Tarea 3 ejecutada por thread %d\n",omp_get_thread_num()); }
    }
    return 0;
}