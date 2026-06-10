#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
    int rank,size;
    int valor, suma;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    valor=100+rank;
    suma=0;
    MPI_Reduce(&valor,&suma,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    if (rank==0)
      printf("Soy PID %d suma==%d\n",rank,suma);
    MPI_Finalize();
    return 0;
}