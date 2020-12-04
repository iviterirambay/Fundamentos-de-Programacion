/* 
* Archivo: cuadrado_caracter.c
* Autor: José Bedón
* DESCRIPCIÓN: Pedir un caracter y el lado del cuadrado, dibujar el cuadrado
* con el caracter ingresado, sin la diagonal de la derecha superior hasta
* la esquian izquierda inferior
*/
#include <stdio.h>
void cuadrado(int n,char car);

void main(){
	int l;
	char let='a';
	printf("Ingrese un caracter : ");
	scanf("%c",&let);
	printf("Ingrese el lado del cuadrado : ");
	do{
	scanf("%d",&l);
	}while(l<=0);
	cuadrado(l,let);

}
void cuadrado(int n,char car){
	int f,c;
	for(f=1;f<=n;f++){
		for(c=n;c>=1;c--){
			if(f==c)
				printf(" ");
			else
				printf("%c",car);
		}
		printf("\n");
	}
}
