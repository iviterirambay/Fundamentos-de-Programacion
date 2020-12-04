/*
*	Archivo: main.c
*	Autor: V.Cedeno
*	Fecha de creación: 2010-07-06
*	Descripcion:
*	Programa utilizado para mostrar el uso de sentencias de control repetitivas.
*	for, do...while y while.
*	Modificaciones:
*	2010-11-06: se incluyo manejo de funciones y procedimentos (V.Cedeno)
*/
#include <stdio.h>
#define SALIR 4
int suma(int a, int b);
int factorial(int n);
void menu(void);
void main()
{
	int i,n, op, digito;
	int numDig=0;
	do
	{
		do
		{
			menu();
			printf("Ingrese una opcion: ");
			scanf("%d",&op);
		}while(op<=0 || op>SALIR);

		switch(op)
		{
			case 1:
				printf("Ingrese n: ");
				scanf("%d",&n);
				for(i=1;i<=12;i++)
				{
					printf("%3d+%d=%d\n",i,n,suma(i,n));
				}
				getch();
				break;
			case 2:
				numDig=0;
				do
				{
					printf("Ingrese n: ");
					scanf("%d",&n);
				}while(n<=0);
				while(n>0)
				{
					digito=n%10;
					n=n/10;
					numDig++;
					printf("%d ",digito);
					switch(numDig)
					{
						case 1:
							printf("unidades\n");
							break;
						case 2:
							printf("decenas\n");
							break;
						case 3:
							printf("centenas\n");
							break;
						default:
							printf("algo mas que centenas....\n");
					}	
				}
				printf("\nNumero de digitos: %d\n",numDig);
				getch();
				break;
			case 3:

				do
				{
					printf("Ingrese n: ");
					scanf("%d",&n);
				}while(n<0);
				printf("El factorial de %d es %d\n",n,factorial(n));
				getch();


				break;
			case SALIR:
				printf("Fin del programa\n");
				getch();
				break;
			default:
				printf("Opcion no valida\n");
				getch();
		}
	}while(op!=SALIR);

}

/*
*	Funcion: suma
*	Uso: suma(a,b);
*	Descripcion: Retorna la suma de los valores enviados como parámetros.
*/
int suma(int a, int b)
{
	return (a+b);
}
/*
*	Funcion: factorial
*	Uso: factorial(a);
*	Descripcion: Retorna el factorial del número enviado como parámetro.
*/
int factorial(int n)
{
	int fact=1;
	int i;
	for(i=1;i<=n;i++)
		fact=fact*i;
	return fact;
}
/*
*	Procedimiento: menu
*	Uso:menu();
*	Descripcion: Muestra por pantalla el menu principal del programa.
*/
void menu(void)
{
	system("cls");
	printf("++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\t1. Tabla de Sumar\n\t2. Separar un numero en digitos\n\t3. Factorial\n\t4. Salir\n\n");
}

