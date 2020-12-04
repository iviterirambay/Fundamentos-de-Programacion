/*
*	Archivo: perfecto.c
* Autor: Freddy Orosco
*	Descripcion:	Elabore una función que retorne uno si un numero es perfecto o
*								que retorne cero si no lo es.
*								Un numero es perfecto cuando la suma de sus divisores excepto el
*								mismo numero da como resultado el mismo numero.
*								Ejemplo: 
*								n=6 divisores: 1,2,3,6   suma=1+2+3=6  suma=n perfecto
*								n=10 divisores: 1,2,5,10 suma=1+2+5=8  suma!=n no es perfecto
*/


#include <stdio.h>

int perfecto(int n);
int perfecto(int n)
{
	int divisor=1, suma=0;
	while (divisor<n)
	{
		if((n%divisor)==0)
		{
		suma=suma+divisor;
		}
		divisor++;
	}
	if(n==suma)
		return 1;
	else
		return 0;
}
void main()

{
	int numero,esPerfecto;
	printf("Ingrese un numero:");scanf("%d", &numero);
	esPerfecto=perfecto(numero);
	if(esPerfecto==1)
	{
		printf("El numero %d es perfecto",numero);
	}
	else
	{
		printf("El numero %d no es perfecto",numero);
	}
getch();
}