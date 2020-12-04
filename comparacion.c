/*
*	Archivo: comparacion.c
* Autor: Freddy Orosco
*	Descripcion:  Hacer un Programa que pida al usuario ingresar dos numeros, comprobar cual 
*								numero es el mayor o comprobar si los numeros ingresados son iguales.
*/

#include <stdio.h>

void main()
{
	int num1,num2;
	printf("Ingrese el primer numero: ");
	scanf("%d",&num1);
	printf("Ingrese el segundo numero: ");
	scanf("%d",&num2);
	if(num1>num2)
		printf("El mayor es:%d\n",num1);
	else
	{
		if(num2>num1)
			printf("El mayor es:%d\n",num2);
		else
		printf("Los numeros son iguales");
	}
	getch();
}