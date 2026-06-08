#include <stdio.h>
#include <omp.h>

int main(){
    int n=10;
    int A[n];

    #pragma omp parallel
    {
        #pragma omp for
        for (int i=0;i<n;i++){
            A[i]=i*2;
            printf("Thread %d calculo A[%d]=%d\n",omp_get_thread_num(),i,A[i]);
        }
    }
    return 0;
}