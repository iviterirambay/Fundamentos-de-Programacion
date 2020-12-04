/*
	Archivo:	 tablas_sumar.c
	Autor: Freddy Orosco V.
	Descripción: Realizar una matriz que presenta las tablas de sumar del 1 hasta el 12 por pantalla. 
*/

#include <stdio.h>
#define FILA 12
#define COLUM 12

void LLenar_Tabla(int tabla[][COLUM],int filas);
void Mostrar_Tabla(int tabla[][COLUM],int filas);

void main()
{
	int suma[FILA][COLUM]={0};
	LLenar_Tabla(suma,12);
	Mostrar_Tabla(suma,12);	
	getch();
}

void LLenar_Tabla(int tabla[][12],int filas)
{
	int i,j;
	for(i=0;i<filas;i++)
	{
		for(j=0;j<COLUM;j++)
			tabla[i][j]=(i+1)+(j+1);
	}
}

void Mostrar_Tabla(int tabla[][12],int filas)
{
	int i,j;
	printf(" + %c",186);
	for(i=0;i<filas;i++)
		printf("%4d ",i+1);
	printf("\n");
	for(i=0;i<65;i++)
		printf("%c",205);
	printf("\n");
	for(i=0;i<filas;i++)
	{
		printf("%3d%c",i+1,186);
		for(j=0;j<COLUM;j++)
			printf("%4d ",tabla[i][j]);
		printf("\n");
	}
}