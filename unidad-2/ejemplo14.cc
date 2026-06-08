#include <stdio.h>
#include <omp.h>

int main(){
    int n=1000000;
    double suma=0.0;

    #pragma omp parallel for reduction(+:suma)
    for (int i=0;i<n;i++){
        suma+=1.0;
    }
    printf("Resultado=%.0f\n",suma);
    return 0;
}