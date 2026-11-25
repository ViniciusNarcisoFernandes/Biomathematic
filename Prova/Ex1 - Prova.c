#include<stdio.h>
#include<math.h>

/*Definindo constantes*/
#define sigma 10
#define b 8/3
#define r 28
#define tmax 30
#define tmin 0
#define h 0.01

/*Edo em dx/dt*/
float fX(float X, float Y)
{
    return (sigma*(-X+Y));
}

/*Edo em dy/dt*/
float fY(float X, float Y, float Z)
{
    return (r*X - Y - X*Z);
}

/*Edo em dz/dt*/
float fZ(float X, float Y, float Z)
{
    return (-b*Z + X*Y);
}

main()
{
    /*Definindo variaveis*/
    int i,j,N;
    float k1,k2,k3,k4,l1,l2,l3,l4,m1,m2,m3,m4;

    /*Tamanho do vetor*/
    N = (tmax-tmin)/h;
    float X[N],Y[N],Z[N],T[N];

    /*Runge-kutta de quarta-ordem*/
    for(i=0;i<=N;i++)
    {
        /*Adicionando as condições inicias*/
        T[0] = 0;
        X[0] = 5.01;
        Y[0] = 5;
        Z[0] = 5;

        /*Valor de k1, l1 e m1*/
        k1 = h*fX(X[i],Y[i]);
        l1 = h*fY(X[i],Y[i],Z[i]);
        m1 = h*fZ(X[i],Y[i],Z[i]);

        /*Valor de k2, l2 e m2*/
        k2 = h*fX((X[i] + (k1*0.5)), (Y[i] + (l1*0.5)));
        l2 = h*fY((X[i] + (k1*0.5)), (Y[i] + (l1*0.5)), (Z[i] + (m1*0.5)));
        m2 = h*fZ((X[i] + (k1*0.5)), (Y[i] + (l1*0.5)), (Z[i] + (m1*0.5)));

        /*Valor de k3, l3 e m3*/
        k3 = h*fX((X[i] + (k2*0.5)), (Y[i] + (l2*0.5)));
        l3 = h*fY((X[i] + (k2*0.5)), (Y[i] + (l2*0.5)), (Z[i] + (m2*0.5)));
        m3 = h*fZ((X[i] + (k2*0.5)), (Y[i] + (l2*0.5)), (Z[i] + (m2*0.5)));

        /*Valor de k4, l4 e m4*/
        k4 = h*fX((X[i] + k3), (Y[i] + l3));
        l4 = h*fY((X[i] + k3), (Y[i] + l3), (Z[i] + m3));
        m4 = h*fZ((X[i] + k3), (Y[i] + l3), (Z[i] + m3));

        /*Adicionando os valores nos vetores*/
        T[i+1] = T[i] + h;
        X[i+1] = X[i] + ((k1 + 2*k2 + 2*k3 + k4)/6);
        Y[i+1] = Y[i] + ((l1 + 2*l2 + 2*l3 + l4)/6);
        Z[i+1] = Z[i] + ((m1 + 2*m2 + 2*m3 + m4)/6);
    }

    /*Colocando os dados em uma unica matriz*/
    float Runge[N][4];
    for(i=0;i<N;i++)
    {
        Runge[i][0] = T[i];
        Runge[i][1] = X[i];
        Runge[i][2] = Y[i];
        Runge[i][3] = Z[i];
    }

    /*Verificando os valores da matriz de runge-kutta*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("  %f  ",Runge[i][j]);
        }
        printf("\n");
    }

    FILE *dados_saida;
    dados_saida = fopen("Runge-kutta - condicao2.txt","w");
    for(i=0;i<N;i++)
    {
        for(j=0;j<4;j++)
        {
            fprintf(dados_saida," %f ",Runge[i][j]);
        }
        fprintf(dados_saida,"\n",Runge[i][j]);
    }
    fclose(dados_saida);
}


