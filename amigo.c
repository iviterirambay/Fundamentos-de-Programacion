/*
*	Archivo: amigos.c	
* Autor: Freddy Orosco
*	Descripcion:	Elaborar una función que retorne si dos numeros son amigos.
*								Dos numeros son amigos si la suma de los divisores propios
*								de cada uno de ellos es igual al otro numero.
*								Ejemplo: 
*								220 divisores: 1,2,4,5,10,11,20,22,44,55,110 suma=284
*								284 divisores: 1,2,4,71,142									 suma=220
*								entonces estos dos numeros son amigos.
*/

#include <stdio.h>

int amigo(int n1,int n2);
int amigo(int n1,int n2)
{
	int divisor=1,suma1=0,suma2=0;
	while (divisor<n1)
	{
		if((n1%divisor)==0)
			suma1=suma1+divisor;
		divisor++;
	}
	divisor=1;
	while (divisor<n2)
	{
		if((n2%divisor)==0)
			suma2=suma2+divisor;
		divisor++;
	}
	if(n1==suma2 && n2==suma1)
		return 1;
	else
		return 0;
}

void main()
{
	int numero1,numero2,esAmigo;
	printf("Ingrese un numero:");scanf("%d", &numero1);
	printf("Ingrese otro numero:");scanf("%d", &numero2);
	esAmigo=amigo(numero1,numero2);
	if(esAmigo==1)
		printf("El %d es un numero amigo de %d",numero1,numero2);
	else
		printf("El %d no es un numero amigo de %d",numero1,numero2);
getch();
}