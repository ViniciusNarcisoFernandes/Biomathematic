#include<stdio.h>
#include<math.h>

void main()
{
    /*Defininco o numero de colunas para os dados*/
    int col2 = 2, col3 = 3;

    /*-----Bases de dados sem peso - Primeiro arquivo-----*/
    FILE *a = fopen("soc-dolphins - sem peso.mtx","r");
    int N1 = 62, l1 = 159, M1[l1][col2], A1[N1][N1];
    char salvar1[100] = {"A1-Soc-Dolphins-matriz_adjacencia.dat"};
    Matriz_adjacencia(l1,col2,N1,M1,A1,salvar1,a);

    /*-----Bases de dados sem peso - Segundo arquivo-----*/
    FILE *b = fopen("ENZYMES_g1 - sem peso.edges","r");
    int N2 = 37, l2 = 168, M2[l2][col2], A2[N2][N2];
    char salvar2[100] = {"A2-Enzymes-matriz_adjacencia.dat"};
    Matriz_adjacencia(l2,col2,N2,M2,A2,salvar2,b);

    /*-----Bases de dados sem peso - Terceiro arquivo-----*/
    FILE *c = fopen("bio-celegans - sem peso.mtx","r");
    int N3 = 453, l3 = 2025, M3[l3][col2], A3[N3][N3];
    char salvar3[100] = {"A3-Bio-Celegans-matriz_adjacencia.dat"};
    Matriz_adjacencia(l3,col2,N3,M3,A3,salvar3,c);

    /*-----Bases de dados com peso - Quarto arquivo-----*/
    FILE *d = fopen("mammalia-macaque-dominance.edges","r");
    int N4 = 62, l4 = 1167, M4[l4][col3], A4[N4][N4];
    char salvar4[100] = {"A4-Mammalia-Macaque-matriz_adjacencia.dat"};
    Matriz_adjacencia(l4,col3,N4,M4,A4,salvar4,d);

    /*-----Bases de dados com peso - Quinto arquivo-----*/
    FILE *e = fopen("insecta-ant-colony2-day31.edges","r");
    int N5 = 87, l5 = 2008, M5[l5][col3], A5[N5][N5];
    char salvar5[100] = {"A5-Insecta-Ant-matriz_adjacencia.dat"};
    Matriz_adjacencia(l5,col3,N5,M5,A5,salvar5,e);

    /*------Bases de dados com peso - Sexto arquivo-----*/
    FILE *f = fopen("mammalia-kangaroo-interactions.edges","r");
    int N6 = 17, l6 = 91, M6[l6][col3], A6[N6][N6];
    char salvar6[100] = {"A6-Mammalia-kangaroo-matriz_adjacencia.dat"};
    Matriz_adjacencia(l6,col3,N6,M6,A6,salvar6,f);

    /*------Bases de dados com peso - Setimo arquivo-----*/
    FILE *g = fopen("jazz.mtx","r");
    int N7 = 198, l7 = 2742, M7[l7][col3], A7[N7][N7];
    char salvar7[100] = {"A7-Jazz-matriz_adjacencia.dat"};
    Matriz_adjacencia(l7,col3,N7,M7,A7,salvar7,g);

    /*------Bases de dados com peso - Oitavo arquivo-----*/
    FILE *h = fopen("soc-tribes.edges","r");
    int N8 = 16, l8 = 58, M8[l8][col3], A8[N8][N8];
    char salvar8[100] = {"A8-Tribes-matriz_adjacencia.dat"};
    Matriz_adjacencia(l8,col3,N8,M8,A8,salvar8,h);

    /*-------------------------------------------------------------------------------------------------------------------------------------*/
    /*Chamando a matriz de adjacencia - Primeiro arquivo*/
    printf("Primeiro arquivo:\n");
    /*FILE *p = fopen("A1-Soc-Dolphins-matriz_adjacencia.dat","r");
    Sem_Peso(N1,p);*/

    /*Chamando a matriz de adjacencia - Segundo arquivo*/
    printf("\nSegundo arquivo:\n");
    /*FILE *q = fopen("A2-Enzymes-matriz_adjacencia.dat","r");
    Sem_Peso(N2,q);*/

    /*Chamando a matriz de adjacencia - Terceiro arquivo*/
    printf("\nTerceiro arquivo:\n");
    /*FILE *r = fopen("A3-Bio-Celegans-matriz_adjacencia.dat","r");
    Sem_Peso(N3,r);*/

    /*Chamando a matriz de adjacencia - Quarto arquivo*/
    printf("\nQuarto arquivo:\n");
    FILE *s = fopen("A4-Mammalia-Macaque-matriz_adjacencia.dat","r");
    Com_Peso(N4,s);

    /*Chamando a matriz de adjacencia - Quinto arquivo*/
    printf("\nQuinto arquivo:\n");
    /*FILE *t = fopen("A5-Insecta-Ant-matriz_adjacencia.dat","r");
    Com_Peso(N5,t);*/

    /*Chamando a matriz de adjacencia - Sexto arquivo*/
    printf("\nSexto arquivo:\n");
    /*FILE *u = fopen("A6-Mammalia-kangaroo-matriz_adjacencia.dat","r");
    Com_Peso(N6,u);*/

    /*Chamando a matriz de adjacencia - Setimo arquivo*/
    printf("\nSetimo arquivo:\n");
    /*FILE *v = fopen("A7-Jazz-matriz_adjacencia.dat","r");
    Com_Peso(N7,v);*/

    /*Chamando a amtriz de adjacencia*/
    printf("\nOitavo arquivo:\n");
    /*FILE *x = fopen("A8-Tribes-matriz_adjacencia.dat","r");
    Com_Peso(N8,x);*/
}

