#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>

void print_matrix (double **matrix, int rows, int cols);
void print_matrix2 (int rows, int cols, double matrix[rows][cols]);
void generate_values (double ** matrix, int rows, int cols);
void free_matrix (double **matrix, int rows);
void matrix_addition (double ** mat_1, double ** mat_2, int rows, int cols, double result[rows][cols]);
void matrix_subtraction (double ** mat_1, double ** mat_2, int rows, int cols, double result[rows][cols]);
void matrix_multiplication (double ** mat_1, int rows, int cols, double ** mat_2, int cols_2, double result[rows][cols_2]);

#endif
