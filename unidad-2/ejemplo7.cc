#include <cstdio>
#include <omp.h>

int main() {
    int x=0;
    #pragma omp parallel for
    for (int i=0;i<1000;i++){
        #pragma onp critical
        x++;
    }
    printf("Resultado correcto: %d\n",x);
    return 0;
}
