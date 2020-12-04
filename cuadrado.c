/*
*	Archivo: cuadrado.c
* Autor: Freddy Orosco
*	Descripcion:	Escriba un procedimiento cuyo prototipo es:
*								void cuadrado(int lineas, char caracter) que graficar� un cuadrado 
*								formado por el caracter enviado como par�metro y cuya  longitud depender� 
*								del n�mero de lineas. Considere que no tiene que dibujar la diagonal derecha 
*								del cuadrado (use espacios en blanco).
*								Por ejemplo:
*								cuadrado(5,'*') muestra:				
*								*	*	*	*	
*								*	*			*
*								*			*	*
*										*	*	*
*									*	*	*	*
*/

#include <stdio.h>

void cuadrado(int lineas,char letra); 
void cuadrado(int lineas,char letra)
{
	int i,j;
	for(i=1;i<=lineas;i++)
	{
		for(j=1;j<=lineas;j++)
		{
			if(i==lineas-j+1)
				printf("%c",' ');
			else
				printf("%c",letra);
		}
		printf("\n");
	}
}

void main()
{
	int lin;
	char carac;
	printf("Ingrese el caracter:");
	scanf("%c",&carac);
	printf("Ingrese el numero de lineas:");
	scanf("%d",&lin);
	cuadrado(lin,carac);
	getch();
}