#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *length);
void output(int *a, int length);
void sorting(int *a, int length);

int main() {
    int n = 0;
    int *a = NULL;
    if (input(&a, &n) == 1) {
        sorting(a, n);
        output(a, n);
    } else {
        printf("%s", "n/a");
    }
    free(a);
    return 0;
}

int input(int **buffer, int *length) {
    int error = 1;
    if (scanf("%d", length) != 1 || *length <= 0) {
        error = 0;
    }
    if (error == 1) {
        *buffer = (int *)malloc(*length * sizeof(int));
        if (*buffer == NULL) {
            error = 0;
        }
    }
    if (error == 1) {
        for (int *p = *buffer; (error) && (p - *buffer < *length); p++) {
            if ((scanf("%d", p)) != 1) {
                error = 0;
            }
        }
    }
    return error;
}

void sorting(int *a, int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(a + j) > *(a + j + 1)) {
                temp = *(a + j + 1);
                *(a + j + 1) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p - a < n - 1) {
            printf("%d ", *p);
        } else {
            printf("%d", *p);
        }
    }
}
