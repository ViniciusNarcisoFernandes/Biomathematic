#include<stdio.h>
#include<math.h>

void Sem_Peso(int L, int C, int N, int MA[N][N], int Dados[L][C],FILE* ponteiro_sem_peso)
    int i,j,k;
    FILE *ponteiro_sem_peso;
    for(i=0;i<L;i++)
    {
        for(j=0;j<C;j++)
        {
            fscanf(ponteiro_sem_peso,"%d",&Dados[i][j]);
        }
    }
    fclose(ponteiro_sem_peso);
    /* Construcao da matriz adjacencia: zerando todos os elementos*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            MA[i][j] = 0;
        }
    }

    /*Construindo a matriz de adjacencia*/
    for(i=0;i<L;i++)
    {
        for(j=0;j<C;j++)
        {
            MA[Dados[i][0] - 1][Dados[i][1] - 1] = 1;
            MA[Dados[i][1] - 1][Dados[i][0] - 1] = 1;
        }
    }

    /*Verificando a matriz de adjacencia*/
    printf("Matriz Adjacencia:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf(" %d ",MA[i][j]);
        }
        printf("\n");
    }
    /*Verificando o número de conexoes*/
    int conexoes = 0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            conexoes = conexoes + MA[i][j];
        }
    }
    printf("O numero de conexos:%d\n",conexoes/2);

    /*Densidade de conexoes*/
    float densidade;
    densidade = conexoes/(N*(N-1.0));
    printf("A densidade de conexoes:%f\n",densidade);

    /*Calculo do grau de conectividade*/
    int grau[N];
    for(i=0;i<N;i++)
    {
        grau[i] = 0;
        for(j=0;j<N;j++)
        {
            grau[i] = grau[i] + MA[i][j];
        }
    }
    printf("Grau de conectividade:\n");
    for(i=0;i<N;i++)
    {
        printf("Vertice: %d - Grau de conectividade: %d\n",i+1,grau[i]);
    }
    /*Calculo do menor, maior graus de conectividade e o grau de conectividade medio*/
    float menor_grau,maior_grau,grau_medio,soma_grau=0;
    menor_grau = grau[0];
    maior_grau = grau[0];
    for(i=0;i<N;i++)
    {
        soma_grau = soma_grau + grau[i];
        if(grau[i] > maior_grau)
        {
            maior_grau = grau[i];
        }
        if(grau[i] < menor_grau)
        {
            menor_grau = grau[i];
        }
    }
    grau_medio = soma_grau/N;
    printf("Maior grau de conectividade: %.3f, Menor grau de conectividade: %.3f, Grau de conectividade medio: %.3f\n",maior_grau,menor_grau,grau_medio);
    Coeficiente de agrupamento medio*/
    float conec[N],soma_conec = 0, coef_agrupamento;
    for(i=0;i<N;i++)
    {
        conec[i] = (2*grau[i])/(grau[i]*(grau[i]-1));
        soma_conec = soma_conec + conec[i];
    }
    coef_agrupamento = soma_conec/N;
    printf("O coeficiente de agrupamento:%f\n",coef_agrupamento);*/
    /*Menor Caminho - Floyd-Warshall*/
    int dist[N][N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            dist[i][j] = MA[i][j];
        }
    }
    /*Fazendo o algoritmo de Floyd-Marshall*/
    for(k=0;k<N;k++)
    {
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(dist[i][j] > (dist[i][k] + dist[k][j]))
                {
                    dist[i][j] = (dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    printf("Mostrando a matriz de distancia de Floyd-Marshall:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf(" %d ",dist[i][j]);
        }
        printf("\n");
    }
    /*Fazendo o menor caminho*/
    float menor_caminho = 0,soma_menor_caminho;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i!=j)
            {
                menor_caminho = menor_caminho + 1;
            }
        }
    }
    soma_menor_caminho = menor_caminho/(N*(N-1.0));
    printf("Menor caminho:%f\n",soma_menor_caminho);
}

