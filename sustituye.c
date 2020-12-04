/*Archivo: sustituye.c
Autor:José Bedón
Descripcion:
	LLENAR UN ARREGLO CON NUMEROS ALEATORIOS DEL 150-250  Y PEDIR AL USUARIO EL NUMERO
	QUE DESEA CAMBIAR POR UNO NUEVO
	LUEGO MOSTRAR EL NUEVO ARREGLO
	EJEMPLO:
				150-160-170-180-190-195-170...
				CAMBIAR EL 160 POR EL 600
				150-600-170-180-190-195-170...
				....


**************************************************************/

#include<stdio.h>
void sustituye(int A[],int viejo,int nuevo);
void llenar(int arre[]);
void prt_arreglo(int A[]);
#define DIM 10


void main(){
	
	int num,a,b;
	int arreglo[DIM]={0};

	llenar(arreglo);
	prt_arreglo(arreglo);

	
	printf("\nCambiar los numero : ");
	scanf("%d",&a);
	printf("Por el : ");
	scanf("%d",&b);

	sustituye(arreglo,a,b);

	prt_arreglo(arreglo);
}

void llenar(int arre[]){
	int i;
	for(i=0;i<DIM;i++)
			arre[i]=rand()%101+150;		//NUMEROS ALEATORIOS ENTRE 150-250
}
void sustituye(int A[],int viejo,int nuevo){
	int i,j=0;
	for(i=0;i<DIM;i++){
		if(A[i]==viejo){
			j=1;	//ATAJO PARA COMPROBAR POSTERIORMENTE SI SE ENCONTRO ESE NUMERO
			A[i]=nuevo;
		}
	}
	if(j==0)
		printf("NO SE ENCONTRO ESE NUMERO \n");
	else
		printf("SE ENCONTRO ESE NUMERO \n");
}
void prt_arreglo(int A[]){
	int i;
	for(i=0;i<DIM;i++)
		printf(" %d ",A[i]);
}