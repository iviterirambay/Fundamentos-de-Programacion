/*
*	Archivo: amigos.c	
* Autor: Freddy Orosco
*	Descripcion:	Elaborar una función palindromo que retorne 1 si un numero 
*								es palindromo y 0 si no lo es.
*								Un numero es palindromo si al invertir el numero como respuesta
*								obtienes el mismo numero. Ejemplo: 
*								13431 invirtiendo el numero queda 13431 por lo tanto es palindromo
*								9876 invirtiendo el numero queda 6789 por lo tanto no es palindromo
*/

#include <stdio.h>

int palindromo(int n);
int palindromo(int n)
{
	int dig,x,invertido=0;
	x=n;
	while(n>0)
	{
		dig=n%10;
		invertido=(invertido*10)+dig;
		n=n/10;
	}
	if(x==invertido)
		return 1;
	else
		return 0;
}

void main()
{
	int numero,esPalindromo;
	printf("Ingrese un numero:");scanf("%d", &numero);
	esPalindromo=palindromo(numero);
	if(esPalindromo==1)
		printf("El %d es palindromo",numero);
	else
		printf("El %d no es palindromo",numero);
getch();
}