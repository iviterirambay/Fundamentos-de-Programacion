#include <stdio.h>
#include <conio.h>

void convertirNumero(int numero);

main()
{
	printf("\n\t\t===========TEMA2==============\n");
	printf("\nNumero a convertir: 19\tConversion:\t");
	convertirNumero(19);

	printf("\nNumero a convertir: 23\tConversion:\t");
	convertirNumero(23);

	printf("\nNumero a convertir: 45\tConversion:\t");
	convertirNumero(45);

	_getch();
}

void convertirNumero(int numero)
{
	if(numero == 0) return;

	convertirNumero(numero/2);

	printf("%d",numero%2);
}