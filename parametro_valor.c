/*
*	Archivo: Paso_Referencia_Valor.c
*	Descripcion:	Hacer un programa para poder visualizar, paso por referencia y paso
*								por valor.
*/

#include <stdio.h>
#define TAMANIO 5

void modificarArreglo(int b[],int tamanio);
void modificarElemento(int ele);

void main()
{
	int a[TAMANIO]={0,1,2,3,4},i;
	printf("Efectos de Pasar arreglos completos por referencia\n");
	for(i=0;i<TAMANIO;i++)
	{
		printf("%3d",a[i]);
	}
	printf("\n");
	modificarArreglo(a,TAMANIO);
	printf("Los valores del arreglo modificado son:\n");
	for(i=0;i<TAMANIO;i++)
	{
		printf("%3d",a[i]);
	}
	printf("\n\n\nEfectos de pasar un elemento del arreglo por valor:\n\nEl valor de a[3] es %d\n",a[3]);
	modificarElemento(a[3]);
	printf("El valor de a[3] es %d\n",a[3]);
	getch();
}

void modificarArreglo(int b[],int tamanio)
{
	int j;
	for(j=0;j<tamanio;j++)
	{
		b[j]*=2;
	}
}
void modificarElemento(int ele)
{
	printf("El valor de Modificar Elemento es %d\n",ele*=2);
}
