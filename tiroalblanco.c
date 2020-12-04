/* 
* Archivo: tiroalblanco.c
* Autor: José Bedón
* DESCRIPCIÓN: El programa debera de generar al azar una coordenada en X y en Y,
* estas coordenadas seran el lugar de tiro, se debe simular un tablero de 10X10
* y etndra circunferencias concentricas de radio 5-3-1 declarar en #define, usar
* la ecuacion de la circunferencia para decidir si el tiro dio en el blanco en 
* en que seccion y si fallo, muestre las coordenadas y el mensaje de tiro
* considere la ecacion de la circunferencia (x-5)^2+(y-5)^2=(radio)^2
* Ejemplo: x=5   y=5	---> tiro al centro A
	   x=4   y=6	---> tiro al intermedio B
	   x=2   y=5	---> tiro externo C
	   x=1   y=10	---> fallo el tiro
		
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void seccion(int posx,int posy);

#define RADIO1 5
#define RADIO2 3
#define RADIO3 1

void main(){
	int x,y;
	srand(time(NULL));	
	x=rand()%11;	//coordenadas(0-10)
	y=rand()%11;	//coordenadas(0-10)
	printf("COORDENADAS\nX : %d\nY : %d\n",x,y);
	seccion(x,y);
}
void seccion(int posx,int posy){
	int valor;
	valor=pow(posx-5,2)+pow(posy-5,2);
	printf("\n%d\n",valor);
	if(valor<=pow(RADIO3,2))
		printf("TIRO SECCION CENTRAL A\n");
	else if(valor<=pow(RADIO2,2))
		printf("TIRO SECCION INTERMEDIO B\n");
	else if(valor<=pow(RADIO1,2))
		printf("TIRO SECCION EXTERNA C\n");
	else
		printf("TIRO FALADO");
}