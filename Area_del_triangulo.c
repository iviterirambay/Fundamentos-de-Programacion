/*
*	Archivo: Area_del_Triangulo.c
* Autor: Freddy Orosco
*	Descripcion:  Hacer un programa que ingrese por teclado la base y la altura 
*								de un triangulo rectangulo(considere la opción que los datos
								pueden ser con decimales). Calcular el Area.
*/

#include <stdio.h> 

void main()
{ 
	float base,altura,area=0;

	printf("Ingrese la Base del Triangulo: ");
	scanf("%f",&base);
	printf("Ingrese la altura del Triangulo: ");
	scanf("%f",&altura);
	area=(base*altura)/2;//Formula para el area del triangulo
	printf("El area del Triangulo es: %.2f",area);
	getch();
}