/* 
* Archivo: numeromayor.c
* Autor: José Bedón
* DESCRIPCIÓN: El programa debe de pedir n numeros mientras sea distinto que 0
* cuando esto ocurra deja de pedi numero y muestra cual fue el mayor de todos.
* Ejemplo: 15-20-17-57-12-20-17-0		MAYOR : 57
*/

#include<stdio.h>
void main(){
	int num,mayor=0,tmp,i=1;
	do{
		printf("Ingrese #%d : ",i++);
		scanf("%d",&num);
		tmp=num;
		if(num>mayor)
			mayor=num;
	}while(num!=0);
	printf("EL NUMERO MAYOR FUE : %d",mayor);
	getch();
}