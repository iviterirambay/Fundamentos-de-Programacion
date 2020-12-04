#include <stdio.h>
#include <conio.h>
#include<ctype.h>
#define MAX 200
void copiarArchivo(FILE* entrada,FILE* salida);
main()
{   char s[MAX];
	FILE *entrada,*salida;
	printf("Ingrese el nombre del archivo con su extension:");
	scanf("%s",s);
	entrada=fopen(s,"r");
	if(entrada==NULL)
	{
		printf("Error al abrir el archivo\n");
		getch();
		exit(1);
	}
	salida=fopen("salida.txt","w");
	copiarArchivo(entrada,salida);
}
void copiarArchivo(FILE* entrada,FILE* salida)
{   char c=getc(entrada);
if(c!=EOF && islower(c))
{
	putc(tolower(c),salida);
	while((c=getc(entrada))!=EOF)
	{
		putc(tolower(c),salida);
	}
}
else
if(c!=EOF && isupper(c))
{
	putc(toupper(c),salida);
	while((c=getc(entrada))!=EOF)
	{
		putc(toupper(c),salida);
	}
}
	fclose(entrada);
	fclose(salida);
	getch();
}
