/*
*	Archivo: adivina_numero.c
* Autor: Freddy Orosco
*	Descripcion:	Hacer un programa que simule un juego. El juego consiste en lo siguiente:
*								Hacer generar un numero alatorio, luego pedirle al usuario que 
*								ingrese un numero entre el uno y el diez, si el numero que el 
*								usuario ingresa es el mismo que el generado presentar en pantalla
*								"Gano el juego", si no es asi pedirle al usuario otro numero teniendo
*								en cuenta que solo tiene tres oportunidades. Si luego de haber terminado 
*								No ha adivinado presentar "Lo siento, Has perdidio"
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int num,numgen,cont=3;
	srand(time(NULL));
	numgen=1+rand()%10;//Genera un aleatorio entre 1 y 10
	do{
		do{

		printf("Ingrese un numero entre 1 y 10:");
		scanf("%d",&num);
		}while(num<1 || num>10);//Condicion para los numeros entre 1 y 10
		if(numgen==num)//Si numero es igual al aleatorio
		{
			printf("Ha adivinado. Gano el juego\n");
			cont=-1;//para que salga del lazo
		}
		else
		{
			if(cont!=1)
				printf("No has adivinado. Tienes otra Oportunidad\n");
			cont--;//valla de decrementando
		}
	}while(cont>=1);//mientras el cont sea mayor a uno seguira el lazo
	if(cont==0)
	{
		printf("Lo siento, Has perdido");
		printf("\nEl numero ganador era: %d",numgen);
	}
		getch();
}