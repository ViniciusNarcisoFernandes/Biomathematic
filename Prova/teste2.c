#include<stdio.h>

main()
{
    float a=0,b=1,somaA1=0,somaA2=0,N = 100,h, somaA,i;
    h = (b-a)/N;
    for(i=a;i<=b;i=i+h)
    {
        if(i==a || i==b)
        {
            somaA1 = somaA1 + (h/2)*(1.0/(pow(i,2)-4));
        }
        else
        {
            somaA2 = somaA2 + h*(1.0/(pow(i,2)-4));
        }
    }
    somaA = somaA1 + somaA2;
    printf("\nA integral pela regra do trapezio e: %f",somaA);
}
