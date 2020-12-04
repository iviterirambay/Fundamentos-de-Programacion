/*
*	Archivo: calcular_edad.c
*	Autor: Freddy Orosco	
*	Descripcion:	Hacer  un  Programa que pida al usuario  ingresar  el año  de nacimiento
*								de una persona, Con dicho año calcular la edad de la persona y presentar
*								el valor en pantalla.
*/

#include <stdio.h>

void main()
{
	int anio,edad;
	printf("Ingrese el a%co de nacimiento de la persona:",420);
	scanf("%d",&anio);
	if(anio>=1900 && anio<=2010)//Verifica si el año ingresado esta de acuerdo a la epoca
	{
		edad=2010-anio;//Calculo para determinar la edad
		printf("La edad de la persona es:%d a%cos",edad,420);//Presenta la edad
	}
	else
		printf("El a%co es invalido",420);//Si la condicion no se cumple presenta este mensaje
	getch();
}