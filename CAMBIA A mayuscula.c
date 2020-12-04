/*
*	Archivo: copiaMayusMinus.c
*	Autor: V.Cedeno
*	Fecha de creacion: 2010-07-30
*	Descripcion:
*	Programa que lee de un archivo por el usuario. Si el primer caracter del contenido del archivo es
*	minuscula copia el contenido en minuscula en otor archivo. Si el primer caracter del contenido del archivo es
*	mayuscula copia el contenido en mayuscula en otro archivo.
*/
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void copiarArchivo(FILE* entrada,FILE* salida);
main()
{
	FILE *entrada,*salida;
	char nombreArchivo[256];

	printf("Ingrese el nombre del archivo:");
	scanf("%s",nombreArchivo);
	entrada=fopen(nombreArchivo,"r");
	if(entrada==NULL)
	{
		printf("Error al abrir el archivo\n");
		getch();
	}
	salida=fopen("salida.txt","w");
	copiarArchivo(entrada,salida);
	
}
/*
*	Procedimento: copiarArchivo
*	Uso: modifica(a, b);
*	Descripcion: Si el primer caracter del contenido del archivo es
*	minuscula copia el contenido en minuscula. Si el primer caracter del contenido del archivo es
*	mayuscula copia el contenido en mayuscula.
*/
void copiarArchivo(FILE* entrada,FILE* salida)
{

	char c=getc(entrada);

	if(islower(c))
	{
		putc(c,salida);
		while((c=getc(entrada))!=EOF)
		{
			putc(tolower(c),salida);
		}
	}
	else if(isupper(c))
	{
		putc(c,salida);
		while((c=getc(entrada))!=EOF)
		{
			putc(toupper(c),salida);
		}
	}
	fclose(entrada);
	fclose(salida);
	getch();
}