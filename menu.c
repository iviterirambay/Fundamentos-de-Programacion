/* 
* Archivo: menu.c
* Autor: José Bedón
* DESCRIPCIÓN: Realizar un menu con salir, sumatoria y facotria, donde sumatoria es la suma 
* de n numero, factorial calcula el factorial de un numero
*/

#include<stdio.h>
void sumatoria();
void factorial();

void main(){
	int op;
	do{
		printf("MENU***\n1) SALIR\n2) SUMATORIA\n3) FACTORIAL\n");
		do{
			printf("Opcion : ");
		scanf("%d",&op);
		}while(!(op>=1 && op<=3));
		printf("\n\n\n");
		switch(op){
			case 2:
				sumatoria();
				break;

			case 3:
				factorial();
				break;
		}
	}while(op!=1);
}
void sumatoria(){

	int num,i=1,acu=0;
	do{
		printf("Ingresar %d numero : ",i++);
		scanf("%d",&num);
		acu=acu+num;
	}while(num!=0);
	printf("Sumatoria : %d\n\n\n",acu);
}
void factorial()
{
	int n,fact=1,i;
	printf("Ingrese un numero : ");
	do{
		scanf("%d",&n);
	}while(n<0);
	for(i=n;i>0;i--)
		fact=fact*i;
	printf("FACOTIRAL ES : %d\n\n\n",fact);
}