#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_STATIC_SIZE 100
void print_matrix(int** matrix, int m, int n);
void read_matrix(int** matrix, int m, int n);
int** create_dynamic_matrix(int m, int n);
void delete_matrix(int** matrix, int m, int n);

void sum();
void multiply();
void transpose();

int main() {
    int mode;

    scanf("%d", &mode);
    switch (mode) {
        case 1:
            sum();
            break;
        case 2:
            multiply();
            break;
        case 3:
            transpose();
            break;
        default:
            printf("n/a");
    }
}
void sum() {
    int m1, n1, m2, n2;
    scanf("%d %d", &m1, &n1);
    int** matrix1 = create_dynamic_matrix(m1, n1);
    read_matrix(matrix1, m1, n1);
    scanf("%d %d", &m2, &n2);
    int** matrix2 = create_dynamic_matrix(m2, n2);
    read_matrix(matrix2, m2, n2);
    if (m1 != m2 || n1 != n2) {
        printf("n/a");
    } else {
        int** res = create_dynamic_matrix(m1, n1);
        for (int i = 0; i < m1; i++) {
            for (int j = 0; j < n1; j++) {
                res[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        print_matrix(res, m1, n1);
        free(res);
    }
    free(matrix1);
    free(matrix2);
}
void transpose() {
    int m1, n1;
    scanf("%d %d", &m1, &n1);
    int** matrix1 = create_dynamic_matrix(m1, n1);
    read_matrix(matrix1, m1, n1);
    int** res = create_dynamic_matrix(n1, m1);
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            res[i][j] = matrix1[j][i];
        }
    }
    print_matrix(res, n1, m1);
    free(res);
    free(matrix1);
}
void multiply() {
    int m1, n1, m2, n2;
    scanf("%d %d", &m1, &n1);
    int** matrix1 = create_dynamic_matrix(m1, n1);
    read_matrix(matrix1, m1, n1);
    scanf("%d %d", &m2, &n2);
    int** matrix2 = create_dynamic_matrix(m2, n2);
    read_matrix(matrix2, m2, n2);
    int m = m1;
    int q = n2;
    int n = m2;
    if (n1 != m2) {
        printf("n/a");
    } else {
        int** res = create_dynamic_matrix(m, q);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < q; j++) {
                res[i][j] = 0;
                for (int k = 0; k < n; k++) res[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
        print_matrix(res, m, q);
        free(res);
    }
    free(matrix1);
    free(matrix2);
}
void print_matrix(int** matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        if (i != m - 1) {
            printf("\b\n");
        }
    }
    printf("\b");
}
void read_matrix(int** matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int** create_dynamic_matrix(int m, int n) {
    int** matrix = NULL;
    matrix = (int**)malloc(m * n * sizeof(int) + m * sizeof(int*));
    int* ptr = (int*)(matrix + m);
    for (int i = 0; i < m; i++) {
        matrix[i] = ptr + n * i;
    }
    return matrix;
}