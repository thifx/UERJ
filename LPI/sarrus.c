#include <stdio.h>

int main()
{
    double matrix[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }
    double diag1 = matrix[0][0] * matrix[1][1] * matrix[2][2];
    double diag2 = matrix[0][1] * matrix[1][2] * matrix[2][0];
    double diag3 = matrix[0][2] * matrix[1][0] * matrix[2][1];

    double diag4 = matrix[0][2] * matrix[1][1] * matrix[2][0];
    double diag5 = matrix[0][0] * matrix[1][2] * matrix[2][1];
    double diag6 = matrix[0][1] * matrix[1][0] * matrix[2][2];

    double det = diag1 + diag2 + diag3 - diag4 - diag5 - diag6;
    printf("%.1lf", det);
}