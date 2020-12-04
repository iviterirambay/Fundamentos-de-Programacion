/*Implementar un procedimiento recursivo que dados una cadena y un caracter, 
modifique la cadena reemplazando el caracter dado por un asterisco. 

Por ejemplo:

Dada la cadena “elefante” y el caracter ‘e’ la cadena modificada sería  “*l*fant*”
Dada la cadena “arrullar” y el caracter ‘r’ la cadena modificada sería  “a**ulla*”
*/
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

void modifique(char *s, char c);

main()
{
	char s[MAX]="";
	char c;

	printf("Cadena:");
	gets(s);
	printf("Caracter:");
	scanf("%c",&c);

	modifique(s,c);
	printf("%s",s);
	getch();
}
void modifique(char *cadena, char c)
{
	char *p=cadena;

	if(*p=='\0')
		return;
	else
		if(*p==c)
			*p='*';
	return modifique(p+1,c);

}