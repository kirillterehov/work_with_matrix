#include <stdio.h>
#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);
void output(int **picture, int n, int m);

int main() {
    int picture_data[N][M] = {0};
    int *picture[N] = {0};
    transform(*picture_data, picture, N, M);

    make_picture(picture, N, M);
    output(picture, N, M);
    return 0;
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);

    int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
    int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);

    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
        picture[length_frame_h - 1][i] = frame_w[i];
        picture[length_frame_h / 2][i] = frame_w[i];
    }
    for (int i = 0; i < length_frame_h; i++) {
        picture[i][0] = frame_h[i];
        picture[i][M / 2] = frame_h[i];
        picture[i][M - 1] = frame_h[i];
    }

    for (int i = M / 2; i <= 9; i++) {
        for (int j = 3; j <= 4; j++) {
            if (i == n / 2) {
                picture[i][j] = 1;
                picture[i + 1][j] = tree_trunk[i - 6];
            } else if (i == n / 2 + 1 && j == 4) {
                picture[i][j] = tree_trunk[i - 6];
            } else if (i != n / 2 + 1) {
                picture[i][j] = tree_trunk[i - 6];
            }
        }
    }
    for (int j = 2; j <= 5; j++) {
        picture[10][j] = tree_trunk[j - 2];
    }
    for (int i = 2; i <= 5; i++) {
        for (int j = 2; j <= 5; j++) {
            if (!(i == 5 && (j == 2 || j == 5))) {
                picture[i][j] = tree_foliage[i - 2];
            }
        }
    }

    for (int i = 1; i <= 6; i++) {
        for (int j = 7; j <= 11; j++) {
            picture[i][j] = sun_data[i - 1][j - 7];
        }
    }
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}

void output(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", picture[i][j]);
            if (j < m - 1) {
                printf(" ");
            }
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
}