void Com_Peso(int L, int C, int N, int W[N][N], int Dados[L][C],FILE* ponteiro_com_peso)
    int i,j,k;
    FILE *ponteiro_com_peso;
    for(i=0;i<L;i++)
    {
        for(j=0;j<C;j++)
        {
            fscanf(ponteiro_com_peso,"%d",&Dados[i][j]);
        }
    }
    fclose(ponteiro_cem_peso);
    /* Construcao da matriz adjacencia: zerando todos os elementos*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            W[i][j] = 0;
        }
    }

    /*Construindo a matriz de adjacencia*/
    for(i=0;i<L;i++)
    {
        for(j=0;j<C;j++)
        {
            W[Dados[i][0] - 1][Dados[i][1] - 1] = Dados[i][3];
            W[Dados[i][1] - 1][Dados[i][0] - 1] = Dados[i][3];
        }
    }

    /*Verificando a matriz de adjacencia*/
    printf("Matriz Adjacencia:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf(" %d ",W[i][j]);
        }
        printf("\n");
    }
    /*Verificando o número de conexoes*/
    int conexoes = 0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            conexoes = conexoes + W[i][j];
        }
    }
    printf("O numero de conexos:%d\n",conexoes/2);

    /*Densidade de conexoes*/
    float densidade;
    densidade = conexoes/(N*(N-1.0));
    printf("A densidade de conexoes:%f\n",densidade);

    /*Calculo do grau de conectividade*/
    int grau[N];
    for(i=0;i<N;i++)
    {
        grau[i] = 0;
        for(j=0;j<N;j++)
        {
            grau[i] = grau[i] + W[i][j];
        }
    }
    printf("Grau de conectividade:\n");
    for(i=0;i<N;i++)
    {
        printf("Vertice: %d - Grau de conectividade: %d\n",i+1,grau[i]);
    }
    /*Calculo do menor, maior graus de conectividade e o grau de conectividade medio*/
    float menor_grau,maior_grau,grau_medio,soma_grau=0;
    menor_grau = grau[0];
    maior_grau = grau[0];
    for(i=0;i<N;i++)
    {
        soma_grau = soma_grau + grau[i];
        if(grau[i] > maior_grau)
        {
            maior_grau = grau[i];
        }
        if(grau[i] < menor_grau)
        {
            menor_grau = grau[i];
        }
    }
    grau_medio = soma_grau/N;
    printf("Maior grau de conectividade: %.3f, Menor grau de conectividade: %.3f, Grau de conectividade medio: %.3f\n",maior_grau,menor_grau,grau_medio);
    Coeficiente de agrupamento medio*/
    float conec[N],soma_conec = 0, coef_agrupamento;
    for(i=0;i<N;i++)
    {
        conec[i] = (2*grau[i])/(grau[i]*(grau[i]-1));
        soma_conec = soma_conec + conec[i];
    }
    coef_agrupamento = soma_conec/N;
    printf("O coeficiente de agrupamento:%f\n",coef_agrupamento);*/
    /*Menor Caminho - Floyd-Warshall*/
    int dist[N][N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            dist[i][j] = W[i][j];
        }
    }
    /*Fazendo o algoritmo de Floyd-Marshall*/
    for(k=0;k<N;k++)
    {
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(dist[i][j] > (dist[i][k] + dist[k][j]))
                {
                    dist[i][j] = (dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    printf("Mostrando a matriz de distancia de Floyd-Marshall:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf(" %d ",dist[i][j]);
        }
        printf("\n");
    }
    /*Fazendo o menor caminho*/
    float menor_caminho = 0,soma_menor_caminho;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i!=j)
            {
                menor_caminho = menor_caminho + 1;
            }
        }
    }
    soma_menor_caminho = menor_caminho/(N*(N-1.0));

    printf("Menor caminho:%f",soma_menor_caminho);
}

void main()
{
    /*Primeira base de dados*/
    FILE *a;
    int N1 = 62, l1 = 159, c1 = 2, M1[l1][c1], A1[N1][N1];
    a = fopen("soc-dolphins - sem peso.mtx","r");
    Sem_Peso(l1,c1,N1,M1[159][2],A1[N1][N1],a);

    /*Segunda base de dados*/
    FILE *b;
    int N2 = 31, l2 = 168, c2 = 2, M2[l2][c2], A2[N2][N2];
    b = fopen("ENZYMES_g1 - sem peso.edges","r");
    /*Sem_Peso(l2,c2,N2,M2[l2][c2],A2[N2][N2],b);*/

    /*Terceira base de dados*/
    FILE *c;
    c = fopen("bio-celegans - sem peso.mtx","r");
    int N3 = 453, l3 = 2025, c3 = 2, M3[l3][c3], A3[N3][N3];
    /*Sem_Peso(l3,c3,N3,M3[l3][c3],A3[N3][N3],c);*/

    /*Base de dados com peso*/

    /*Quarta base de dados*/
    FILE *d;
    d = fopen("mammalia-macaque-dominance.edges","r");
    int N4 = 62, l4 = 1167, c4 = 3, M4[l4][c4], A4[N4][N4];

    /*Quinta base de dados*/
    FILE *e;
    e = fopen("insecta-ant-colony2-day31.edges","r");
    int N5 = 87, l5 = 2008, c5 = 3, M5[l5][c5], A5[N5][N5];

    /*Sexta base de dados*/
    FILE *f;
    f = fopen("mammalia-kangaroo-interactions.edges","r");
    int N6 = 17, l6 = 91, c6 = 3, M6[l6][c6], A6[N6][N6];

    /*Setima base de dados*/
    FILE *g;
    g = fopen("jazz.edges","r");
    int N7 = 198, l7 = 2742, c7 = 3, M7[l7][c7], A7[N7][N7];

    /*Oitava base de dados*/
    FILE *h;
    h = fopen("soc-tribes.edges","r");
    int N8 = 16, l8 = 58, c8 = 3, M8[l8][c8], A8[N8][N8];
}

