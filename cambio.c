/*
*	Archivo: cambio.c
*	Autor:Freddy Orosco V.
*	Descripcion:	Hacer un programa que pueda cambiar los elementos de un arreglo,
*								que los ordene de forma ascendente.
*/

#include <stdio.h>
#define TAMANIO 10

void main()
{
	int a[TAMANIO]={10,7,90,4,25,12,89,68,45,70};
	int pasadas,i,almacena;
	printf("Elementos de datos en el orden original\n");
	for(i=0;i<TAMANIO;i++)
	{
		printf("%4d",a[i]);
	}
	for(pasadas=1;pasadas<TAMANIO;pasadas++)
	{
		for(i=0;i<TAMANIO-1;i++)
		{
			if(a[i]>a[i+1])
			{
				almacena=a[i];
				a[i]=a[i+1];
				a[i+1]=almacena;
			}
		}
	}
	printf("\nElementos de Datos en orden Ascendente:\n");
	for(i=0;i<TAMANIO;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
	getch();
}