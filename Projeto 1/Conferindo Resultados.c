#include<stdio.h>
#include<math.h>

main()
{
    /*Correlacao cruzada das variaveis - sexuada e assexuada*/
    int i,j,N =103;
    FILE *arquivo_import;
    arquivo_import = fopen("s731-s731a.dat","r");
    float Dados_cor[N][3];
    for(i=0;i<N;i++)
    {
        for(j=0;j<3;j++)
        {
          fscanf(arquivo_import,"%f",&Dados_cor[i][j]);
        }
    }
    fclose(arquivo_import);

    /*Fazendo a media para X - sexuada*/
    float mediaXs = 0, mediaX, mediaYa = 0, mediaY;
    for(i=0;i<N;i++)
    {
        mediaXs = mediaXs + Dados_cor[i][1];
        mediaYa = mediaYa + Dados_cor[i][2];
    }
    mediaX = mediaXs/N;
    mediaY = mediaYa/N;

    /*Calculando o sigmax e sigmay*/
    float sigmaX = 0, sigmaY = 0;
    for(i=0;i<N;i++)
    {
        sigmaX = sigmaX + ((Dados_cor[i][1] - mediaX)*(Dados_cor[i][1]-mediaX));
        sigmaY = sigmaY + ((Dados_cor[i][2] - mediaY)*(Dados_cor[i][2]-mediaY));
    }

    /*Fazendo o delay*/
    int d;
    float sigmaXY, r[10];
    for(d=0;d<=10;d++)
    {
        sigmaXY = 0;
        for(i=0;i<(N-d);i++)
        {
            sigmaXY = sigmaXY + (Dados_cor[i][2]-mediaY)*(Dados_cor[i+d][1]-mediaX);
        }
        r[d] = sigmaXY/(sqrt(sigmaX*sigmaY));
    }

    printf("\nOs valores do delay:\n");
    for(d=0;d<=10;d++)
    {
        printf(" %f ",r[d]);
    }

    /*Salvando os dados obtidos pelo delay*/
    FILE *arquivo_saida3;
    arquivo_saida3  = fopen("s731-delay.dat","w");
    for(d=0;d<=10;d++)
    {
        fprintf(arquivo_saida3," %f ",r[d]);
    }
    fclose(arquivo_saida3);

}
