#include <stdio.h>
#include <mpi.h> 
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv){
    int size,rank;
    int max_len=300;
    char texto[max_len];
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("Soy PID =%d\n",rank);

    if (rank==0)
    {
        strcpy(texto,"Hola desde MPI");
    }
    MPI_Bcast(texto,max_len,MPI_CHAR,0,MPI_COMM_WORLD);

    if(rank!=0)
       printf("pid %d texto=%s\n",rank,texto);
    
    MPI_Finalize();
    return 0;
}