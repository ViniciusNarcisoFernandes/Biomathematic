#include<stdio.h>
#define inf 99999


void multiplica_matriz(int N, int B[N][N], int C[N][N], int BC[N][N])
{
    int i,j,k;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            BC[i][j] = 0;
            for(k=0;k<N;k++)
            {
                BC[i][j] = BC[i][j] + (B[i][k]*C[k][j]);
            }
        }
    }
}

main()
{
    /*Definindo variaveis*/
    int i,j,k,N = 300, A[N][N];
    FILE *dados_entrada;
    dados_entrada = fopen("BA.txt","r");
    /*Abrindo a matriz de adjacencia*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            fscanf(dados_entrada," %d ", &A[i][j]);
        }
    }
    fclose(dados_entrada);

    /*------------ 3.1 -----------*/

    /*Verificando se a matriz e simetrica*/
    float T[N][N],soma = 0;

    /*Fazendo a transposicao da matriz de adjacencia*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            T[i][j] = A[j][i];
        }
    }

    /*Verificando se a matriz e simetrica*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(A[i][j] != T[i][j])
            {
                soma = soma + 1;
            }
        }
    }

    /*Soma == 0 - Matriz Simetrica, Soma != 0 Matriz assimetrica */
    if(soma == 0)
    {
        printf("\nA matriz e simetrica, logo a rede e nao direcionada.\n");
    }
    else
    {
        printf("\nA matriz e assimetrica, logo a rede e direcionada.\n");
    }

    /*------------ 3.2 -----------*/

    /*Ciclo N3 e Ciclo N4*/
    int A2[N][N],A3[N][N],A4[N][N];
    float soma_N3 = 0,N3,soma_A4 = 0 , soma_prod = 0, soma_A2 = 0,soma_N4;
    multiplica_matriz(N,A,A,A2);
    multiplica_matriz(N,A2,A,A3);
    multiplica_matriz(N,A3,A,A4);

    /*Somando os elementos da diagonal*/
    for(i=0;i<N;i++)
    {
        soma_N3 = soma_N3 + A3[i][i];
        soma_A4 = soma_A4 + A4[i][i];
        soma_prod = soma_prod + (A2[i][i]*A2[i][i]);
        soma_A2 = soma_A2 + A2[i][i];
    }
    soma_N4 = soma_A4 - 2*soma_prod + soma_A2;
    printf("ciclo N3: %f triangulos, ciclo N4: %f Quadrados\n",soma_N3/6,soma_N4/8);

    /*------------ 3.3 -----------*/
    int dist[N][N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i!=j && A[i][j] == 0)
            {
                dist[i][j] = inf;
            }
            else
            {
                dist[i][j] = A[i][j];
            }
        }
    }

    /*Algoritmo de Floyd-Warshall*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            for(k=0;k<N;k++)
            {
                if(dist[j][k] > (dist[j][i] + dist[i][k]))
                {
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }

    /*Inverso do Menor caminho*/
    float somar_caminho = 0,Cc[N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i!=j && dist[i][j] != inf)
            {
                somar_caminho = somar_caminho + dist[i][j];
            }
        }
        if(somar_caminho > 0)
        {
            Cc[i] = 1.0/somar_caminho;
        }
        else
        {
            Cc[i] = 0;
        }
    }

    /*Colocando os dados em matriz*/
    float MatrizC[N][N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<2;j++)
        {
            MatrizC[i][0] = i+1;
            MatrizC[i][1] = Cc[i];
        }
    }
    /*Salvando os dados*/
    FILE *dados_saida;
    dados_saida = fopen("Centralidade de closeness.txt","w");
    for(i=0;i<N;i++)
    {
        for(j=0;j<2;j++)
        {
            fprintf(dados_saida," %f ",MatrizC[i][j]);
        }
        fprintf(dados_saida,"\n",MatrizC[i][j]);
    }
    fclose(dados_saida);
}
