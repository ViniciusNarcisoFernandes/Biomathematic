#include<stdio.h>
#include<time.h>

void insere_borda_periodica(int N, int Aut[N][N], int Aut2[N+2][N+2])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            Aut2[i+1][j+1] = Aut[i][j];
        }
        /*Inserindo as bordas*/
        Aut2[0][i] = Aut[N-1][i];
        Aut2[N+1][i] = Aut[0][i];
        Aut2[i][0] = Aut[i][N-1];
        Aut2[i][N+1] = Aut[i][0];
    }
    /*Preenchendo as bordas*/
    Aut2[0][0] = Aut[N-1][N-1];
    Aut2[0][N+1] = Aut[N-1][0];
    Aut2[N+1][0] = Aut[0][N-1];
    Aut2[N+1][N+1] = Aut[0][0];
}

main()
{
    srand(time(NULL));
    /*Dados iniciais do meu codigo*/
    int N = 50,Aut[N][N],Aut2[N+2][N+2],i,j,tmax = 100,t,aux;
    float porcent = 0.01,mi = 0.375,lambda = 0.25, s , n = N;

    /*Matriz de zeros do automato celular*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            Aut[i][j] = 0;
        }
    }

    aux = porcent*N*N;

    /*Criando a matriz de automatos*/
    for(t=0;t<aux;t++)
    {
        /*linha e coluna aleatoria*/
        i = rand() % N;
        j = rand() % N;
        Aut[i][j] = 1;
    }

    /*mostrando a matriz de automatos*/
    printf("\nA primeira matriz de automatos:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d ",Aut[i][j]);
        }
        printf("\n");
    }
    
    /*chamando a funcao preenchida*/
    insere_borda_periodica(N, Aut,Aut2);
    printf("\nA segunda matriz de automatos com bordas:\n");
    
    /*mostrando a matriz de automatos*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d ",Aut2[i][j]);
        }
        printf("\n");
    }

    /*Sequencial*/
    for(t=0;t<tmax;t++)
    {
        i = rand() % N;
        j = rand() % N;
        if(Aut[i][j] == 0)
        {
            i = i + 1;
            j = j + 1;
            if(Aut2[i-1][j] == 1 || Aut2[i+1][j] == 1 || Aut2[i][j-1] == 1 || Aut2[i][j+1] == 1)
            {
                s = rand() % N/n;
                if(s <= lambda)
                {
                    Aut[i-1][i-1] = 1;
                }
            }
        }
        else
        {
            s = rand() % N/n;
            if(s <= mi)
            {
                Aut[i][j] = 0;
            }
        }
        insere_borda_periodica(N, Aut, Aut2);
    }

    /*mostrando a matriz de automatos*/
    printf("\nA matriz alterada:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d ",Aut[i][j]);
        }
        printf("\n");
    }
}
