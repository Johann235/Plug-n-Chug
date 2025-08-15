#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Expected: #rows, #cols\n");
        exit(1);
    }
    
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    double ** matty = malloc(sizeof(double *) * rows);
    if(matty == NULL){
        printf("Malloc failed\n");
        exit(1);
    }
    for (int i = 0; i < rows; i ++){
        matty[i] = malloc(sizeof(double)*cols);
        if(matty[i] == NULL){
            printf("Malloc failed\n");
            exit(1);
        }
    }
    print_matrix(matty, rows,cols);

    return 0;
}