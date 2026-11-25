#include<stdio.h>
#include<time.h>

#define mi 0.375
#define lambda 0.25

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
    /*Dados iniciais do codigo*/
    int N = 200,tmax = 100,i,j,t,aux,Aut[N][N],Aut2[N+2][N+2];
    float porc = 0.1,s , n = N;

    /*Matriz de zeros do automato celular*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            Aut[i][j] = 0;
        }
    }

    aux = porc*N*N;

    /*Criando a matriz de automatos*/
    for(t=0;t<aux;t++)
    {
        /*linha e coluna aleatoria*/
        i = rand() % N;
        j = rand() % N;
        Aut[i][j] = 1;
    }

    /*chamando a funcao preenchida*/
    insere_borda_periodica(N,Aut,Aut2);

    /*Salvando a matriz de automatos*/
    FILE *Aut2_saida = fopen("200x200(0.1)-matriz_automatos_inicial","w");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            fprintf(Aut2_saida," %d ",Aut2[i][j]);
        }
        fprintf(Aut2_saida,"\n",Aut2[i][j]);
    }
    fclose(Aut2_saida);

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

    /*Salvando os dados*/
    FILE *Aut_saida = fopen("200x200(0.1)-Aut_atualizada.dat","w");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            fprintf(Aut_saida," %d ",Aut[i][j]);
        }
        fprintf(Aut_saida,"\n",Aut[i][j]);
    }
    fclose(Aut_saida);
}
