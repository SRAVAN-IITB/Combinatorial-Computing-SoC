#include <stdio.h>
#include <stdbool.h>
void Update_and_Check(int x[], int *wt_ptr, int n, int m, int p);
int main()
{
    int n, m, p, x[n], weight[n][m];
    printf("Enter the number of vertices 'n':\n");
    scanf("%d", &n);
    printf("Enter the number of moves 'm':\n");
    scanf("%d", &m);
    printf("Enter the edge weights:\n");
    for (int i = 0; i < n; ++i) {
        x[i] = 0;
        for (int j = 0; j < n; ++j) {
            if (i == j)
                weight[i][j] = -2147483648;  // (-2^31)
            else
                scanf("%d", &weight[i][j]);
        }
    }
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                printf("  ");
            }
            else
                printf("%d ", weight[i][j]);
        }
        printf("\n");
    }*/
    Update_and_Check(x, weight, n, m, p);
    return 0;
}

void Update_and_Check(int x[], int *wt_ptr, int n, int m, int p) {
    while (m > 0) {
        int b[n];
        for (int i = 0; i < n; i++) {
            b[i] = x[i] * -1;
        }
        for (int i = 0; i < n; i++) {
            int max = -2147483648;
            for (int j = 0; j < n; j++) {
                if (max < wt_ptr[n * j + i] - x[j])
                    max = wt_ptr[n * j + i] - x[j];
            }
            b[i] = max;
        }
        m -= p / 2;
        if (p == 2)
            p = 1;
        else
            p = 2;
        for (int i = 0; i < n; i++) {
            x[i] = b[i];
        }
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        x[i] = wt_ptr[0 + n * i] - x[i];
        if (x[i] > 0)
            flag = true;
    }
    if (flag)
        printf("Player 1 is the winner!");
    else
        printf("Player 2 is the winner!");
}
