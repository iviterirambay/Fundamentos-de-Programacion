/*
*	Archivo: Arreglo.c
*	Autor: Viteri Rambay Irwin Alberto
*	Fecha de creaci�n: 25/Junio/2010
*	Descripci�n:
*		Programa que utiliza los procedimientos llenarArreglo y mostrarArreglo.
*		Los procedimientos reciben como par�metro un arreglo de enteros y el
*		tama�o de dichos arreglos.
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
*	Descripci�n:
*		Este procedimiento llena el arreglo enviado como par�metro con n�meros aleatorios
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
*	Descripci�n:
*		Este procedimiento muestra por pantalla el contenido del arreglo
*		enviado como par�metro. Muestra cada elemento en una l�nea diferente.
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
*	Descripci�n:
*		Este procedimiento multiplica el valor de mi arrego enviado como par�metro con n�meros aleatorios
*		entre 1 y 6 por el numero que el usuario ingrese.
*/

void multiplicarArreglo(int A[],int tam, int valor)
{
int i;
for(i=0;i<tam;i++)

A[i]=A[i]*valor;

}