void Matriz_adjacencia(int linhas, int colunas, int N, int Dados[linhas][colunas], int M[N][N], char salvar[] ,FILE *arquivo)
{
    int i,j;
    /*Puxando os dados*/
    for(i=0;i<linhas;i++)
    {
        for(j=0;j<colunas;j++)
        {
            fscanf(arquivo," %d ",&Dados[i][j]);
        }
    }
    fclose(arquivo);

    /*Preenchendo a matriz de adjacencia*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            M[i][j] = 0;
        }
    }

    /*Verificando o numero de colunas*/
    if(colunas == 2)
    {
        for(i=0;i<linhas;i++)
        {
            for(j=0;j<colunas;j++)
            {
                M[Dados[i][0] - 1][Dados[i][1] - 1] = 1;
                M[Dados[i][1] - 1][Dados[i][0] - 1] = 1;
            }
        }
    }

    if(colunas == 3)
    {
        for(i=0;i<linhas;i++)
        {
            for(j=0;j<colunas;j++)
            {
                M[Dados[i][0] - 1][Dados[i][1] - 1] = Dados[i][3];
                M[Dados[i][1] - 1][Dados[i][0] - 1] = Dados[i][3];
            }
        }
    }
    /*Salvando os dados*/
    FILE *saida_matriz = fopen(salvar,"w");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            fprintf(saida_matriz," %d ",M[i][j]);
        }
        fprintf(saida_matriz,"\n",M[i][j]);
    }
    fclose(saida_matriz);
}

void Sem_Peso(int N, FILE *arquivo_sem_peso)
{
    int i,j,k,MA[N][N];

    /*Puxando os dados*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            fscanf(arquivo_sem_peso,"%d",&MA[i][j]);
        }
    }
    fclose(arquivo_sem_peso);

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
    printf("Densidade de conexoes: %f\n",densidade);

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
    printf("O maior grau de conectvidade: %.3f\n",maior);
    printf("O menor grau de conectividade: %.3f\n",menor);
    printf("O grau de conectividade media: %.3f\n",medio);

    /*Coeficiente de agrupamento global*/
    float coef_total = 0, coef_global;
    for (i = 0; i < N; i++)
    {
        int Numero_triangulos = 0, vertice_grau = 0;
        for(j=0;j<N;j++)
        {
            if(MA[i][j] == 1)
            {
                vertice_grau = vertice_grau + 1;
                for(k=j+1;k<N;k++)
                {
                    if(MA[i][j] == 1 && MA[j][k] == 1)
                    {
                        Numero_triangulos = Numero_triangulos + 1;
                    }
                }
            }
        }
        if(vertice_grau > 1)
        {
            float coef = (2*Numero_triangulos)/(vertice_grau*(vertice_grau-1));
            coef_total = coef_total + coef;
        }
    }
    /*Coeficiente de agrupamento global*/
    coef_global = coef_total/N;
    printf("Coeficiente de agrupamento global:%f\n",coef_global);

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

    /*Algoritmo: Floyd-Marshall*/
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
    printf("Menor caminho medio:%f\n",menor_caminho);
}

void Com_Peso(int N, FILE *arquivo_com_peso)
{
    int i,j,k,W[N][N];

    /*Puxando os dados*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            fscanf(arquivo_com_peso,"%d",&W[i][j]);
        }
    }
    fclose(arquivo_com_peso);

    /*Verificando o numero de conexoes*/
    int conexoes = 0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            conexoes = conexoes + W[i][j];
        }
    }
    printf("Numero de conexoes:%d\n",conexoes/2);

    /*Densidade de conexoes*/
    float densidade;
    densidade = conexoes/(N*(N-1.0));
    printf("Densidade de conexoes:%f\n",densidade);

    /*Calculo da forca de conectividade - Coeficiente de agrupamento*/
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

    /*Coeficiente de agrupamento global*/
    float coef_total = 0, coef_global;
    for (i = 0; i < N; i++)
    {
        int Numero_triangulos = 0, vertice_grau = 0;
        for(j=0;j<N;j++)
        {
            if(W[i][j] != 0)
            {
                vertice_grau = vertice_grau + 1;
                for(k=j+1;k<N;k++)
                {
                    if(W[i][j] != 0 && W[j][k] != 0)
                    {
                        Numero_triangulos = Numero_triangulos + 1;
                    }
                }
            }
        }
        if(vertice_grau > 1)
        {
            float coef = (2*Numero_triangulos)/(vertice_grau*(vertice_grau-1));
            coef_total = coef_total + coef;
        }
    }
    /*Coeficiente de agrupamento global*/
    coef_global = coef_total/N;
    printf("Coeficiente de agrupamento global:%f\n",coef_global);

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

    /*Algoritmo: Floyd-Marshall*/
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
    printf("Menor caminho medio:%f\n",menor_caminho);
}


