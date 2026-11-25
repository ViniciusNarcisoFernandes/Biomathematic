#include<stdio.h>

main()
{
    int i,j,N = 3;
    float A[N][N],T[N][N];
    printf("Preenchendo a matriz:\n");
    /*Preenchendo a matriz*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("A[%d][%d] = ",i,j);
            scanf("%f",&A[i][j]);
        }
    }
    /*Mostrando a matriz*/
    printf("\nMatriz antes de ser transposta:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf(" %f ", A[i][j]);
        }
        printf("\n");
    }
    /*Fazendo a transposicao da matriz*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            T[i][j] = A[j][i];
        }
    }
    /*Verificando o valor da matriz transposta*/
    printf("\nTransposicao da matriz A:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf(" %f ",T[i][j]);
        }
        printf("\n");
    }
}
