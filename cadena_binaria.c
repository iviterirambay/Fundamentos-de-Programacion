
/**********************************************************************
*	Archivo: cadena_binaria.c
*	Autor: Felix Rivas
*	Fecha de creacion: 21-01-08
*	Descripcion:
*	
*	Programa que contiene 3 formas de implementacion de la funcion
*	bool Es_Cadena_Bianria(char *Cadena)
*	
*				* Iterativa (usando los indices, for,while,etc)
*				* Usando Punteros 
*				* Recursiva
*
*
**********************************************************************/



#include<stdio.h>
/*********************
*D E F I N I C I O N E S
**********************/
#define MAX 100

typedef enum{false,true}bool;

/*********************
*P R O T O T I P O S
*********************/



/*
*	FUNCION BOOL:  Es_Digito_Binario(char ch)
*	Recibe un caracter y retorna verdadero si el caracter
*	es o '1' o '0'.
*/


bool Es_Digito_Binario(char ch);

/*
*	FUNCION BOOL:  Es_Cadena_Binaria_?(char Cadena[])
*	Se recorre la cadena y retorna verdadero en caso
*	de contener unicamente digitos binarios
*
*/


/*Forma Iterativa*/
bool Es_Cadena_Binaria_I(char Cadena[]);

/*Usando Punteros*/
bool Es_Cadena_Binaria_P(char Cadena[]);

/*Forma Recursiva*/
bool Es_Cadena_Binaria_R(char Cadena[]);



void main()
{


	char Cadena[MAX];

	printf("Ingrese una Cadena:");
	scanf("%s",Cadena);

	printf("\nPrueba de Funcion Iterativa:");

	if(Es_Cadena_Binaria_I(Cadena))
		printf("    Su cadena es Binaria");
	else
		printf("    Su cadena no es Binaria");

		printf("\nPrueba de Funcion usando Punteros:");

	if(Es_Cadena_Binaria_P(Cadena))
		printf("    Su cadena es Binaria");
	else
		printf("    Su cadena no es Binaria");

		printf("\nPrueba de Funcion Recursiva:");

	if(Es_Cadena_Binaria_R(Cadena))
		printf("    Su cadena es Binaria");
	else
		printf("    Su cadena no es Binaria");

	getch();

	


}


bool Es_Digito_Binario(char ch){

	return(ch=='0'||ch=='1');

}
bool Es_Cadena_Binaria_I(char Cadena[])
{
	int i;

	for(i=0;Cadena[i]!='\0';i++)
	{
		if(!Es_Digito_Binario(Cadena[i]))
			return false;
	}
	return true;
}

bool Es_Cadena_Binaria_P(char Cadena[])
{
	char *p;

	for(p=Cadena;*p!='\0';p++)
	{
		if(!Es_Digito_Binario(*p))
			return false;
	}
	return true;
}

bool Es_Cadena_Binaria_R(char Cadena[])
{
	char *p=Cadena;
	
	if(*p=='\0')
		return true;

	if(!Es_Digito_Binario(*p))
		return false;
	else
		return Es_Cadena_Binaria_R(p+1);

}