/*Existe un lenguaje llamado chi dif�cil de entender para algunas personas. 
Este lenguaje coloca a continuaci�n de cada s�laba, el t�rmino chi.

Por ejemplo:

Lenguaje chi: 	Vachimoschi  achi  lachi  plachiyachi  ohchi  ohchi  ohchi!!!
Traducci�n: 	Vamos a la playa, oh oh oh!!!

Escriba un programa que traduzca el lenguaje chi a lenguaje natural.  
Este programa permite al usuario ingresar una frase en lenguaje chi 
y mostrar en pantalla su traducci�n. La traducci�n elimina todos los 
chi y mantiene sin modificar el resto de los caracteres.
*/

/*
*	Archivo: lenguajechi.c
*	Autor: V. Cede�o
*	Fecha de creaci�n: 2010-07-28
*	Descripci�n:
*		Programa que traduce el lenguaje chi a lenguaje natural.
*/

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
void traducir(char *cad);

main()
{
   char c[MAX]="";

   printf("Lenguaje chi:");
   gets(c);
   traducir(c);
   getch();
}

/*
*	Procedimiento: traducir
*	Uso: traducir(c);
*	Descripci�n:
*		Este procedimiento traduce la cadena recibida como par�metro.
*/
void traducir(char *cad)
{
   char *frase=cad;
   char *silaba="";
   int pos=0;
   char nueva[100]="";

   while(silaba!=NULL)
   {
   silaba=strstr(frase,"chi");
   pos=(int)(silaba-frase);
   strncat(nueva,frase,pos);
   frase=frase+pos+3;
   }
   printf("Traduccion:%s",nueva);
}
