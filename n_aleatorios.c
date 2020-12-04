/* Archivo: n_aleatorios.c
* Autor: Freddy M. Orosco
* Descripción:  Escriba un programa en C, que permita  mostrar por pantalla
*								el contenido de un arreglo de “n” elementos; el arreglo debe ser llenado
*								con números enteros positivos aleatorios entre 15 y 25. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define MAX 50

int gen_aleat(int lim_sup, int lim_inf);
void presentar(int lista[], int tam);
void menu();

void main()
{
	int numf2,n,num1, num2, num_aleat, i;
	int lista[MAX];
	srand(time(NULL));
	do{
			fflush(stdin);
			printf("Ingrese el numero de elementos que desea que tenga el arreglo:\t");
			scanf("%d", &n);
			printf("Ingrese limite inferior:\t");scanf("%d", &num1);
			printf("Ingrese limite superior:\t");scanf("%d", &num2);
			for(i=0;i<n;i++)
				lista[i]=0;
			for(i=0;i<n;i++)
			{
				num_aleat=gen_aleat(num2,num1);
				lista[i]=num_aleat;
			}
				presentar(lista,n);
				menu();
			do{
			printf("Eliga una opcion:");scanf("%d", &numf2);
			}while(numf2<=0||numf2>=3);
			if(numf2==1)
			{
				system("cls");
				printf("Ha elegido la opcion volver a generar numeros aleatorios\n");
			}
			else
				printf("Ha elegido la opcion salir\n");
	}while(numf2==1);
getch();
}

int gen_aleat(int lim_sup, int lim_inf)
{
	return (lim_inf+rand()%(lim_sup-lim_inf+1));
}

void presentar(int lista[], int tam)
{
	int i=0;
	for(i=0;i<tam;i++)
		printf("La celda del archivo lista[%d] es: %d\n",i,lista[i]);
}

void menu()
{
	printf("Desea volver a generar un conjunto de numeros aleatorios\n");
	printf(" ------------- \t\t\t\t  ------------- \n");
	printf("|    1.SI     |\t\t\t\t |   2.SALIR   |\n");
	printf(" ------------- \t\t\t\t  ------------- \n");
}