/*
	Archivo:	 transpuesta.c
	Autor: Freddy Orosco V.
	Descripción: Dadas una matriz presentar en pantalla su transpuesta.
*/

#include <stdio.h>

void trans(int matriz[][3],int filas,int transpuesta[][4],int filasT);


void main()
{
	int matriz[4][3]={{3,5,7},{2,4,6},{1,0,7},{8,9,0}};
	int transpuesta[3][4],i,j;
	trans(matriz,4,transpuesta,3);
	printf("Su matriz original es:\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
			printf("%3d",matriz[i][j]);
		printf("\n");
	}

	printf("\nLa matriz tranpuesta es:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
			printf("%3d",transpuesta[i][j]);
		printf("\n");
	}
	getch();
}

void trans(int matriz[][3],int filas,int transpuesta[][4],int filasT)
{
	int i=0,j;
	do{
		for(j=0;j<filasT;j++)
			transpuesta[j][i]=matriz[i][j];
		i++;
	}while(i<filas);
}