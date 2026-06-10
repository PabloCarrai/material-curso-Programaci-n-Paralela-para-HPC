#include <stdio.h>
#include <mpi.h>  //sudo apt update && sudo apt install -y build-essential openmpi-bin openmpi-common libopenmpi-dev

int main(int argc,char **argv)
{
    MPI_Init(&argc,&argv);
    printf("Hola Mundo \n");
    MPI_Finalize();
}