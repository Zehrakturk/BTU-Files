#include <stdio.h>

int main(void)
{
  int a,day;

  printf("Bir sayi giriniz:\n");
  scanf("%d", &a);

	day=a%7;
  	switch (day) {

    case 1:
      printf("Sectiginiz gun pazartesi ");
      	break;
    case 2:
      printf("Sectiginiz gun sali ");
      	break;
    case 3:
      printf("Sectiginiz gun carsamba ");
    	break;
	case 4:
      printf("Sectiginiz gun persembe ");
    	break;
	case 5:
      printf("Sectiginiz gun cuma ");
    	break;
	case 6:
      printf("Sectiginiz gun cumartesi ");
    	break;
	case 0:
      printf("Sectiginiz gun pazar ");
    	break;
  }
}





