/* 
* Archivo: menu.c
* Autor: José Bedón
* DESCRIPCIÓN: Pedir un numero 1-52 y mostrar su palo y valor
*/

#include<stdio.h>
void palo(int n);
void valor(int n);
void main(){
	int carta;
	printf("Escoja una carta <1-52> : ");
	do{
		scanf("%d",&carta);
	}while(!(carta>=1 && carta<=52));
	palo(carta);
	valor(carta);
	printf("\n\n");
}
void palo(int n){
	if(n>=1 && n<=13)
		printf("%c",3);
	if(n>=14 && n<=26)
		printf("%c",4);
	if(n>=27 && n<=39)
		printf("%c",5);
	if(n>=40 && n<=52)
		printf("%c",6);
}
void valor(int n){
	if(n%13==0)
		printf("K");
	else if(n%13==1)
		printf("As");
	else if(n%13==11)
		printf("J");
	else if(n%13==12)
		printf("Q");
	else
		printf("%d",n%13);
}