#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int numero_procesadores, procesador_activo;
    int n = 1000000;
    int a = 2;
    int b = 2;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &numero_procesadores);
    MPI_Comm_rank(MPI_COMM_WORLD, &procesador_activo);

    int* series = (int*)malloc(n * sizeof(int));
    int index = 0;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1 && i > 1) {
            series[index] = a;
            a = a + i;
        }
        else if (i > 2) {
            series[index] = b;
            b = i;
        }
        index++;
    }

    for (int i = n - 1; i >= 0; i--) {
        printf("%d,", series[i]);
    }

    free(series);

    MPI_Finalize();

    return 0;
}
