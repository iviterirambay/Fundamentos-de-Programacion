/*
*	Archivo: funcion_suma.c
*	Autor: Freddy Orosco
*	Descripcion:	Hacer una funcion suma que reciva como parametros tres numeros enteros,
*								Luego de esto presentar en pantalla dicha suma.
*/

#include <stdio.h>

int sumar(int numero1,int numero2); 

void main()
{
	int num1,num2,num3,suma=0;
	printf("Ingrese un numero:");
	scanf("%d",&num1);
	printf("Ingrese otro numero:");
	scanf("%d",&num2);
	printf("Ingrese otro numero:");
	scanf("%d",&num3);
	suma=sumar(num1,num2,num3);//Uso de Funcion
	printf("La suma es: %d",suma);
	getch();
}

int sumar(int numero1,int numero2,int numero3)//funcion que recibe dos parametro de tipo entero
{
	int suma=0;
	suma=numero1+numero2+numero3;
	return suma;
}