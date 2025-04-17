#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void yazdir(int n,...)
{
    va_list listem;
    va_start(listem,n);
    for(int i=0;i<n;i++)
    {
        printf("%c",va_arg(listem,int));
    }
    va_end(listem);
}
int main()
{
    /*esnek argümanlý fonksiyon[ int topla(int ,...)]
    uc nokta n sayýda eleman girilebilir i iafe eder.
    Ve bazen 2 bazen 3 zaman zaman farklý sayýda parametre alabilir.
    va_list: veri tipi va_star(list,n): veri listesini baslatir
    va_arg(list,int): listeden int degerlikli veriyi cek va_end(list):listeyi bellekten temizle. */

    yazdir(5,'b','u','r','s','a');
    printf("\n");
    yazdir(3,'b','t','u');
}
