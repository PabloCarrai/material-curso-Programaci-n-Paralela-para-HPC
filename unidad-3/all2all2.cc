#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
    int size,rank;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    int A[size], B[size];
    for (int i=0;i<size;i++)
      A[i] =rank*10;

    MPI_Alltoall(A,1,MPI_INT,B,1,MPI_INT,MPI_COMM_WORLD);

    for (int i=0;i<size;i++)
     printf("pid %d B[%d]=%d\n",rank,i,B[i]);
    MPI_Finalize();
    return 0;
}