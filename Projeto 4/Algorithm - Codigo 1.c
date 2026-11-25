#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void main()
{
    int N = 62, i,j, MA[N][N],LA[159][2],n_conexoes = 0;
    FILE *entrada;
    entrada = fopen("soc-dolphins.mtx","r");
    for(i=0;i<159;i++)
    {
        for(j=0;j<2;j++)
        {
            fscanf(entrada,"%d",&LA[i][j]);
            printf(" %d ",LA[i][j]);
        }
        printf("\n");
    }
    fclose(entrada);
    /* Construcao da matriz adjacencia: zerando todos os elementos*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            MA[i][j] = 0;
        }
    }
    /*Construindo a matriz adjacência*/
    for(i=0;i<159;i++)
    {
        for(j=0;j<2;j++)
        {
            MA[LA[i][0] - 1][LA[i][1] - 1] = 1;
            MA[LA[i][1] - 1][LA[i][0] - 1] = 1;
        }
    }
    /*Verificando o numero de conexoes*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            n_conexoes = n_conexoes + MA[i][j];
        }
    }
    printf("O numero de conexoes: %d\n",n_conexoes/2);

    /*Imprimindo a matriz de adjacencia em um arquivo de saida*/

    FILE *saida_matriz_adjacencia;
    saida_matriz_adjacencia = fopen("matriz_adjacencia_dolphins.dat","w");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            fprintf(saida_matriz_adjacencia," %d ",MA[i][j]);
        }
        fprintf(saida_matriz_adjacencia,"\n",MA[i][j]);
    }
    fclose(saida_matriz_adjacencia);

    /*Fazendo a densidade de conexoes*/
    float d_conexoes;
    d_conexoes = n_conexoes/(N*(N-1.0));
    printf("densidade de conexoes: %f",d_conexoes);

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
    float menor_grau_conectividade,maior_grau_conectividade, conectividade_medio, soma_grau = 0;
    menor_grau_conectividade = grau_vertices[0];
    maior_grau_conectividade = grau_vertices[0];
    conectividade_medio = 0;
    /*Calculando esses graus*/
    for(i=0;i<N;i++)
    {
        soma_grau = soma_grau + grau_vertices[i];
        if(grau_vertices[i] > maior_grau_conectividade)
        {
            maior_grau_conectividade = grau_vertices[i];
        }
        if(grau_vertices[i] < menor_grau_conectividade)
        {
            menor_grau_conectividade = grau_vertices[i];
        }
    }
    conectividade_medio = soma_grau/N;
    printf("O maior grau de conectvidade:%.3f, menor grau de conectividade: %.3f, grau de conectividade media: %.3f",
           maior_grau_conectividade,menor_grau_conectividade,conectividade_medio);

    /*Fazer uma pesquisa em como randomizar uma rede*/
    /*Matriz com peso nao faz sentido calcular a densidade, calcular a forca de conectividade dos vertices*/

}
