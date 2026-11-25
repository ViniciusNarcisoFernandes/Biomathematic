#include<stdio.h>
#include<math.h>

/*Parametros*/
#define H 10000
#define n 0.01
#define a 1
#define K 1000000
#define r 0.2
#define nbmb -0.33
#define e 10
#define pi 3.14

/*Suscetíveis variando a*/
float fSa(float T,float S,float I, float B, float lambda)
{
    return (n*(H-S)-(0.5 + 0.5*sin(2*pi*T/365))*lambda*S);
}

/*Infectados variando a*/

float fIa(float T,float S, float I, float B, float lambda)
{
    return ((0.5 + 0.5*sin(2*pi*T/365))*lambda*S-r*I);
}

/*Concentracao de toxigenico*/
float fB(float S, float I, float B)
{
    return (B*nbmb + e*I);
}

main()
{
    int i,j,h = 1,N=366;
    float Ta[N],Sa[N],Ia[N],Ba[N],La[N];
    float k1,k2,k3,k4,l1,l2,l3,l4,m1,m2,m3,m4;

    /*Fazendo o Runge-kutta de quarta ordem*/
    for(i=0;i<N;i++)
    {
        /*Condições Iniciais*/
        Ta[0] = 0;
        Sa[0] = H;
        Ia[0] = 30;
        Ba[0] = 5;

        /*Valor de lambda = dose logistica*/
        La[i] = Ba[i]/(K+Ba[i]);

        /*Valor de k1, l1 e m1*/
        k1 = h*fSa(Ta[i],Sa[i],Ia[i],Ba[i],La[i]);
        l1 = h*fIa(Ta[i],Sa[i],Ia[i],Ba[i],La[i]);
        m1 = h*fB(Sa[i],Ia[i],Ba[i]);

        /*Valor de k2, l2 e m2*/
        k2 = h*fSa((Ta[i] + (0.5*h)),(Sa[i] + (k1*0.5)), (Ia[i] + (l1*0.5)), (Ba[i] + (m1*0.5)),La[i]);
        l2 = h*fIa((Ta[i] + (0.5/h)),(Sa[i] + (k1*0.5)), (Ia[i] + (l1*0.5)), (Ba[i] + (m1*0.5)),La[i]);
        m2 = h*fB((Sa[i] + (k1*0.5)), (Ia[i] + (l1*0.5)), (Ba[i] + (m1*0.5)));

        /*Valor de k3, l3 e m3*/
        k3 = h*fSa((Ta[i] + (0.5*h)),(Sa[i] + (k2*0.5)), (Ia[i] + (l2*0.5)), (Ba[i] + (m2*0.5)),La[i]);
        l3 = h*fIa((Ta[i] + (0.5*h)),(Sa[i] + (k2*0.5)), (Ia[i] + (l2*0.5)), (Ba[i] + (m2*0.5)),La[i]);
        m3 = h*fB((Sa[i] + (k2*0.5)), (Ia[i] + (l2*0.5)), (Ba[i] + (m2*0.5)));

        /*Valor de k4, l4 e m4*/
        k4 = h*fSa((Ta[i] + h),(Sa[i] + k3), (Ia[i] + l3), (Ba[i] + m3),La[i]);
        l4 = h*fIa((Ta[i] + h),(Sa[i] + k3), (Ia[i] + l3), (Ba[i] + m3),La[i]);
        m4 = h*fB((Sa[i] + k3), (Ia[i] + l3), (Ba[i] + m3));

        /*Adicionando os valores nos vetores*/
        Sa[i+1] = Sa[i] + ((k1 + 2*k2 + 2*k3 + k4)/6);
        Ia[i+1] = Ia[i] + ((l1 + 2*l2 + 2*l3 + l4)/6);
        Ba[i+1] = Ba[i] + ((m1 + 2*m2 + 2*m3 + m4)/6);
        Ta[i+1] = Ta[i] + h;
      }


    /*colocando a comunidade SC*/
    float Sc[N];
    for(i=0;i<N;i++)
    {
        Sc[i] = 6600;
    }

    /*Coloando esses dados numa unica matriz*/
    float RungeK[N][5];
    for(i=0;i<N;i++)
    {
        RungeK[i][0] = Ta[i];
        RungeK[i][1] = Sa[i];
        RungeK[i][2] = Ia[i];
        RungeK[i][3] = Ba[i];
        RungeK[i][4] = Sc[i];
    }
    printf("Valores:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("   %f   ",RungeK[i][j]);
        }
        printf("\n");
    }

    FILE *saida;
    saida = fopen("Comunidade3-a.dat","w");
    for(i=0;i<N;i++)
    {
        for(j=0;j<5;j++)
        {
            fprintf(saida," %f ",RungeK[i][j]);
        }
        fprintf(saida,"\n");
    }
    fclose(saida);

}
