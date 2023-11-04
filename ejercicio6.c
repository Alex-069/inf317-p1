#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mpi.h>

char** divide_frase(char* frase) {
    int num_palabras = 0;
    char** grupos = NULL;
    char* palabra = strtok(frase, " ");
    
    while (palabra != NULL) {
        grupos = realloc(grupos, (num_palabras + 1) * sizeof(char*));
        grupos[num_palabras] = palabra;
        num_palabras++;
        palabra = strtok(NULL, " ");
    }
    
    int mitad = num_palabras / 2;
    grupos[mitad] = NULL;
    
    return grupos;
}

int main(int argc, char** argv) {
    int numero_procesadores, procesador_activo;
    char* frase = "tres tristes tigres trigaban trigo por culpa del bolivar";
    
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numero_procesadores);
    MPI_Comm_rank(MPI_COMM_WORLD, &procesador_activo);
    
    if (procesador_activo == 0) {
        char** grupos = divide_frase(frase);
        int num_palabras = 0;
        
        while (grupos[num_palabras] != NULL) {
            num_palabras++;
        }
        
        int mitad = num_palabras / 2;
        
        for (int i = 0; i < mitad; i++) {
            printf("Grupo 1: %s\n", grupos[i]);
        }
        
        for (int i = mitad; i < num_palabras; i++) {
            printf("Grupo 2: %s\n", grupos[i]);
        }
        
        free(grupos);
    }
    
    MPI_Finalize();
    
    return 0;
}
