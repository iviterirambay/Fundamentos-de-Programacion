/*
*	Archivo: booleana_esNarcisista.c
* Autor: Freddy Orosco
*	Descripcion:	Recibe  la cual retorna verdadero si n es un número narcisista,
*								caso contrario retorna falso.  Un número narcisista es aquel en el 
*								cual la suma de los cubos de sus dígitos es igual al mismo número.  
*								Por ejemplo:
*								153 = 1^3+5^3+3^3 , esNarcisista (153) retorna true.
*								25 ? 2^3+5^3 , esNarcisista (25) retorna false.
*/

#include <stdio.h>
#include <math.h>
typedef enum {false,true}bool;

bool esNarcisista(int numero); 
bool esNarcisista(int numero)
{
	int cifra,temp;
	float cubo,suma=0;
	temp=numero;// Se igual una temporal al numero porque al final la necesitaremos para ver si el numero es igual. 
	while(numero!=0)
	{
		cifra=numero%10;//obtiene digito
		cubo=pow(cifra,3);//eleva el digito al cubo
		numero=numero/10;//Disminuye el numero
		suma=suma +cubo;//acumula la suma de los digitos al cubo
	}
	if(temp==suma)
		return true;
	else
		return false;
}

void main()
{
	int num,opcion;
	printf("Ingrese un numero:");
	scanf("%d",&num);
	opcion=esNarcisista(num);
	if(opcion==1)
		printf("El numero %d es Narcisista",num);
	else
		printf("El numero %d NO es Narcisista",num);
	getch();
}