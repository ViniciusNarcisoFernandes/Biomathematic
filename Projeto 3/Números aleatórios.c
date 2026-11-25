#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
    /*Variáveis e vetores*/
    int i;
    int num[10];

    /*Semente para a variação de número*/
    srand(time(NULL));

    for(i=0;i<10;i++)
    {
        num[i] = rand();
    }
    printf("\n");
    for(i=0;i<10;i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n\n");
}
