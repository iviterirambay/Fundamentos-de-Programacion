/*
*	Archivo: aleatoriosPares.c	
* Autor: Freddy Orosco
*	Descripcion:	Hacer un programa que genere cinco numeros aleatorios PARES entre el 20
*								y 40, presentar los numeros en pantalla.
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
		aleatorio=20+rand()%21;
		if(aleatorio%2==0)
		{
			printf("%d\n",aleatorio);
			cont++;
		}
	}
	getch();
}