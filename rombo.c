/* 
*	Archivo:rombo.c
*	Autor: Freddy Orosco
*	Descripcion:	Elabore un procedimiento que grafique un rombo; para ello 
*								necesitara su altura y un caracter finalmente presentar lo siguiente.
*								Tome en cuenta que la altura de un rombo siempre es un numero impar.
*								altura: 5
*								caracter: $
*								  $
*								 $$$
*								$$$$$
*								 $$$
*									$
*/


#include <stdio.h>
void rombo(int h,char a);
void rombo(int h,char a)
{
	int i,j;
	h=(h+1)/2;
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=h-i;j++)
			printf(" ");
		for(j=1;j<=2*i-1;j++)
			printf("%c",a);
	printf("\n");
	}
	for(i=h-1;i>=1;i--)
	{
		for(j=1;j<=h-i;j++)
			printf(" ");
	for(j=1;j<=2*i-1;j++)
			printf("%c",a);
	printf("\n");
	}
}

void main()
{
	int num;
	char car;
	printf("Ingrese un caracter: ");
	scanf("%c",&car);
	do{
		system("cls");
		printf("Ingrese un caracter:%c\n",car);
		printf("Ingrese la altura del rombo(debe ser un numero impar): ");
		scanf("%d",&num);
	}while(num%2==0);
	rombo(num,car);
	getch();
}