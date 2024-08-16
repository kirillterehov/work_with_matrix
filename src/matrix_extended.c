#include <stdio.h>
#include <stdlib.h>
#define length 100
#define width 100

int input(int *, int *, int *);
void first_dynamic(int, int);
void second_dynamic(int, int);
void third_dynamic(int, int);
void static_array(int N, int M, int data[length][width]);
void input_array_static(int N, int M, int data[length][width], int *error);
void input_array_dynamic(int N, int M, int *, int *);
void max_min_in_static(int N, int M, int data[length][width]);
void max_min_in_dynamic(int N, int M, int *);

int main() {
    int N, M, mode, data[length][width];
    if (input(&N, &M, &mode) == 1) {
        return 1;
    }
    if (mode == 1) {
        first_dynamic(N, M);
    } else if (mode == 2) {
        second_dynamic(N, M);
    } else if (mode == 3) {
        third_dynamic(N, M);
    } else if (mode == 4) {
        static_array(N, M, data);
    }

    return 0;
}

void first_dynamic(int N, int M) {
    int **ptr = malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) {
        ptr[i] = malloc(N * sizeof(int));
    }
    int error = 0;
    input_array_dynamic(N, M, *ptr, &error);
    if (error == 1) {
        printf("n/a");
        return;
    }
    for (int i = 0; i < M; i++) {
        if (i != 0) {
            printf("\n");
        }
        for (int j = 0; j < N; j++) {
            if (i != (M - 1) || j != (N - 1)) {
                printf("%d ", ptr[i][j]);
            } else {
                printf("%d", ptr[i][j]);
            }
        }
    }
    max_min_in_dynamic(N, M, *ptr);
    for (int i = 0; i < M; i++) {
        free(ptr[i]);
    }
    free(ptr);
}

void second_dynamic(int N, int M) {
    int **ptr = malloc(M * sizeof(int *));
    int *values_array = malloc(M * N * sizeof(int));
    for (int i = 0; i < M; i++) {
        ptr[i] = values_array + N * i;
    }
    int error = 0;
    input_array_dynamic(N, M, *ptr, &error);
    if (error == 1) {
        printf("n/a");
        return;
    }
    for (int i = 0; i < M; i++) {
        if (i != 0) {
            printf("\n");
        }
        for (int j = 0; j < N; j++) {
            if (i != (M - 1) || j != (N - 1)) {
                printf("%d ", ptr[i][j]);
            } else {
                printf("%d", ptr[i][j]);
            }
        }
    }
    max_min_in_dynamic(N, M, *ptr);
    free(values_array);
    free(ptr);
}

void third_dynamic(int N, int M) {
    int **single_array_matrix = malloc(M * N * sizeof(int) + M * sizeof(int *));
    int *ptr = (int *)(single_array_matrix + M);
    for (int i = 0; i < M; i++) {
        single_array_matrix[i] = ptr + N * i;
    }
    int error = 0;
    input_array_dynamic(N, M, *single_array_matrix, &error);
    if (error == 1) {
        printf("n/a");
        return;
    }
    for (int i = 0; i < M; i++) {
        if (i != 0) {
            printf("\n");
        }
        for (int j = 0; j < N; j++) {
            if (i != (M - 1) || j != (N - 1)) {
                printf("%d ", single_array_matrix[i][j]);
            } else {
                printf("%d", single_array_matrix[i][j]);
            }
        }
    }
    max_min_in_dynamic(N, M, *single_array_matrix);
    free(single_array_matrix);
}

void static_array(int N, int M, int data[length][width]) {
    int error = 0;
    input_array_static(N, M, data, &error);
    if (error == 1) {
        printf("n/a");
        return;
    }
    for (int i = 0; i < M; i++) {
        if (i != 0) {
            printf("\n");
        }
        for (int j = 0; j < N; j++) {
            if (i != (M - 1) || j != (N - 1)) {
                printf("%d ", data[i][j]);
            } else {
                printf("%d", data[i][j]);
            }
        }
    }
    max_min_in_static(N, M, data);
}

void input_array_static(int N, int M, int data[length][width], int *error) {
    *error = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &data[i][j]) != 1) {
                *error = 1;
            }
        }
    }
}

void input_array_dynamic(int N, int M, int *data, int *error) {
    *error = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", data + i * N + j) != 1) {
                *error = 1;
            }
        }
    }
}

int input(int *N, int *M, int *mode) {
    int error = 0;
    if (scanf("%d", mode) != 1 || *mode < 1 || *mode > 4) {
        printf("n/a");
        error = 1;
    }
    if (error == 0) {
        if (scanf("%d %d", N, M) != 2 || *N > 100 || *N < 1 || *M > 100 || *M < 1) {
            printf("n/a");
            error = 1;
        }
    }
    return error;
}

void max_min_in_static(int N, int M, int data[length][width]) {
    printf("\n");

    int max_in_row[M];

    int min_in_coll[N];

    for (int i = 0; i < M; i++) {
        max_in_row[i] = data[i][0];

        for (int j = 0; j < N; j++) {
            if (data[i][j] > max_in_row[i]) {
                max_in_row[i] = data[i][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        min_in_coll[i] = data[0][i];

        for (int j = 0; j < M; j++) {
            if (data[j][i] < min_in_coll[i]) {
                min_in_coll[i] = data[j][i];
            }
        }
    }

    for (int i = 0; i < M; i++) {
        printf("%d ", max_in_row[i]);
    }

    printf("\n");

    for (int i = 0; i < N; i++) {
        if (i != (N - 1)) {
            printf("%d ", min_in_coll[i]);

        } else {
            printf("%d", min_in_coll[i]);
        }
    }
}

void max_min_in_dynamic(int N, int M, int *data) {
    printf("\n");

    int max_in_row[M];

    int min_in_coll[N];

    for (int i = 0; i < M; i++) {
        max_in_row[i] = data[i * N];

        for (int j = 0; j < N; j++) {
            if (data[i * N + j] > max_in_row[i]) {
                max_in_row[i] = data[i * N + j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        min_in_coll[i] = data[i];

        for (int j = 0; j < M; j++) {
            if (data[j * N + i] < min_in_coll[i]) {
                min_in_coll[i] = data[j * N + i];
            }
        }
    }

    for (int i = 0; i < M; i++) {
        printf("%d ", max_in_row[i]);
    }

    printf("\n");

    for (int i = 0; i < N; i++) {
        if (i != (N - 1)) {
            printf("%d ", min_in_coll[i]);

        } else {
            printf("%d", min_in_coll[i]);
        }
    }
}
