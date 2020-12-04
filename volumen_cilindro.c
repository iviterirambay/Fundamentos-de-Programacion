/*
*	Archivo:     Volumen_cilindro.c
* Autor: Freddy Orosco
*	Descripcion: Hacer un programa que ingrese por teclado el radio y la altura 
*				       de un Cilindro. Calcular el Volumen del Cilindro.
*				       Declarar como Constante PI con valor 3.1416
*/

#include <stdio.h> 
#define PI 3.1416 

void main()
{
	//Variables
	int radio,altura;
	float volumen;

	printf("Ingrese el radio del Cono:");
	scanf("%d",&radio);
	printf("Ingrese la altura del Cono:");
	scanf("%d",&altura);
	volumen=PI*radio*radio*altura;//Formula para encontrar el volumen de un cilindro
	printf("El volumen del Cilindro es :%.2f",volumen);
	getch();
}