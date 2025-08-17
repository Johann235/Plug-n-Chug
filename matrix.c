#include <math.h>
#include <stdlib.h>
#include "matrix.h"

void print_matrix (double **matrix, int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_matrix2 (int rows, int cols, double matrix[rows][cols]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}


void generate_values (double ** matrix, int rows, int cols){
    int min = 0;
    int max = 10;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            matrix[i][j] = min + rand() % max;
        }
    }
}

void free_matrix (double **matrix, int rows){
    for (int i = 0; i < rows; i ++){
        free(matrix[i]);
    }
    free(matrix);
}

void matrix_addition (double ** mat_1, double ** mat_2, int rows, int cols, double result[rows][cols]){
    for (int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j ++){
            result[i][j] = mat_1[i][j] + mat_2[i][j];
        }
    }
}

void matrix_subtraction (double ** mat_1, double ** mat_2, int rows, int cols, double result[rows][cols]){
    for (int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j ++){
            result[i][j] = mat_1[i][j] - mat_2[i][j];
        }
    }
}

void matrix_multiplication (double ** mat_1, int rows, int cols, double ** mat_2, int cols_2, double result[rows][cols_2]){
    for (int c = 0; c < cols_2; c++){
        for (int i = 0; i < rows; i++){
            int dot_product = 0;
            for(int j = 0; j < cols; j++){
                dot_product += mat_1[i][j] * mat_2[j][c];
            }
            result[i][c] = dot_product;
        }
    }

}

