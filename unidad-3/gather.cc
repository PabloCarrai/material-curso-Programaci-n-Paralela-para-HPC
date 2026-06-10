#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
    int rank,size;
    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    int valor, *valores_recolectados;
    valor=rank*10;

    if (rank==0)
      valores_recolectados=(int*)malloc(size*sizeof(int));

    MPI_Gather(&valor,1,MPI_INT,valores_recolectados,1,MPI_INT,0,MPI_COMM_WORLD);
    if(rank==0)
      for (int i=0;i<size;i++)
        printf("valor[%d]=%d\n",i,valores_recolectados[i]);
    MPI_Finalize();

    return 0;
}