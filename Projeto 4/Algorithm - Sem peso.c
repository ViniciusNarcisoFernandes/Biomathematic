#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void main()
{
    int N = 62, i,j,k,L=159,C=2,MA[N][N],Dados[L][C];
    FILE *entrada;
    entrada = fopen("soc-dolphins - sem peso.mtx","r");
    for(i=0;i<L;i++)
    {
        for(j=0;j<C;j++)
        {
            fscanf(entrada,"%d",&Dados[i][j]);
        }
    }
    fclose(entrada);

    /*Mostrando os dados*/
    for(i=0;i<L;i++)
    {
        for(j=0;j<C;j++)
        {
            printf(" %d ",Dados[i][j]);
        }
        printf("\n");
    }

    /* Construcao da matriz adjacencia: zerando todos os elementos*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            MA[i][j] = 0;
        }
    }
    /*Construindo a matriz adjacência*/
    for(i=0;i<L;i++)
    {
        for(j=0;j<2;j++)
        {
            MA[Dados[i][0] - 1][Dados[i][1] - 1] = 1;
            MA[Dados[i][1] - 1][Dados[i][0] - 1] = 1;
        }
    }

    printf("\nA matriz de Adjacencia:\n");
    /*Mostrando a matriz de adjacencia*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf(" %d ",MA[i][j]);
        }
        printf("\n");
    }

    /*Verificando o numero de conexoes*/
    int conexoes = 0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            conexoes = conexoes + MA[i][j];
        }
    }
    printf("O numero de conexoes: %d\n",conexoes/2);

    /*Fazendo a densidade de conexoes*/
    float densidade;
    densidade = conexoes/(N*(N-1.0));
    printf("densidade de conexoes: %f",densidade);

    /*Calculo do grau de conectividade de cada vertice*/
    int grau_vertices[N];
    for(i=0;i<N;i++)
    {
        grau_vertices[i] = 0;
        for(j=0;j<N;j++)
        {
            grau_vertices[i] = grau_vertices[i] + MA[i][j];
        }
    }
    printf("\nGrau de conectividade\n");
    for(i=0;i<N;i++)
    {
        printf("Vertice: %d - Grau de conectividade: %d\n",i+1,grau_vertices[i]);
    }
    /*Calculo do menor e maior graus de conectividade e o grau de  conectividade media*/
    float menor = grau_vertices[0],maior = grau_vertices[0], medio, soma_grau = 0;

    /*Calculando esses graus*/
    for(i=0;i<N;i++)
    {
        soma_grau = soma_grau + grau_vertices[i];
        if(grau_vertices[i] > maior)
        {
            maior = grau_vertices[i];
        }
        if(grau_vertices[i] < menor)
        {
            menor = grau_vertices[i];
        }
    }
    medio = soma_grau/N;
    printf("O maior grau de conectvidade:%.3f, menor grau de conectividade: %.3f, grau de conectividade media: %.3f",maior,menor,medio);

     /*Menor Caminho*/
    float dist[N][N], inf = 9999;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i!=j && MA[i][j] == 0)
            {
                dist[i][j] = inf;
            }
            else
            {
                dist[i][j] = MA[i][j];
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
