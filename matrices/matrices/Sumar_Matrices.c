/*
	Archivo:	 Sumar_Matrices.c
	Autor:		 Freddy Orosco V.
	Descripción: Dadas dos matrices ingresadas por el usuario realizar la suma de dichas matrices
*/

#include <stdio.h>
#define MAX 100

void llenar_matrices(int mat1[][MAX],int mat2[][MAX], int fila, int columna);
void Suma_matrices(int mat1[][MAX],int mat2[][MAX], int suma[][MAX],int fil1,int col1);
void Mostrar_Pantalla(int mat1[][MAX],int mat2[][MAX],int suma[][MAX],int fila, int columna);

void main()
{
	int matriz1[MAX][MAX],matriz2[MAX][MAX],suma[MAX][MAX];
	int fila,columna;
	printf("Ingrese las dimensiones de la primera matriz\n");
	printf("Fila:\t");
	scanf("%d",&fila);
	printf("Columna:\t");
	scanf("%d",&columna);
	printf("Ingrese las matrices\n");
	llenar_matrices(matriz1,matriz2,fila,columna);
	Suma_matrices(matriz1,matriz2,suma,fila,columna);
	Mostrar_Pantalla(matriz1,matriz2,suma,fila,columna);
	getch();
}

void llenar_matrices(int mat1[][MAX], int mat2[][MAX], int fila, int columna)
{
	int i,j;
	for(i=0;i<fila;i++)
	{
		for(j=0;j<columna;j++)
		{
			fflush(stdin);
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("\n");
	for(i=0;i<fila;i++)
	{
		for(j=0;j<columna;j++)
		{
			fflush(stdin);
			scanf("%d",&mat2[i][j]);
		}
	}
	printf("\n");

	
}

void Suma_matrices(int mat1[][MAX],int mat2[][MAX], int suma[][MAX], int fila, int columna)
{
	int i,j;	
	
	for(i=0;i<fila;i++)
	{
		for(j=0;j<columna;j++)
		{
			suma[i][j]=mat1[i][j]+mat2[i][j];
		}
		
	}

}

void Mostrar_Pantalla(int mat1[][MAX],int mat2[][MAX],int suma[][MAX],int fila, int columna)
{
	int i,j;
	system("cls");
	for(i=0;i<fila;i++)
	{
		for(j=0;j<columna;j++)
		{
			printf("%4d",mat1[i][j]);
		}
		printf("\n");
	}
	printf("\n\t +\n");
	for(i=0;i<fila;i++)
	{
		for(j=0;j<columna;j++)
		{
			printf("%4d",mat2[i][j]);
		}
		printf("\n");
	}
	printf("\n\t =\n");
	for(i=0;i<fila;i++)
	{
		for(j=0;j<columna;j++)
		{
			printf("%4d",suma[i][j]);
		}
		printf("\n");
	}

}
