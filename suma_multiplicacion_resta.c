/*
*	Archivo: suma_multiplicacion_resta.c
* Autor: Freddy Orosco
*	Descripcion:  Ingresar dos numeros por teclado, hallar la suma, multiplicacion
*								resta de ambos, luego  presentar  cada uno de los resultados por
*								pantalla.
*/

#include <stdio.h> 

void main()
{
	int num1,num2;
	int suma=0,multi=0,resta=0;

	printf("Ingrese el primer numero:");
	scanf("%d",&num1);//Ingresamos el primer numero
	printf("Ingrese el segundo numero:");
	scanf("%d",&num2);//Ingresamos el segundo numero
	suma=num1+num2;//Sumamos los numeros
	resta=num1-num2;//Restamos los numeros
	multi=num1*num2;//Multiplicamos los numeros
	printf("\nLa suma de los numeros es: %d",suma);
	printf("\nLa resta de los numeros es: %d",resta);
	printf("\nLa multiplicacion de los numeros es: %d",multi);
	getch();
}