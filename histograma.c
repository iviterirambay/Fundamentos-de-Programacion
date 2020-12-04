/*
*	Archivo: histograma.c
*	Autor: Freddy Orosco
*	Descripcion:	Hacer un programa que pida al usuario ingresar diez datos de una encuesta destro
*								de un arreglo y finalmente presentar su respectivo histograma.
*/

#include <stdio.h>
#define TAM 10

void main()
{
	int num[TAM]={0};
	int i,j,datos;
	for(i=0;i<TAM;i++)
	{
		printf("Ingrese el dato #%d de su encuesta:",i+1);
		scanf("%d",&datos);
		num[i]=datos;
	}	
	printf("\nElemento\tValor\tHistograma\n");
	for(i=0;i<TAM;i++)
	{
		printf("   %d      \t  %d\t",i+1,num[i]);
		for(j=1;j<=num[i];j++)
		{
			printf("%c",'*');
		}
		printf("\n");
	}
	getch();
}