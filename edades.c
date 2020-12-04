/*
*	Archivo: edades.c
*	Autor: Freddy Orosco
*	Descripcion:	Hacer un Programa  que pida  al usuario  ingresar la  edad de una
*								persona(Edad Positiva),Comprobar la edad  y presentar en pantalla 
*               lo siguiente:
*								Si la edad esta entre 0 y 8  :Presentar-> Es niño
*								Si la edad esta entre 9 y 14 :Presentar-> Es Adolescente
*								Si la edad esta entre 15 y 24:Presentar-> Es Joven
*								Si la edad es mayor a 25     :Presentar-> Es Adulto
*/

#include <stdio.h>

void main()
{
	int edad;
	printf("Ingrese la edad de una persona: ");
	scanf("%d",&edad);
	printf("La persona que tiene %d a%cos es considerada : ",edad,164);
	if(edad>=0 && edad<9)//Condición de Niño
		printf("Ni%co",420);
	if(edad>=9 && edad<15)//Condición de Adolescente
		printf("Adolescente");
	if(edad>=15 && edad<25)//Condición de Joven
		printf("Joven");
	if(edad>=25)//Condición de Adulto
		printf("Adulto");
	getch();
}