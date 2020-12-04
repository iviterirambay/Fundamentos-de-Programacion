/*
*	Archivo: multiplo_par_impar.c
* Autor: Freddy Orosco
*	Descripcion:  Hacer  un Programa que pida al usuario ingresar un número, comprobar si el
*								numero ingresado es multiplo de algun numero ingresado tambien por teclado
*               y si lo es indique si es par o impar.
*/

#include <stdio.h>

void main()
{
	int num1, num2;
	printf("Ingrese un numero: ");
	scanf("%d",&num1);
	printf("Ingrese un multiplo a verificar: ");
	scanf("%d",&num2);
	if(num1%num2==0)
	{
		if(num1%2==0)
			printf("El %d es un numero PAR y multiplo de %d\n",num1,num2);
		else
			printf("El %d es un numero IMPAR y multiplo de %d\n",num1,num2);
	}
	else
	{
		printf("El %d no es un multiplo de %d\n",num1,num2);
	}
	getch();
}