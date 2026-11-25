#include<stdio.h>
# define inf 99999
main()
{
    int N = 100, MA[N][N], LA[400][2],i,j,k;
    FILE *entrada_dados;
    entrada_dados = fopen("WS.txt","r");
    /*Abrindo os dados*/
    for(i=0;i<400;i++)
    {
        for(j=0;j<2;j++)
        {
            fscanf(entrada_dados," %d ", &LA[i][j]);
        }
    }
    fclose(entrada_dados);
    /*Construindo a matriz de adjacencia*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            MA[i][j] = 0;
        }
    }
    /*Preenchendo a matriz de adjacencia*/
    for(i=0;i<400;i++)
    {
        for(j=0;j<2;j++)
        {
            MA[LA[i][0] - 1][LA[i][1] - 1] = 1;
            MA[LA[i][1] - 1][LA[i][0] - 1] = 1;
        }
    }
    /*Verificando o numero de conexoes*/
    float numero_conexoes = 0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            numero_conexoes = numero_conexoes + MA[i][j];
        }
    }

    /*----------- 2.1 ----------*/

    /*------ Densidade de conexoes ------*/
    float densidade_conexoes;
    densidade_conexoes = numero_conexoes/(N*(N-1.0));
    printf("Densidade de conexoes: %f\n",densidade_conexoes);

    /*Comprimento medio do menor caminho L*/
    float dist[N][N];
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

    /*Menor caminho*/
    float menor_caminho, somar_caminho = 0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i!=j && dist[i][j] != inf)
            {
                somar_caminho = somar_caminho + dist[i][j];
            }
        }
    }
    menor_caminho = somar_caminho/(N*(N-1.0));
    printf("Menor caminho medio:%f\n",menor_caminho);

    /*------ Coeficiente de agrupamento medio ------*/
    float coef_total = 0, coef_medio;
    int numero_triangulo = 0, vertice_grau = 0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(MA[i][j] != 0)
            {
                vertice_grau = vertice_grau + 1;
                for(k=j+1;k<N;k++)
                {
                    if(MA[i][j] != 0 && MA[j][k] != 0)
                    {
                        numero_triangulo = numero_triangulo + 1;
                    }
                }
            }
        }
        if(vertice_grau > 1)
        {
            coef_total = coef_total + (2*numero_triangulo)/(vertice_grau*(vertice_grau-1.0));
        }
    }
    /*Coeficiente de agrupamento medio*/
    coef_medio = coef_total/N;
    printf("Coeficiente de agrupamento medio: %f\n",coef_medio);

    /*----------- 2.2 ----------*/

    /*Calculando a eficiencia*/
    float soma = 0, dist2[N][N], eficiencia;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i!=j && MA[i][j] == 0)
            {
                dist2[i][j] = inf;
            }
            else
            {
                dist2[i][j] = MA[i][j];
            }
        }
    }

    /*Algoritmo Floyd-Warshall*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            for(k=0;k<N;k++)
            {
                if(dist2[j][k] > (dist2[j][i] + dist2[i][k]))
                {
                    dist2[j][k] = dist2[j][i] + dist2[i][k];
                }
            }
        }
    }
    /*Calculando a eficiencia global*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i!=j && dist2[i][j] != inf)
            {
                soma = soma + (1.0/dist2[i][j]);
            }
        }
    }
    eficiencia = soma/(N*(N-1.0));
    printf("Eficiencia:%f \n",eficiencia);
}
