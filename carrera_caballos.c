/* Archivo: carrera_caballos.c
*	Autor: Freddy M. Orosco
*	Descripcion :-  Escriba un programa que implemente el juego “Carrera de caballos”.
*									El programa debe utilizar el procedimiento llenarPista, mostrar el caballo ganador
*									y el número de turnos jugados
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define MAX 50

void llenar_pista(int pista[], int tam);

void main()
{
	int avance,posicion1=0,caballo1=0,posicion2=0,caballo2=0;
	int pista[MAX];
	srand(time(NULL));
	llenar_pista(pista,MAX);
	do{
		avance=1+rand()%5;
		printf("\nLa posicion inicial del caballo 1 es:%d\n", posicion1);
		posicion1=posicion1+avance;
		printf("La posicion final del caballo 1 es:%d\n", posicion1);
		if((pista[posicion1-1])==-1)
		{
			posicion1=posicion1-3;
			printf("Ha caido en un obstaculo retroceda 3 casillas\n");
			if(posicion1<0)
				posicion1=0;
			printf("Su nueva posicion final es:%d\n", posicion1);
		}
		else
			if(pista[posicion1-1]==1)
			{
				posicion1=posicion1+2;
				printf("Ha caido en un premio avance 2 casillas\n");
				printf("Su nueva posicion final es:%d\n", posicion1);
			}
		caballo1=caballo1+1;
		if(posicion1==posicion2&&caballo1>caballo2)
		{
			posicion1=posicion1-1;
			printf("El caballo 1 ocupa una celda ya ocupada\n");
			printf("El caballo 1 retrocede una casilla\n");
			printf("Su nueva posicion final es:%d\n", posicion1);
		}
		getch();
		avance=rand()%5+1;
		printf("\nLa posicion inicial del caballo 2 es:%d\n", posicion2);
		posicion2=posicion2+avance;
		printf("La posicion final del caballo 2 es:%d\n", posicion2);
		if(pista[posicion2-1]==-1)
		{
			posicion2=posicion2-3;
			printf("Ha caido en un obstaculo retroceda 3 casillas\n");
			if(posicion2<0)
				posicion2=0;
			printf("Su nueva posicion final es:%d\n", posicion2);
		}
		else
			if(pista[posicion2-1]==1)
			{
				posicion2=posicion2+2;
				printf("Ha caido en un premio avance 2 casillas\n");
				printf("Su nueva posicion final es:%d\n", posicion2);
			}
		caballo2=caballo2+1;
		if(posicion1==posicion2&&caballo2==caballo1)
			{
				posicion2=posicion2-1;
				printf("El caballo 2 ocupa una celda ya ocupada\n");
				printf("El caballo 2 retrocede una casilla\n");
				printf("Su nueva posicion final es:%d\n", posicion2);
			}
	getch();
		
	}while(posicion1<=50&&posicion2<=50);

	if(posicion1>50&&posicion1>posicion2)
	{
		printf("\nEl ganador es el caballo 1\n");
		printf("Los turnos que se movio fueron:%d\n", caballo1);
	}
	else
	{	
		printf("\nEl ganador es el caballo 2\n");
		printf("Los turnos que se movio fueron:%d\n", caballo2);
	}
	getch();
}
void llenar_pista(int pista[], int tam)
{
	int i, a;
	for(i=0;i<MAX;i++)
	{
		pista[i]=0;
	}
		for(i=0;i<2;i++)
	{
		do{
		a=rand()%50;
		}while(pista[a]!=0);
		pista[a]=1;
	}
	for(i=0;i<2;i++)
	{
		do{
		a=rand()%50;
		}while(pista[a]!=0);
		pista[a]=-1;	
	}
}