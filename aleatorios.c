/*
*	Archivo: aleatorios.c	
* Autor: Freddy Orosco
*	Descripcion:	Hacer un programa que genere cinco numeros aleatorios entre el uno
*								y el nueve, presentar los numeros en pantalla.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int aleatorio,cont=1;
	srand(time(NULL));
	while(cont<=5)
	{
		aleatorio=1+rand()%9;
		printf("%d\n",aleatorio);
		cont++;
	}
	getch();
}