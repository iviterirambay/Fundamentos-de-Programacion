/* 
* Archivo: flecha.c
* Autor: José Bedón
* DESCRIPCIÓN: El programa debe de pedir al usuario el lado que se usara como base
* para construir una flecha hacia arriba, la cola de la flecha siempre tendra un
* grosor de 3 asteriscos
* Ejemplo: 9
		    *
		   ***
		  *****
		 *******
		*********
		   ***
		   ***
		   ***
		   ***
*/

#include<stdio.h>
void main(){
	int l,z,y=1,f,c,cu,h,ast,esp;
	printf("Ingrese lado de la flecha : ");
	do{
		scanf("%d",&l);
	}while(!(l>0 && l%2==1));	//mayores que 0 y numero impares
	cu=l/2;		//lado del cuadrilatero
	h=l-cu;		//altura del triangulo
	z=h;
	//FOR PARA LA PARTE DEL TRIANGULO
	for(f=1;f<=h;f++){
		for(esp=z-1;esp>=1;esp--)
			printf(" ");
		for(ast=1;ast<=y;ast++)
			printf("*");
		printf("\n");
		z--;
		y=y+2;
	}
	//FOR PARA LA PARTE DEL CUADRILATERO
	for(f=1;f<=cu;f++){
		for(esp=1;esp<=(l-3)/2;esp++)
			printf(" ");
		for(ast=1;ast<=3;ast++)
			printf("*");
		printf("\n");
	}
	//getch();
}