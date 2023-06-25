#include <stdio.h>
int MAX_Row(int n, int a[][n], int i);
int MAX_Col(int n, int a[][n], int j);
int main()
{
    int n, m, array[n][n];
    printf("Enter the number of vertices 'n':\n");
    scanf("%d", &n);
    printf("Enter the number of moves 'm':\n");
    scanf("%d", &m);
    printf("Enter the edge weights:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                array[i][j] = -2147483648;  // (-2^31)
            else
                scanf("%d", &array[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                printf("  ");
            }
            else
                printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    for (int node = 0; node < n; node++) {
        //  Trying to backtrace the sequence of each node-end, don't know how to exactly code it
    }
    return 0;
}
int MAX_Row(int n, int a[][n], int i)
{
    int MAX = 0;
    for (int j = 0; j < n; ++j) {
        if (a[i][j] > MAX)
            MAX = a[i][j];
    }
    return MAX;
}
int MAX_Col(int n, int a[][n], int j)
{
    int MAX = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i][j] > MAX)
            MAX = a[i][j];
    }
    return MAX;
}