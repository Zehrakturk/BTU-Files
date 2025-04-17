#include <stdio.h>
#include <stdlib.h>
void kelimebul(char a[],char b[],int poz1,int poz2,int sayac)
{
    poz1=0;
    poz2=0;
    if(sayac==strlen(b))
        return 1;
    else if(a[poz1]==b[poz2] && (poz1<strlen(a)&& poz2<strlen(b)))
    {
        return kelimebul(a,b,poz1+1,poz2+1,sayac+1);
    }
    else if(a[poz1]!=b[poz2]&& (poz1<strlen(a)&& poz2<strlen(b)))
    {
        return kelimebul(a,b,poz1+1,0,0);
    }
    else
        return 0;

}
int main()
{
    char a={'m','e','r','h','a','b','a'};
    char b={'a','b','a'};

}
