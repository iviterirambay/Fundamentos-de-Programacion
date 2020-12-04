/*Archivo: dig_repetidos.c
Autor:José Bedón
Descripcion:
	LLENAR UN ARREGLO CON NUMEROS ALEATORIOS DEL 100-200  Y 
	MOSTRAR EL ARREGLO CON SUINDICE.
	EJEMPLO:
				NUMERO : 112254778
				REPETIDO 1=2
				REPETIDO 2=2
				REPETIDO 4=1
				....


**************************************************************/

#include<stdio.h>

#define DIM 10

void prt_arreglo(int A[]);

void main(){
	int arreglo[DIM]={0},dig;	//un arreglo para que coincidan los numeros repetidos del numero co el indice del arreglo y poder saber cuantos digitos se repitieron
	long num;

	printf("Ingresar un numero : ");
	do{
		scanf("%ld",&num);
	}while(num<0);

	do{
		dig=num%10;
		arreglo[dig]++;
		num=num/10;
	}while(num!=0);

	prt_arreglo(arreglo);

}
void prt_arreglo(int A[]){
	int i;
	for(i=0;i<DIM;i++){
		if(A[i]!=0)		//Si no en esa casilla hay 0 es que no se repitieron x lo tanto no lo imprimo esta es la condicion de negacion
			printf("REPETIDO %d = %d VECES\n",i,A[i]);
	}
}
