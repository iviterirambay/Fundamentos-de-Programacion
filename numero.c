/*
*	Archivo: numero.c
* Autor: Freddy Orosco
*	Descripcion:  Hacer un Programa que pida al usuario ingresar un n�mero,comprobar si el
*								n�mero ingresado es cero, mayor o menor a cero, presentar en pantalla
*								dicho resultado.
*/

#include <stdio.h>

void main()
{
	int num;
	printf("Ingrese un numero:");
	scanf("%d",&num);
	if(num==0)
		printf("El numero Ingresado es \"CERO\"");
	if(num>0)
		printf("El %d es un numero MAYOR a cero\n",num);
	if(num<0)
		printf("El %d es un numero MENOR a cero\n",num);
	
	getch();
}