/*
*	Archivo: diagonal1.c
*	Autor: V. Cedeno
*	Fecha de creaci�n: 2010-06-11
*	Descripci�n:
*	Ejercicios para aplicar la declaraci�n, implementaci�n y uso de funciones.
*	Modificaciones:
*	
*/

#include <stdio.h>
#include <conio.h>

//Prototipos
int contarDigitos(int z);
int esPar(int n);
int sumarDigitos(int n);


void main()
{
	int n,x,y,suma;

	do
	{
		printf("Ingrese n: ");
		scanf("%d",&n);
	}while(n<=0);
	
	x = contarDigitos(n);
	y = esPar(n);
	suma = sumarDigitos(n);
	
	printf("Tiene %d d%cgitos\n",x,161);
	if(y==1)
		printf("Es par\n");
	else
		printf("Es impar\n");
	printf("La suma de los digitos es %d\n",suma);

	getch();

}

/*
*	Funci�n: contarDigitos
*	Uso: x = contarDigitos(n);
*	---------------------------
*	Descripci�n: Esta funci�n calcula el n�mero de d�gitos de un n�mero n.
*/

int contarDigitos(int z)
{
	int digito;
	int numdig=0;
	while(z>0)
	{
		digito=z%10;
		z=z/10;
 		numdig++;
	}
	return numdig;
}


/*
*	Funci�n: esPar
*	Uso: x = esPar(n);
*	---------------------------
*	Descripci�n: Esta funci�n retorna 1 si n es un n�mero par sino retorna 0.
*/
int esPar(int n)
{
	if(n%2==0)
		return 1;
	else
		return 0;
}

/*
*	Funci�n: sumarDigitos
*	Uso: x = sumarDigitos(n);
*	---------------------------
*	Descripci�n: Esta funci�n suma los d�gitos de un n�mero n.
*/
int sumarDigitos(int n)
{
	int digito;
	int suma=0;
	while(n>0)
	{
		digito=n%10;
		n=n/10;
 		suma = suma + digito;
	}
	return suma;

}