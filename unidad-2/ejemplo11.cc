#include <cstdio>
#include <omp.h>

int main() {
    int x=10;
    
    #pragma omp parallel private(x)
    {
        int id=omp_get_thread_num();

        x+=id; // Cada thread tiene su propia version de x
        printf("Thread %d: x= %d\n",id,x);        
    }
    printf("valor final de x(fuera)= %d\n",x);
    return 0;
}