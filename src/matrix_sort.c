#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int** create_dynamic_matrix_one(int n, int m);
int** create_dynamic_matrix_two(int n, int m);
int** create_dynamic_matrix_three(int n, int m);
int input_matrix(int** matrix, int n, int m);
void print_matrix(int** matrix, int n, int m);
void free_dynamic_matrix_one(int** matrix, int n);
void free_dynamic_matrix_two(int** matrix);
void sort(int** matrix, int n, int m);
int strSum(int** matrix, int j);

int main() {
    int n, m, mode;
    int** matrix = NULL;

    if (scanf("%d", &mode) != 1 || (mode < 1 || mode > 3)) {
        printf("n/a");
    } else {
        if (scanf("%d %d", &n, &m) != 2 || (n > MAX_SIZE) || (m > MAX_SIZE) || n <= 0 || n <= 0) {
            printf("n/a");
        } else {
            if (mode == 1) {
                matrix = create_dynamic_matrix_one(n, m);
            } else if (mode == 2) {
                matrix = create_dynamic_matrix_two(n, m);

            } else if (mode == 3) {
                matrix = create_dynamic_matrix_three(n, m);
            }
        }

        if (matrix == NULL) {
            printf("n/a");
        } else {
            if (input_matrix(matrix, n, m) != 1) {
                printf("n/a");
            } else {
                sort(matrix, n, m);
                print_matrix(matrix, n, m);
            }

            switch (mode) {
                case 1:
                    free_dynamic_matrix_one(matrix, n);
                    break;
                case 2:
                    free_dynamic_matrix_two(matrix);
                    break;
                case 3:
                    free(matrix);
                    break;
            }
        }

        return 0;
    }
}

int** create_dynamic_matrix_one(int n, int m) {
    int** pointer_array = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        pointer_array[i] = malloc(sizeof(int) * m);
    }
    return pointer_array;
}

void free_dynamic_matrix_one(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int** create_dynamic_matrix_two(int n, int m) {
    int** pointer_array = malloc(n * sizeof(int*));
    int* value_array = malloc(n * m * sizeof(int));
    for (int i = 0; i < n; i++) {
        pointer_array[i] = value_array + i * m;
    }
    return pointer_array;
}

void free_dynamic_matrix_two(int** matrix) {
    if (matrix != NULL) {
        free(matrix[0]);
        free(matrix);
    }
}

int** create_dynamic_matrix_three(int n, int m) {
    int** three = malloc(n * m * sizeof(int) + n * sizeof(int*));
    int* ptr = (int*)(three + n);
    for (int i = 0; i < n; i++) {
        three[i] = ptr + m * i;
    }
    return three;
}

void print_matrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            printf("%d", matrix[i][j]);
            if (j < m - 1) {
                printf(" ");
            }
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
}

int input_matrix(int** matrix, int n, int m) {
    int check = 1;
    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d%c", &matrix[i][j], &c) != 2 || (c != ' ' && i <= n - 1 && j < m - 1)) {
                check = 0;
            }
        }
    }
    if (check) {
        if (c != '\n') {
            check = 0;
        }
    }
    return check;
}

void sort(int** matrix, int n, int m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strSum(matrix, j) > strSum(matrix, j + 1)) {
                for (int c = 0; c < m; c++) {
                    int temp = matrix[j][c];
                    matrix[j][c] = matrix[j + 1][c];
                    matrix[j + 1][c] = temp;
                }
            }
        }
    }
}

int strSum(int** matrix, int i) {
    int sum = 0;
    for (int j = 0; j < i; j++) {
        sum += matrix[i][j];
    }
    return sum;
}