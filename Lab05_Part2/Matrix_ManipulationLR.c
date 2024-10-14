/*
10/13/2024
Luke Reicherter
KU ID: 3135060
EECS 348: Lab 05
Lab Session: Thursday 11:00 AM
Description: This will take two matrices and display their sum, product, and each matrix transposed
*/
#include <stdio.h>

#define SIZE 5
void transposeMatrix(int rows, int columns, int matrix[rows][columns], int transposed[rows][columns]) {
    //This function transposes the matric by reversing i and j indices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transposed[i][j] = matrix[j][i];
        }
    }
}
void multiplyMatrices(int rows, int columns, int A[rows][columns], int B[rows][columns], int AtimesB[rows][columns]) {
    //This function multiplies both matrices and stores the product matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            for (int k = 0; k < columns; k++)
            AtimesB[i][j] += A[i][k] * B[k][j];
        }
    }
}
void addMatrices(int rows, int columns, int A[rows][columns], int B[rows][columns], int AplusB[rows][columns]) {
    //This function adds the matrices by iterating through the indices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            AplusB[i][j] = A[i][j] + B[i][j];
        }
    }
}
void printMatrix(int rows, int columns, int matrix[rows][columns]) {
    //This function prints a matrix by iterating through each index
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    //This code creates both matrices and calls all functions. This also prints all the output.
    int A [SIZE][SIZE] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };
    int B [SIZE][SIZE] = {
        {25,24,23,22,21},
        {20,19,18,17,16},
        {15,14,13,12,11},
        {10,9,8,7,6},
        {5,4,3,2,1}
    };
    int AplusB[SIZE][SIZE], AtimesB[SIZE][SIZE], AT[SIZE][SIZE], BT[SIZE][SIZE];
    //The code below will call various functions to then store the data in a empty arrray. The result is then printed
    addMatrices(SIZE, SIZE, A, B, AplusB);
    printf("A + B:\n\n");
    printMatrix(SIZE, SIZE, AplusB);
    printf("A * B:\n\n");
    multiplyMatrices(SIZE, SIZE, A, B, AtimesB);
    printMatrix(SIZE, SIZE, AtimesB);
    printf("A^T:\n\n");
    transposeMatrix(SIZE, SIZE, A, AT);
    printMatrix(SIZE, SIZE, AT);
    printf("B^T:\n\n");
    transposeMatrix(SIZE, SIZE, B, BT);
    printMatrix(SIZE, SIZE, BT);
    return 0;
}