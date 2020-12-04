/*Escriba la función bool CoincideFinal (char *cadena1, char *cadena2), la cual recibe dos cadenas 
y retorna verdadero si la cadena 2 es la terminación de la cadena 1, caso contrario retorna falso.

Por ejemplo:
CoincideFinal(“cancion”, “cion”) retorna verdadero.
CoincideFinal (“cancion”, “can”) retorna falso.
CoincideFinal (“cancionero”, “cion”) retorna falso.*/

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
typedef enum bool
{false,
true,
}bool;

bool CoincideFinal (char *cadena1, char *cadena2);

main()
{
	char s1[MAX]="",s2[MAX]="";

	printf("Cadena1:");
	scanf("%s",s1);
	printf("Cadena2:");
	scanf("%s",s2);

	if(CoincideFinal(s1,s2))
		printf("Verdadero");
	else
		printf("Falso");
	getch();
}
bool CoincideFinal (char *cadena1, char *cadena2)
{
	int tam1,tam2,pos;
	
	tam1=strlen(cadena1);
	tam2=strlen(cadena2);
	pos=tam1-tam2;
	cadena1=cadena1+pos;
	if(strcmp(cadena1,cadena2)==0)
		return true;
	else 
		return false;
}