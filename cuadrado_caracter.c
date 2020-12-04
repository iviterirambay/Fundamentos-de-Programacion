/* 
* Archivo: cuadrado_caracter.c
* Autor: José Bedón
* DESCRIPCIÓN: Pedir un caracter y el lado del cuadrado, dibujar el cuadrado
* con el caracter ingresado, solo el contorno
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
		for(c=1;c<=n;c++){
			if(f==1 || f==n)
				printf("%c",car);
			else{
				if(c==1 || c==n)
					printf("%c",car);
				else
					printf(" ");
			}
		}
		printf("\n");
	}
}
