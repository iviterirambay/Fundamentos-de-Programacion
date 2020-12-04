/*
*	Archivo: buscaReemplazaInvierteDigito.c	
* Autor: Freddy Orosco
*	Descripcion:	Crear una funcion buscaReemplazaInvierteDigito la cual buscara un digito
*								ingresado por teclado en el numero y lo reemplazará por otro. Finalmente
*								Presentará dicho numero con el digito reemplazado e invertido.
*								Ejemplo:
*								113451611
*								busca :1
*								reemplaza por: 9
*								El nuevo numero reemplazado e invertido: 996954399
*/

#include <stdio.h>

int buscaReemplazaInvierteDigito(int numero,int busca,int reemplaza);
int buscaReemplazaInvierteDigito(int numero,int busca,int reemplaza)
{
	int dig,invertido=0;
	while(numero>0)
	{
		dig=numero%10;
		if(dig==busca)
			dig=reemplaza;
		invertido=(invertido*10)+dig;
		numero=numero/10;
	}
		return invertido;
}
void main()
{
	int numero,busca,digBuscar,digReemplaza;
	printf("Ingrese un numero:");scanf("%d", &numero);
	printf("Ingrese un digito a buscar en su numero: ");scanf("%d",&digBuscar);
	printf("Ingrese un digito que reemplazar al buscado: ");scanf("%d",&digReemplaza);
	busca=buscaReemplazaInvierteDigito(numero,digBuscar,digReemplaza);
	printf("Su numero con sus nuevos digitos e invertido es: %d",busca);
	getch();
}