#include <stdio.h>
#include <unistd.h>
#include <omp.h>

int main(){
    int N=20;
    int A[N],tid;

    for(int i=0;i<N;i++) A[i]=-1;

    #pragma omp parallel for schedule(dynamic,2) num_threads(2) private(tid)
        for (int i=0;i<N;i++){
            tid=omp_get_thread_num();
            A[i]=tid;
            sleep(1);
        }
        int i;
        for (i=0;i<N/2;i++) printf(" %2d",i); printf("\n");
        for (i=0;i<N/2;i++) printf("%2d",A[i]); printf("\n\n\n");
        for (i=N/2;i<N;i++) printf("%2d",i); printf("\n");
        for (i=N/2;i<N;i++) printf("%2d",A[i]); printf("\n\n");
        return 0;
}