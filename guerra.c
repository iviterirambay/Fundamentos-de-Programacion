/*Archivo: guerra.c
Autor:José Bedón
Descripcion:
	SIMULAR UNA GUERRA DE BARCO, LLENA EL MAR(DIM 10) CON 5 BARCOS Y LAS MUNICIONES(DIM 10)
	CON 5 BALAS, EL JUGADOR TENDRA 10 OPURTUNIDADES DEBERA AL POS DE SU BALA, LUEGO SI HAY
	UNA BALÑA DEBERA ELEGIR LA POS DEL BARCO, SI ACIERTA HUNDE EL BARCO Y GANA 100 PTS, SI 
	NO LO HUNDE PIERDE 50 PTS.
	EL JUEGO TERMINA DESPUES QUE EL JUGADOR TENGA 5 OPORTUNIDADES PARA SELECIONAR LA POS
	DE SU BALA.

**************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void llenar(int A[]);
void imprimir(int A[]);

#define DIM 10


void main(){
	int mar[DIM]={0},muni[DIM]={0};
	int pos_bala,turno,pos_barco,puntaje=0;
	srand(time(NULL));
	llenar(mar);
	llenar(muni);
	
	

	for(turno=1;turno<=5;turno++){
		printf("LE QUEDAN %d TURNOS",5-turno);
		/*NO SE DEBERIA MOSTRAR EL ARREGLO MAR Y EL ARREGLO MUNI
		******PERO SE LOS MOSTRARA PARA FACILITAR EL JUEGO*****/
		printf("\n");
		printf("MUNICIONES : ");
		imprimir(muni);
		printf("\nMAR : ");
		imprimir(mar);
		/********************************************************/
		/********************************************************/
		
		printf("\nINGRESE POSICION DE BALA <1-10> : ");
		do{
			scanf("%d",&pos_bala);
		}while(pos_bala<1 || pos_bala>10);

		if(muni[pos_bala-1]==0)
			printf("NO SE ENCONTRO BALA --> INTENTO FALLIDO\n\n");
		else{
			muni[pos_bala-1]=0;	//BALA USADA POSICION EN 0
			printf("\n\tINGRESE POSICION DEL MAR <1-10> : ");
			do{
				scanf("%d",&pos_barco);
			}while(pos_barco<1 || pos_barco>10);

			if(mar[pos_barco-1]==0){
				printf("\tNO SE ENCONTRO BARCO --> TIRO FALLIDO\n\n");
				puntaje=puntaje-50;
			}
			else{
				mar[pos_barco-1]=0;	//BARCO HUNDIDO POSICION 0;
				printf("\tBARCO HUNDIDO\n\n");
				puntaje=puntaje+100;
			}
			
		}

	}
	printf("\n\nPUNTAJE TOTAL : %d",puntaje);
}
void llenar(int A[]){
	int i,rd;
	for(i=1;i<=5;i++){
		do{
			rd=rand()%DIM;	//RANDEAMOS LAS POSICIONES MAS NO EL CONTENIDO DE LA MISMA Y COLOCAREMOS 1 Y 0 PARA LLENO Y VACIO
		}while(A[rd]==1);
		A[rd]=1;
	}
}
void imprimir(int A[]){
	int i;
	for(i=0;i<DIM;i++)
		printf(" %d ",A[i]);
}