/*
*	Archivo: Arreglo.c
*	Autor: Viteri Rambay Irwin Alberto
*	Fecha de creación: 25/Junio/2010
*	Descripción:
*		Programa que utiliza los procedimientos llenarArreglo y mostrarArreglo.
*		Los procedimientos reciben como parámetro un arreglo de enteros y el
*		tamaño de dichos arreglos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define MAX 50

void llenarArreglo(int A[],int tam);
void mostrarArreglo(int A[],int tam);
void multiplicarArreglo(int A[],int tam,int valor);

void main()
{
	int valor;
	int A[MAX];
	srand(time(NULL));
	llenarArreglo(A,MAX);
	mostrarArreglo(A,MAX);
	printf("Ingrese un numero positivo:");
	scanf("%d",&valor);
    multiplicarArreglo(A,MAX,valor);
	mostrarArreglo(A,MAX);

	getch();

}

/*
*	Procedimiento: llenarArreglo
*	Uso: llenarArreglo(A,MAX);
*	Descripción:
*		Este procedimiento llena el arreglo enviado como parámetro con números aleatorios
*		entre 1 y 6.
*/
void llenarArreglo(int A[],int tam)
{
    int i;
	for(i=0;i<tam;i++)
	{
		A[i]=1+(rand()%6);
	}
}



/*
*	Procedimiento: mostrarArreglo
*	Uso: mostrarArreglo(A,MAX);
*	Descripción:
*		Este procedimiento muestra por pantalla el contenido del arreglo
*		enviado como parámetro. Muestra cada elemento en una línea diferente.
*/
void mostrarArreglo(int A[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
		printf("%d \n",A[i]);
	
}

/*
*	Procedimiento: multiplicar arreglo
*	Uso: multiplicar arreglo(A,MAX,valor);
*	Descripción:
*		Este procedimiento multiplica el valor de mi arrego enviado como parámetro con números aleatorios
*		entre 1 y 6 por el numero que el usuario ingrese.
*/

void multiplicarArreglo(int A[],int tam, int valor)
{
int i;
for(i=0;i<tam;i++)

A[i]=A[i]*valor;

}