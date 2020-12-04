/*
*	Archivo: par_impar.c
* Autor: Freddy Orosco
*	Descripcion:  Hacer  un Programa que pida al usuario ingresar un número, comprobar si 
*								el numero ingresado es par o impar.
*/

#include <stdio.h>

void main()
{
	int num;
	printf("Ingrese un numero: ");
	scanf("%d",&num);
	if(num%2==0)
	{
		printf("El %d es un numero PAR\n", num);
	}
	else
	{
		printf("El %d es un numero IMPAR\n", num);
	}
	getch();
}
