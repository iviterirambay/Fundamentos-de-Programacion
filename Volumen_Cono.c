/*
*	Archivo: Volumen_Cono.c
* Autor:   Freddy Orosco
*	Descripcion: Hacer un programa que ingrese por teclado el radio y la altura 
*				       de un Cono. Calcular el Volumen del Cono.
*				       Declarar como Constante PI con valor 3.1416
*/

#include <stdio.h> 
#define PI 3.1416 

void main()
{
	//Variables
	int radio,altura;
	float volumen=0;

	printf("Ingrese el radio del Cono:");
	scanf("%d",&radio);
	printf("Ingrese la altura del Cono:");
	scanf("%d",&altura);
	volumen=(PI*radio*radio*altura)/3;//Formula para encontrar el volumen de un cono
	printf("El volumen del Cilindro es :%.2f",volumen);
	getch();
}