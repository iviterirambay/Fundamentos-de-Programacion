/*Archivo: cuadrados_arreglo.c
Autor:José Bedón
Descripcion:
	LLENAR UN ARREGLO CON NUMEROS ALEATORIOS DEL 1-9 SIN QUE SE REPITAN Y 
	MOSTRAR EL CUADRADO RESPECTIVO DE CADA CONTENIDO DEL ARREGLO.

**************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef enum{false,true}bool;

#define DIM 9

void llenar(int arre[]);
void cuadrado(int n);
bool seEncontro(int tmp,int A[],int i);

void main(){
	int arreglo[DIM]={0};
	int i;

	srand(time(NULL));

	llenar(arreglo);

	for(i=0;i<DIM;i++){
		printf("CUADRADO DE LADO : %d\n",arreglo[i]);
		cuadrado(arreglo[i]);
		printf("\n\n");
	}

}
void llenar(int arre[]){
	int i,tmp;
	for(i=0;i<DIM;i++){
		do{
			tmp=rand()%9+1;	//aleatorios entre 1 y 9
		}while(!seEncontro(tmp,arre,i));
		arre[i]=tmp;
	}
}
bool seEncontro(int tmp,int A[],int i){
	int j;
	for(j=0;j<i;j++){
		if(A[j]==tmp)
			return false;
	}
	return true;
}
void cuadrado(int n){
	int f,c;
	for(f=1;f<=n;f++){
		for(c=1;c<=n;c++){
			if(f==1 || f==n)
				printf("%d",n);
			else{
				if(c==1 || c==n)
					printf("%d",n);
				else
					printf(" ");
			}
		}
		printf("\n");
	}
}