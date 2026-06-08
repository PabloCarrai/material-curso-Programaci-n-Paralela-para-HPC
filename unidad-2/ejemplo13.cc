#include <stdio.h>
#include <omp.h>

int main(){
    int n=5;
    int A[n];

    #pragma omp parallel for private(n)
    for (int i=0;i<5;i++){
        n=i; //variable privada
        A[i]=n*2;
        printf("Thread %d: a[%d]=%d(n local=%d)\n", omp_get_thread_num(),i,A[i],n);
    }
    printf("\n Despues del bucle, n(fuera) no cambio: n= %d\n",n);
    return 0;
}