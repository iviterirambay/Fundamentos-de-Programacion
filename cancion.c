/*
*  Archivo: cancion.c
*  Autor:Freddy Orosco
*  Descripcion:
*				Descripción:Escriba un programa que genere una canción y la muestre por pantalla
*				en formato numérico.
*				Una canción está formada por notas musicales representadas con dígitos entre 0 y 6.
*				Las notas musicales de la canción son generadas aleatoriamente de acuerdo a las siguientes 
*				reglas:
*			  -	La primera nota de la canción no debe ser un DO
*				-	Si la nota generada es FA y la nota anterior fue un RE, la nota generada no será tomada en cuenta en la canción.
*				-	Si la nota generada es MI, se añade a la canción DO RE MI, dos veces.
*				La canción finaliza cuando las dos últimas notas generadas sean las notas DO,SI o las notas FA, SOL.	
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 300

int genera_aleatorio(void);

void main()
{
	int b,i=0,A[MAX];
	srand(time(NULL));
	b=genera_aleatorio();
	while(b==0)//Para que la primera nota no sea DO
		b=genera_aleatorio();
	A[i]=b; 
	printf("%d ",A[i]);
	if(A[i]==2)
	{
		printf("0 1 2 "); printf("0 1 2 ");
	}
	
	do{
		i++;
		    b=genera_aleatorio();
			A[i]=b; 
			if(A[i]==3 && A[i-1]==1)
			{
				printf("%c ",' ');
			}
			else
			{
				printf("%d ",A[i]);
			}
			if(A[i]==2)
			{
				printf("0 1 2 "); printf("0 1 2 ");
			}
		
	}while((A[i]!=6 || A[i-1]!=0) && (A[i]!=4 || A[i-1]!=3));
	getch();

}

int genera_aleatorio(void)
{
	int a;
	a=rand()%7;
	return a;
}

