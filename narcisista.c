/* 
* Archivo: narcisista.c
* Autor: José Bedón
* DESCRIPCIÓN: Pedir un numero y verificar si es narcisista, un numero es narcisista
* si la suma del cubo de sus digitos da como reusltado el mismo numero
*/

#include<stdio.h>
typedef enum{false,true}bool;
bool esNarcisista(int n);

void main(){
	int num;
	printf("Ingrese un numero : ");
	scanf("%d",&num);
	if(esNarcisista(num))
		printf("Es Narcisista");
	else
		printf("No es Narcisista");
}
bool esNarcisista(int n){
	int dig,tmp,acu=0;
	tmp=n;
	do{
		dig=tmp%10;
		acu=acu+pow(dig,3);
		tmp=tmp/10;
	}while(tmp!=0);

	if(acu==n)		//si el el numero obtenido por la suma del cubo de sus digitos es igual al numero originario
		return true;
	return false;
}
