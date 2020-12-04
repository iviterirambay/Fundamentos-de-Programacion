/* 
* Archivo: tabla.c
* Autor: José Bedón
* DESCRIPCIÓN: Pedir un numero positivo y mostrar las tablas de multiplicar anterior
* la pedida y la posterior.
*/

#include<stdio.h>
void tabla(int n);
void main(){
	int num;
	printf("Mostrar la tabla del : ");
	do{
		scanf("%d",&num);
	}while(num<1);
	tabla(num-1);	//tabla de multiplicar anterior
	printf("\n");
	tabla(num);		//tabla de multiplicar pedida
	printf("\n");
	tabla(num+1);	//tabla de multiplicar posterior
	printf("\n");
}
void tabla(int n){
	int resul,i;
	for(i=0;i<13;i++){
		resul=i*n;
		printf("%d X %d = %d\n",n,i,resul);		//formato de salida por pantalla
	}
}