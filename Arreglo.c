/*
*	Archivo: Arreglo.c
*	Autor: V.Cedeno
*	Fecha de creaci�n: 2010-06-25
*	Descripci�n:
*		Programa que utiliza los procedimientos llenarArreglo, mostrarArreglo y multiplicarArreglo.
*		Los procedimientos reciben como par�metro un arreglo de enteros y el
*		tama�o de dichos arreglos.
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
*	Descripci�n:
*		Almacena valores aleatorios entre 1 y 6 en el arreglo enviado como par�metro.
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
*	Descripci�n:
*		Muestra por pantalla los valores almacenados en el arreglo enviado como par�metro.
*		Los muestra un valor en cada l�nea.
*/
void mostrarArreglo(int A[], int tamanio)
{
	int i;	
	for(i=0;i<tamanio;i++)
		printf("%d\n",A[i]);
}

/*	Procedimiento: multiplicarArreglo
*	Uso: multiplicarArreglo(A,MAX,valor);
*	Descripci�n:
*		Multiplica todos los valores del arreglo A por el valor enviado
*		como par�metro.
*/
void multiplicarArreglo(int A[], int tamanio, int valor)
{
	int i;
	for(i=0;i<tamanio;i++)
	{
		A[i] = A[i]*valor;
	}
}