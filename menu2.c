
*	Archivo: menu.c
*	Autor: Freddy Orosco
*	Descripcion:	Hacer un programa que ingrese dos numeros, mediante un menu poder seleccionar entre
*								sumar o restar dichos numeros; luego presentar dicho resultado en pantalla.
*/

#include <stdio.h>

void main()
{
	int opcion;
	int num1,num2,suma=0,resta=0;
	printf("Ingrese el primer Numero:");
	scanf("%d",&num1);
	printf("Ingrese el segundo Numero:");
	scanf("%d",&num2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,203);//codigo ASCII para hacer un recuadro
	printf("%c    MENU     %c\n",186,186);
	printf("%c  0.- SUMA   %c\n",186,186);
	printf("%c  1.- RESTA  %c\n",186,186);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	printf("Ingrese Eleccion:");
	scanf("%d",&opcion);
	
	switch(opcion)
	{
	case 0:
		{
			suma=num1+num2;
			printf("La suma es:%d",suma);
		}break;
	case 1:
		{
			resta=num1-num2;
			printf("La resta es:%d",resta);
		}break;
	default:
		{
			printf("Opcion No Valida");
		}
	}
	getch();
}