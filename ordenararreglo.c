/* 
* Archivo: ordenararreglo.c
* Autor: José Bedón
* DESCRIPCIÓN: Llenar un arreglo con numero aleatorios del 1-100, mostralos, ordenarlos
* mostralos
*/


#include<stdio.h>
#define DIM 10
void llenar(int arreglo[]);
void ordenar(int arreglo[]);
void mostrar(int arreglo[]);

void main(){
	int numeros[10]={0};
	srand(time(NULL));
	mostrar(numeros);
	printf("\n");
	llenar(numeros);
	mostrar(numeros);
	printf("\n");
	ordenar(numeros);
	mostrar(numeros);
}
void llenar(int arreglo[]){
	int i;
	for(i=0;i<DIM;i++)
		arreglo[i]=rand()%100+1;
}
void ordenar(int arreglo[]){
	int f,c,tmp;
	for(f=0;f<DIM;f++){
		for(c=f+1;c<DIM;c++){
			if(arreglo[f]<arreglo[c]){
				tmp=arreglo[f];
				arreglo[f]=arreglo[c];
				arreglo[c]=tmp;
			}
		}
	}
}
void mostrar(int arreglo[]){
	int i;
	for(i=0;i<DIM;i++)
		printf("%d ",arreglo[i]);
}