#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
	int pid, nprocs,q;
 
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
	MPI_Comm_rank(MPI_COMM_WORLD,&pid);
 
	MPI_Status status;
	MPI_Request reqs;
 
	int dest;
	if (pid==nprocs-1) dest = 0;
	else dest = pid+1;
 
            MPI_Isend(&pid,1,MPI_INT,dest,1,MPI_COMM_WORLD,&reqs);
        	MPI_Barrier(MPI_COMM_WORLD);
            MPI_Irecv(&q,1,MPI_INT,MPI_ANY_SOURCE,1,MPI_COMM_WORLD,&reqs);
 
	printf("pid %d recibe q=%d\n",pid,q);
            MPI_Barrier(MPI_COMM_WORLD);
	if (pid==0) printf("-----------------\n");
	if (pid==0)
	    q=100;
	MPI_Bcast(&q,1,MPI_INT,0,MPI_COMM_WORLD);
	printf("pid %d q=%d\n",pid,q);
            MPI_Barrier(MPI_COMM_WORLD);
            if (pid==0) printf("-----------------\n");
	int N[20];
	if (pid==0)
	     for(int i=0;i<20;i++) N[i]=i+1;
 
           int cant_recv = 20/nprocs;
           printf("cant rec %d\n",cant_recv);
           int data_recibida[cant_recv];
           MPI_Scatter(N,cant_recv,MPI_INT,data_recibida,cant_recv,
                                 MPI_INT,0,MPI_COMM_WORLD);
 
           for(int i=0;i<cant_recv;i++)
 	   printf("pid %d data_recibida[%d]=%d\n",pid,i,data_recibida[i]);
          MPI_Finalize();
          return 0;
}
