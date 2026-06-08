#include <stdio.h>
#include <omp.h>

int main(){
    int shared_var=100;
    int private_var=200;

    #pragma omp parallel shared(shared_var) private(private_var)
    {
        int id=omp_get_thread_num();
        private_var=id*10;
        #pragma omp critical
        {
            shared_var+=id;
            printf("thr %d: shared_var=%d, private_var=%d\n",id,shared_var,private_var);
        }
    }
    printf("Valor final fuera de la region: shared_var = %d, private_var = %d\n",shared_var,private_var);
    return 0;
}