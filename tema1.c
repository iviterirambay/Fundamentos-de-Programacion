#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

typedef enum {false,true}bool;

bool esCadenaNumerica(char* cadena, int ini, int fin);

main()
{
	char *cadena = malloc(sizeof(char));

	printf("\n\t\t==========TEMA1=============\n");
	printf("\nIngrese la cadena a evaluar[>=0]:\t");
	scanf("%s",cadena);
	printf("\nCadena a evaluar: %s",cadena);
	
	if(esCadenaNumerica( cadena , 0 , (int)strlen(cadena) ))
		printf("\nEs cadena numerica");
	else
		printf("\nNo es cadena numerica");

	_getch();
}

bool esCadenaNumerica(char* cadena, int ini, int fin)
{
	bool result = cadena[ini]>='0' && cadena[ini]<='9';

	if(ini<0) return false ;
	if(ini == fin-1) return result;
	
	return result && esCadenaNumerica(cadena,ini+1,fin);
}