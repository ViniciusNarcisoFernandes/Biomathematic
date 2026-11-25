#include<stdio.h>
#include<math.h>

float fx(float x, float y, float z)
{
    return (-2*x+y+z);
}

float fy(float x, float y, float z)
{
    return (x-2*y+z);
}

float fz(float x, float y, float z)
{
    return (x+y-2*z);
}

main()
{
    int N = 50,i,j;
    float h = 0.1;
    float T[N],X[N],Y[N],Z[N];
    float k1,k2,k3,k4,l1,l2,l3,l4,m1,m2,m3,m4;

    /*Fazendo o Runge-kutta de quarta ordem*/
    for(i=0;i<N;i++)
    {
        /*Condições Iniciais*/
        T[0] = 0.00;
        X[0] = 1.00;
        Y[0] = 2.00;
        Z[0] = 6.00;

        /*Valor de k1, l1 e m1*/
        k1 = h*fx(X[i],Y[i],Z[i]);
        l1 = h*fy(X[i],Y[i],Z[i]);
        m1 = h*fz(X[i],Y[i],Z[i]);

        /*Valor de k2, l2 e m2*/
        k2 = h*fx((X[i] + (k1*0.5)), (Y[i] + (l1*0.5)), (Z[i] + (m1*0.5)));
        l2 = h*fy((X[i] + (k1*0.5)), (Y[i] + (l1*0.5)), (Z[i] + (m1*0.5)));
        m2 = h*fz((X[i] + (k1*0.5)), (Y[i] + (l1*0.5)), (Z[i] + (m1*0.5)));

        /*Valor de k3, l3 e m3*/
        k3 = h*fx((X[i] + (k2*0.5)), (Y[i] + (l2*0.5)), (Z[i] + (m2*0.5)));
        l3 = h*fy((X[i] + (k2*0.5)), (Y[i] + (l2*0.5)), (Z[i] + (m2*0.5)));
        m3 = h*fz((X[i] + (k2*0.5)), (Y[i] + (l2*0.5)), (Z[i] + (m2*0.5)));

        /*Valor de k4, l4 e m4*/
        k4 = h*fx((X[i] + k3), (Y[i] + l3), (Z[i] + m3));
        l4 = h*fy((X[i] + k3), (Y[i] + l3), (Z[i] + m3));
        m4 = h*fz((X[i] + k3), (Y[i] + l3), (Z[i] + m3));

        /*Adicionando os valores nos vetores*/
        X[i+1] = X[i] + ((k1 + 2*k2 + 2*k3 + k4)/6);
        Y[i+1] = Y[i] + ((l1 + 2*l2 + 2*l3 + l4)/6);
        Z[i+1] = Z[i] + ((m1 + 2*m2 + 2*m3 + m4)/6);
        T[i+1] = T[i] + h;
      }

    /*Coloando esses dados numa unica matriz*/
    float RungeK[N][4];
    for(i=0;i<N;i++)
    {
        RungeK[i][0] = T[i];
        RungeK[i][1] = X[i];
        RungeK[i][2] = Y[i];
        RungeK[i][3] = Z[i];
    }
    printf("Verificando os valores da matriz:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<4;j++)
        {
            printf(" %f ",RungeK[i][j]);
        }
        printf("\n");
    }

    FILE *saida;
    saida = fopen("Runge-kutta-teste.dat","w");
    for(i=0;i<N;i++)
    {
        for(j=0;j<4;j++)
        {
            fprintf(saida," %f ",RungeK[i][j]);
        }
        fprintf(saida,"\n");
    }
    fclose(saida);
}


