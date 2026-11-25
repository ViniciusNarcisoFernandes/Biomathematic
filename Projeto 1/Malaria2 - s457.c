#include<stdio.h>
#include<math.h>

main()
{
    FILE *file1;
    file1 = fopen("s457.dat","r");
    int i,j,N=62;
    float Dados1[N][2];

    /*lendo o arquivo*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<2;j++)
        {
            fscanf(file1,"%f",&Dados1[i][j]);
        }
    }
    fclose(file1);

    /*Aplicando log10 aos dados*/
    float DadosLogY[N][2];
    for(i=0;i<N;i++)
    {
        DadosLogY[i][0] = Dados1[i][0];
        DadosLogY[i][1] = log10(Dados1[i][1] + 1);
    }

    /*Dados de saída para o logaritmo*/
    FILE *saida;
    saida = fopen("s457-Log.dat","w");
    for(i=0;i<N;i++)
    {
        for(j=0;j<2;j++)
        {
            fprintf(saida," %f ",DadosLogY[i][j]);
        }
        fprintf(saida,"\n");
    }
    fclose(saida);

    /*Aplicando a interpolacao*/
    for(i=1;i<(N-1);i++)
    {
        if(DadosLogY[i][1] == 5.000000)
        {
            DadosLogY[i][1] = DadosLogY[i-1][1] + ((DadosLogY[i+1][1]-DadosLogY[i-1][1])/
                                                     DadosLogY[i+1][0]-DadosLogY[i-1][0])*
                                                     (DadosLogY[i][0]-DadosLogY[i-1][0]);

        }
    }

    /*Salvando os arquivos em log e interpolados*/
    FILE *arquivo_saida1;
    arquivo_saida1 = fopen("s457-Interpolados.dat","w");
    for(i=0;i<N;i++)
    {
        for(j=0;j<2;j++)
        {
            fprintf(arquivo_saida1," %f ",DadosLogY[i][j]);
        }
        fprintf(arquivo_saida1,"\n");
    }
    fclose(arquivo_saida1);

    /*Numero de maximos locais*/
    float numero_maximo = 0;
    for(i=3;i<(N-3);i++)
    {
        if(DadosLogY[i][1] > DadosLogY[i-3][1] &&
           DadosLogY[i][1] > DadosLogY[i-2][1] &&
           DadosLogY[i][1] > DadosLogY[i-1][1] &&
           DadosLogY[i][1] > DadosLogY[i+1][1] &&
           DadosLogY[i][1] > DadosLogY[i+2][1] &&
           DadosLogY[i][1] > DadosLogY[i+3][1])
        {
            numero_maximo = numero_maximo + 1;
        }
    }
    printf("\nO numero de maximos locais e:%f\n",numero_maximo);

    /*Posicao e valor do primeiro maximo*/
    float posicao_local,valor_local;
    for(i=3;i<(N-3);i++)
    {
        if(DadosLogY[i][1] > DadosLogY[i-3][1] &&
           DadosLogY[i][1] > DadosLogY[i-2][1] &&
           DadosLogY[i][1] > DadosLogY[i-1][1] &&
           DadosLogY[i][1] > DadosLogY[i+1][1] &&
           DadosLogY[i][1] > DadosLogY[i+2][1] &&
           DadosLogY[i][1] > DadosLogY[i+3][1])
        {
            valor_local = DadosLogY[i][1];
            posicao_local = DadosLogY[i][0];
            break;
        }
    }
    printf("\nA posicao e: %f  e valor do primeiro maximo e:%f \n",posicao_local,valor_local);

    /*Posicao e valor do maximo global*/
    float posicao_global,valor_global = 0;
    for(i=0;i<N;i++)
    {
        if(DadosLogY[i][1] > valor_global)
        {
            valor_global = DadosLogY[i][1];
            posicao_global = DadosLogY[i][0];
        }
    }
    printf("\nA posicao global:%f, O valor global:%f\n",posicao_global,valor_global);

    /*tamanho da serie*/
    float primeiro_dia_positivo, ultimo_dia_positivo;
    for(i=0;i<N;i++)
    {
        if(DadosLogY[i][1] > 1)
        {
            primeiro_dia_positivo = DadosLogY[i][0];
            break;
        }
    }
    printf("\nO primeiro dia positivo e:%f\n",primeiro_dia_positivo);

    for(i=0;i<N;i++)
    {
        if(DadosLogY[i][1] > 1)
        {
            ultimo_dia_positivo = DadosLogY[i][0];
        }
    }
    printf("\nO ultimo dia positivo e:%f\n",ultimo_dia_positivo);

    float tamanho_da_serie;
    tamanho_da_serie = ultimo_dia_positivo - primeiro_dia_positivo;
    printf("\nO tamanho da serie e:%f\n",tamanho_da_serie);

    /*Proporcao de observacoes positivas*/
    float primeira_metade = ((tamanho_da_serie + 1)*0.5),cont1 = 0,cont2 = 0,proporcao1;
    for(i=primeiro_dia_positivo;i<=primeira_metade;i++)
    {
        if(DadosLogY[i][1] > 1)
        {
            cont1 = cont1 + 1;
        }
    }
    proporcao1 = cont1/tamanho_da_serie;
    printf("\nA proporcao na primeira metade e: %f\n",proporcao1);

    /*Proporcao de observacoes da segunda metade*/
    for(i=(primeira_metade+1);i<=ultimo_dia_positivo;i++)
    {
        if(DadosLogY[i][1] > 1)
        {
            cont2 = cont2 + 1;
        }
    }
    float proporcao2;
    proporcao2 = cont2/tamanho_da_serie;
    printf("\nA proporcao de observacoes na segunda metade e: %f\n",proporcao2);

    /*Suavizacao da curva*/
    float z[N][2];
    for(i=0;i<N;i++)
    {
        z[i][0] = DadosLogY[i][0];
        z[i][1] = (DadosLogY[i-1][1]+DadosLogY[i][1]+DadosLogY[i+1][1])/3;
    }

    /*Salvan os dados suavizados*/
    FILE *arquivo_saida2;
    arquivo_saida2 = fopen("s457-suavizado.dat","w");
    for(i=0;i<N;i++)
    {
        for(j=0;j<2;j++)
        {
            fprintf(arquivo_saida2," %f ",z[i][j]);
        }
        fprintf(arquivo_saida2,"\n");
    }
    fclose(arquivo_saida2);

    /*Inclinacao da reta*/
    float Xmed = 0, Ymed = 0,Xmedia,Ymedia;
    for(i=primeiro_dia_positivo;i<=posicao_local;i++)
    {
        Xmed = Xmed + DadosLogY[i][0];
        Ymed = Ymed + DadosLogY[i][1];
    }
    Xmedia = Xmed/(posicao_local-primeiro_dia_positivo);
    Ymedia = Ymed/(posicao_local-primeiro_dia_positivo);
    float SXX = 0,SXY = 0,beta1;
    for(i=primeiro_dia_positivo;i<=posicao_local;i++)
    {
        SXX = SXX + ((DadosLogY[i][0] - Xmedia)*(DadosLogY[i][0] - Xmedia));
        SXY = SXY + ((DadosLogY[i][0] - Xmedia)*(DadosLogY[i][1] - Ymedia));
    }
    beta1 = SXY/SXX;
    printf("\nA inclincao da regressao linear e:%f\n",beta1);

    /*Calculo da integral*/
    float Trapezio = 0,h=1;
    for(i=1;i<(N-1);i++)
    {
        Trapezio = Trapezio + ((h/2)*(DadosLogY[i-1][1] + DadosLogY[i][1]));
    }
    printf("\nA integral da minha area e: %f\n",Trapezio);

    /*Correlacao cruzada das variaveis - sexuada e assexuada*/

    FILE *arquivo_import;
    arquivo_import = fopen("s457-s457a.dat","r");
    float Dados_cor[N][3];
    for(i=0;i<N;i++)
    {
        for(j=0;j<3;j++)
        {
          fscanf(arquivo_import,"%f",&Dados_cor[i][j]);
          printf(" %f ",Dados_cor[i][j]);
        }
        printf("\n");
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
    printf("\nMedia do valores de x e de y:%f %f\n",mediaX,mediaY);

    /*Calculando o sigmax e sigmay*/
    float sigmaX = 0, sigmaY = 0;
    for(i=0;i<N;i++)
    {
        sigmaX = sigmaX + ((Dados_cor[i][1] - mediaX)*(Dados_cor[i][1]-mediaX));
        sigmaY = sigmaY + ((Dados_cor[i][2] - mediaY)*(Dados_cor[i][2]-mediaY));
    }
    printf("\n%f %f\n",sigmaX,sigmaY);

    /*Fazendo o delay*/
    int d;
    float sigmaXY, r[20];
    for(d=0;d<=19;d++)
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
    /*FILE *arquivo_saida3;
    arquivo_saida3  = fopen("s457-s457a - delay.dat","w");
    for(d=0;d<=10;d++)
    {
        fprintf(arquivo_saida3," %f ",r[d]);
    }
    fclose(arquivo_saida3);*/

}

