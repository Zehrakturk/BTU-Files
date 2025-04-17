#include <stdio.h>
#include <stdlib.h>

int main()
 {
     int i,j;
     int N=1;
     printf("%4c\t", 'N');

     for(int j = 10 ; j <= 1000;)
     {
         printf("%4d*N\t", j);
         j*=10;
     }
     printf("\n\n");

     for(i = 1 ; i <= 10 ; i++)
     {
         printf("%4d\t", i);
         for(j = 1 ; j <= 100 ;)
         {
             j*=10;
             printf("%4d\t", i*j);
         }
         printf("\n");
     }

 }
