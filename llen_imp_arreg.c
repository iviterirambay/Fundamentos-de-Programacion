/*Archivo: llen_imp_arreg.c
Autor:José Bedón
Descripcion:
	LLENAR UN ARREGLO CON NUMEROS ALEATORIOS DEL 100-200  Y 
	MOSTRAR EL ARREGLO CON SUINDICE.
	EJEMPLO:
				INDICE 0 = 123
				INDICE 1 = 200
				....

**************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define DIM 10


void prt_arreglo(int A[]);
void llenar(int arre[]);

void main(){
	int arreglo[DIM]={0};


	srand(time(NULL));

	llenar(arreglo);
	prt_arreglo(arreglo);

	

}
void llenar(int arre[]){
	int i;
	for(i=0;i<DIM;i++)
			arre[i]=rand()%101+100;	//aleatorios entre 100 y 200--->> n=min+rand()%(max-min+1);
}
void prt_arreglo(int A[]){
	int i;
	for(i=0;i<DIM;i++)
		printf("INDICE %d = %d\n",i,A[i]);
}
