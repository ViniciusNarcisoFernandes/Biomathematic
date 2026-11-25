#include<stdio.h>
#include<math.h>

main()
{
    /*Sexuada*/
    FILE *fileS;
    fileS = fopen("s731.dat","r");
    int i,j,Ns = 70;
    float DadosS[Ns][2];
    for(i=0;i<Ns;i++)
    {
        for(j=0;j<2;j++)
        {
            fscanf(fileS,"%f",&DadosS[i][j]);
        }
    }
    fclose(fileS);

    /*Passando para logY*/
    float DadosLogYS[Ns][2];
    for(i=0;i<Ns;i++)
    {
        DadosLogYS[i][0] = DadosS[i][0];
        DadosLogYS[i][1] = log10(DadosS[i][1] + 1);
    }

    /*Aplicando a interpolacao*/
    for(i=1;i<(Ns-1);i++)
    {
        if(DadosLogYS[i][1] == 5.000000)
        {
            DadosLogYS[i][1] = DadosLogYS[i-1][1] + ((DadosLogYS[i+1][1]-DadosLogYS[i-1][1])/
                                                     DadosLogYS[i+1][0]-DadosLogYS[i-1][0])*
                                                     (DadosLogYS[i][0]-DadosLogYS[i-1][0]);

        }
    }
    /*Dados sexuados*/
    int n = 103, soma = 70;
    for(i=0;i<n;i++)
    {
        if(i >= 70)
        {
            DadosLogYS[i][0] = i+1;
            DadosLogYS[i][1] = 0;
        }
    }
    printf("\nOs novos dados sexuados:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<2;j++)
        {
            printf(" %f ",DadosLogYS[i][j]);
        }
        printf("\n");
    }

    /*Assexuada*/
    FILE *fileA;
    fileA = fopen("s731a.dat","r");

    int Na = 103;
    float DadosA[Na][2];
    for(i=0;i<Na;i++)
    {
        for(j=0;j<2;j++)
        {
            fscanf(fileA,"%f",&DadosA[i][j]);
        }
    }
    fclose(fileA);

    /*Passando para logY*/
    float DadosLogYA[Na][2];
    for(i=0;i<Na;i++)
    {
        DadosLogYA[i][0] = DadosA[i][0];
        DadosLogYA[i][1] = log10(DadosA[i][1] + 1);
    }

    /*Aplicando a interpolacao*/
    for(i=1;i<(Na-1);i++)
    {
        if(DadosLogYA[i][1] == 5.000000)
        {
            DadosLogYA[i][1] = DadosLogYA[i-1][1] + ((DadosLogYA[i+1][1]-DadosLogYA[i-1][1])/
                                                     DadosLogYA[i+1][0]-DadosLogYA[i-1][0])*
                                                     (DadosLogYA[i][0]-DadosLogYA[i-1][0]);

        }
    }
    printf("\nDados assexuados:\n");
    for(i=0;i<Na;i++)
    {
        for(j=0;j<2;j++)
        {
            printf(" %f ",DadosLogYA[i][j]);
        }
        printf("\n");
    }
    /*Juntando os dados*/
    printf("\n");
    float DadosC[Na][3];
    for(i=0;i<Na;i++)
    {
        DadosC[i][0] = DadosLogYS[i][0];
        DadosC[i][1] = DadosLogYS[i][1];
        DadosC[i][2] = DadosLogYA[i][1];
    }

    /*Correlacao*/
    FILE *arquivo_saida;
    arquivo_saida = fopen("s731-s731a.dat","w");
    for(i=0;i<Na;i++)
    {
        for(j=0;j<3;j++)
        {
            fprintf(arquivo_saida," %f ",DadosC[i][j]);
        }
        fprintf(arquivo_saida,"\n");
    }
    fclose(arquivo_saida);
}
