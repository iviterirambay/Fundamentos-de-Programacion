/*
Archivo:	 Encuentra1.c
Autor: Fredy Orosco
Descripción:	Llenar una matriz de 6x6 con ceros y de manera aleatoria colocar 10 unos en dicha posicion 
							luego preguntar al usuario las posiciones de fila y columna  y comprobar si acerto o no.
							*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILA 6
#define COLUM 6

void LLenar_Tabla(int Tabla[][6],int FILAS);
void Mostrar_TablaPosicion(int Tabla[][6],int FILAS);

void main()
{
	int Tabla[FILA][COLUM]={0};//tabla llena de ceros
	int fila,colum;
	srand(time(NULL));
	LLenar_Tabla(Tabla,FILA);
	printf("Elija Posicion entre 1 y 6:\n ");
	do{
		printf("La fila: ");
		scanf("%d",&fila);
	}while(fila<1 || fila>6);//Validacion de las filas
	do{
		printf("La Columna: ");
		scanf("%d",&colum);
	}while(colum<1 || colum>6);//Validacion de las columnas
	Mostrar_TablaPosicion(Tabla,FILA);
	if(Tabla[fila-1][colum-1]==1)
		printf("Gano el Juego\n");
	else
		printf("Perdio el Juego");
	getch();
}

void LLenar_Tabla(int Tabla[][6],int FILAS)
{
	int i,j,x;
	for(x=0;x<10;x++)
	{
		do{
		i=rand()%6;
		j=rand()%6;
		}while(Tabla[i][j]==1);
	Tabla[i][j]=1;
	}
}

void Mostrar_TablaPosicion(int Tabla[][6],int FILAS)
{
	int i,j;
	for(i=0;i<FILAS;i++)
	{
		for(j=0;j<COLUM;j++)
			printf("%4d ",Tabla[i][j]);
		printf("\n");
	}
}