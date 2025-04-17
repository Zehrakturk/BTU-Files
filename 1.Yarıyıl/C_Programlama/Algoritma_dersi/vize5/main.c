#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j,k,m,sayac=0,boyut;
    char X[13][10] = { "harbi", "bitik", "ferah", "define", "alman", "yaban", "sanal", "okutman",
                       "enerjik", "balistik", "toparlak", "algoritma", "karbonlu"
                     };
    char Y[14][10] = { "efendi", "portakal", "jenerik", "komutan", "bitki", "aslan", "ihbar", "baronluk",
                       "bayan", "logaritma", "refah", "basitlik", "anlam", "sabitlik"};

    for(k=0; k<13; k++)
    {
        for(m=0; m<14; m++)
        {
            if(strlen(X[k])==strlen(Y[m]))
            {
                int sayac=0;
                for(i=0; i<strlen(X[k]); i++)
                {
                    for(j=0; j<strlen(Y[m]); j++)
                    {
                        if(X[i]==Y[j])
                        {
                            sayac+=1;printf("a");
                            Y[m][j]='-';
                            break;
                        }
                    }
                }
                if(sayac==strlen(X[k]))
                    printf("%s ile %s anagramdir",X[k],Y[m]);

            }
        }

/*
  for(i=0;i<14;i++)
    {
        for(j=0;j<10;)
        {
            for(k=j;k<strlen(X[i][j]);k++)
                if(X[i][j]==Y[i][k])
                j++;
        }
    }
                       };

    boyut=strlen(X[i][j]);
    for(i=0;i<14;i++)
    {
        for(j=0;j<10;j++)
        {

            if('X[i][j]'=='Y[i][j]')
            {
                sayac++;
            }
            if(sayac==strlen(X[i]))
            {
                for(int k=0;k<strlen(X[i]);k++)
                {
                    for(int m=0;m<strlen(Y[i]);m++)
                    {
                        sayac++;
                    }
                }
            }
            if(sayac==strlen(Y[j]))
            {
                printf("%s ile %s anagramdir.\n",X[i],Y[j]);
            }
        }
    }




  for(i=0;i<14;i++)
    {
        for(j=0;j<10;)
        {
            for(k=j;k<strlen(X[i][j]);k++)
                if(X[i][j]==Y[i][k])
                j++;
        }
    }
                       };

    boyut=strlen(X[i][j]);
    for(i=0;i<14;i++)
    {
        for(j=0;j<10;j++)
        {

            if('X[i][j]'=='Y[i][j]')
            {
                sayac++;
            }
            if(sayac==strlen(X[i]))
            {
                for(int k=0;k<strlen(X[i]);k++)
                {
                    for(int m=0;m<strlen(Y[i]);m++)
                    {
                        sayac++;
                    }
                }
            }
            if(sayac==strlen(Y[j]))
            {
                printf("%s ile %s anagramdir.\n",X[i],Y[j]);
            }
        }
    }*/


}}
