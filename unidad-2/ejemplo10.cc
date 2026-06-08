#include <cstdio>
#include <omp.h>

int main() {
    int x=10; // variable compartida por defecto
    
    #pragma omp parallel shared(x)
    {
        int tid=omp_get_thread_num();

        // Todos los threads modifican la misma variable compartida
        x+=tid;
        printf("Thread %d ve x= %d\n",tid,x);        
    }
    printf("valor final de x= %d\n",x);
    return 0;
}