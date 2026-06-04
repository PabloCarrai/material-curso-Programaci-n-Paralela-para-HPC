#include <cstdio>
#include <omp.h>

int main() {
    int x=0;
    omp_lock_t lock;
    omp_init_lock(&lock);

    #pragma omp parallel for
    for (int i=0;i<1000;i++){
        omp_set_lock(&lock);
        x++;
        omp_unset_lock(&lock);
    }

    omp_destroy_lock(&lock);
    printf("Resultado= %d\n",x);
    return 0;
}
