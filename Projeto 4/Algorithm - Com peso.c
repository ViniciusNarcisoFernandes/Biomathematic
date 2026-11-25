#include<stdio.h>
#include<math.h>

main()
{
    int N=16,linha=58,coluna=3,i,j,k,Dados[linha][coluna],W[N][N];
    FILE *entrada;
    entrada =  fopen("soc-tribes.edges","r");
    /*Salvando os dados*/
    for(i=0;i<linha;i++)
    {
        for(j=0;j<coluna;j++)
        {
            fscanf(entrada," %d ",&Dados[i][j]);
        }
    }
    fclose(entrada);
    /*Mostrando os dados da rede*/
    printf("\nConjunto de dados:\n");
    for(i=0;i<linha;i++)
    {
        for(j=0;j<coluna;j++)
        {
            printf(" %d ",Dados[i][j]);
        }
        printf("\n");
    }
    /*Construindo a matriz adjacencia*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            W[i][j] = 0;
        }
    }
    /*Preenchendo a matriz de adjacencia*/
    for(i=0;i<linha;i++)
    {
        for(j=0;j<coluna;j++)
        {
            W[Dados[i][0] - 1][Dados[i][1] - 1] = Dados[i][3]*1;
            W[Dados[i][1] - 1][Dados[i][0] - 1] = Dados[i][3]*1;
        }
    }
    /*Mostrando a matriz de adjacencia*/
    printf("\nRede complexa com pesos:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf(" %d ",W[i][j]);
        }
        printf("\n");
    }
    /*Verificando o numero de conexoes*/
    int conexoes = 0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            conexoes = conexoes + W[i][j];
        }
    }
    printf("\nNumero de conexoes:%d\n",conexoes/2);

    /*Densidade de conexoes*/
    float densidade;
    densidade = conexoes/(N*(N-1.0));
    printf("\nDensidade de conexoes:%f\n",densidade);

    /*Calculo da forca de conectividade*/
    float Fin[N],Fout[N], soma_forca = 0;
    for(i=0;i<N;i++)
    {
        Fin[i] = 0, Fout[i] = 0;
        for(j=0;j<N;j++)
        {
            soma_forca = soma_forca + W[i][j];
            Fin[i] = Fin[i] + W[i][j];
            Fout[i] = Fout[i] + W[i][j];
        }
    }
    printf("\nForca de conectividade:%f\n",soma_forca);

    for(i=0;i<N;i++)
    {
        printf("%d - Fin = %f - Fout = %f \n",i+1,Fin[i],Fout[i]);
    }

    /*Menor Caminho*/
    float dist[N][N], inf = 9999;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i!=j && W[i][j] == 0)
            {
                dist[i][j] = inf;
            }
            else
            {
                dist[i][j] = W[i][j];
            }
        }
    }

    /*Algorythm: Floyd-Marshall*/
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
    printf("\nMatriz de distancia de Floyd-Marshall\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf(" %.2f ", dist[i][j]);
        }
        printf("\n");
    }
    /*O menor caminho*/
    float menor_caminho, soma_menor_caminho = 0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i!=j)
            {
                soma_menor_caminho = soma_menor_caminho + dist[i][j];
            }
        }
    }
    menor_caminho = soma_menor_caminho/(N*(N-1.0));
    printf("\nMenor caminho medio:%f\n",menor_caminho);

}

