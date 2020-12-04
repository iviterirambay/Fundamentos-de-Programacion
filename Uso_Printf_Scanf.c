/*
*	Archivo: Uso_Printf_Scanf.c
* Autor: Freddy Orosco
*	Descripcion:  Uso de "printf()" y "scanf()"
*								Hacer un programa que ingrese cuatro numeros; luego presentar 
*								en pantalla los numeros de las siguientes manera:	
*								a)Presentar todos los numeros consecutivamente
*								b)Presentar cada numero en una linea diferente
*								c)Presentar cada numero en una linea diferente y además con tabulacion.
*/

#include <stdio.h>

void main()
{
	int num1,num2,num3,num4;

	printf("Ingrese el primer numero:  ");
	scanf("%d",&num1);
	printf("Ingrese el segundo numero: ");
	scanf("%d",&num2);
	printf("Ingrese el tercer numero:  ");
	scanf("%d",&num3);
	printf("Ingrese el cuarto numero:  ");
	scanf("%d",&num4);
	printf("Primer Metodo de Presentacion:\n");   //Presentadion a:
	printf("%d %d %d %d\n\n",num1,num2,num3,num4);
	printf("Segundo Metodo de Presentacion:\n"); 	//Presentacion b:
	printf("%d\n%d\n%d\n%d\n\n",num1,num2,num3,num4);
	printf("Tercer Metodo de Presentacion:\n"); 	//Presentacion c:
	printf("\t%d\n\t%d\n\t%d\n\t%d\n",num1,num2,num3,num4);
	getch();
}