/*
*	Archivo: Arreglo.c
*	Autor: V.Cedeno
*	Fecha de creación: 2010-06-25
*	Descripción:
*		Programa que utiliza los procedimientos llenarArreglo, mostrarArreglo y multiplicarArreglo.
*		Los procedimientos reciben como parámetro un arreglo de enteros y el
*		tamaño de dichos arreglos.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

//Prototipos
void llenarArreglo(int A[], int tamanio);
void mostrarArreglo(int A[], int tamanio);
void multiplicarArreglo(int A[], int tamanio, int valor);


void main()
{
	int x,i;
	int A[MAX];

	srand(time(NULL));
	
	llenarArreglo(A,MAX);
	mostrarArreglo(A,MAX);
	printf("\nSe mostrara el arreglo multiplicado por 2:\n");
	multiplicarArreglo(A,MAX,2);
	mostrarArreglo(A,MAX);
	getch();
}

/*	Procedimiento: llenarArreglo
*	Uso: llenarArreglo(A,MAX);
*	Descripción:
*		Almacena valores aleatorios entre 1 y 6 en el arreglo enviado como parámetro.
*/
void llenarArreglo(int A[], int tamanio)
{
	int i;
	for(i=0;i<tamanio;i++)
		A[i]=1+(rand()%6);
	return;
}

/*	Procedimiento: mostrarArreglo
*	Uso: mostrarArreglo(A,MAX);
*	Descripción:
*		Muestra por pantalla los valores almacenados en el arreglo enviado como parámetro.
*		Los muestra un valor en cada línea.
*/
void mostrarArreglo(int A[], int tamanio)
{
	int i;	
	for(i=0;i<tamanio;i++)
		printf("%d\n",A[i]);
}

/*	Procedimiento: multiplicarArreglo
*	Uso: multiplicarArreglo(A,MAX,valor);
*	Descripción:
*		Multiplica todos los valores del arreglo A por el valor enviado
*		como parámetro.
*/
void multiplicarArreglo(int A[], int tamanio, int valor)
{
	int i;
	for(i=0;i<tamanio;i++)
	{
		A[i] = A[i]*valor;
	}
}