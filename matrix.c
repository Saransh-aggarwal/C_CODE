#include <stdio.h>

void mul(int a[][3], int b[][3],int res[][3], int m, int n, int p)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
void display(int a[][3], int rows, int cols)
{
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int A1[2][3] = {{1, 2,3}, {1,2, 3}};
    int A2[3][3] = {{1, 2, 3}, {2, 3, 4},{3,4,5}};
    int res[2][3];
    display(A1, 2, 3);
    display(A2, 3, 3);
    mul(A1, A2, res, 2, 3, 3);
    display(res, 2, 3);
    return 0;
}
