#include <stdio.h>
#include <mpi.h> 

int main(int argc, char **argv) {
    int nproc;     /* Número de procesos */
    int yo;        /* Mi identificación: 0 <= yo <= (nproc-1) */
    char name[MPI_MAX_PROCESSOR_NAME]; /* Uso de la constante oficial de MPI */
    int resultlen;

    MPI_Init(&argc, &argv);
    
    // CORREGIDO: MPI_Comm_size (ya estaba bien, pero se mantiene)
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    
    // CORREGIDO: 'Comm' va en minúsculas
    MPI_Comm_rank(MPI_COMM_WORLD, &yo);
    
    // CORREGIDO: 'processor' y 'name' van en minúsculas
    MPI_Get_processor_name(name, &resultlen);

    /* Cuerpo del programa */
    printf("Hola, soy el proceso %d de un total de %d y estoy corriendo en la máquina: %s\n", yo, nproc, name);

    MPI_Finalize();
    return 0; // Buena práctica en C
}