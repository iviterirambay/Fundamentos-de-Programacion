/*
	Archivo: buscaminas.c
	Autor: Freddy Orosco
	Descripcion:	Programa que simula una version simplificada del juego Buscaminas:
								Se tiene una matriz de 5X5 (25 cajones) Y a estos se van a asignar 2 clases de constantes
								*MINAS
								*PREMIOS
								El usuario debera ir adivinando en que posicion de una MATRIZ no se encuentran las minas, la matriz a
								mostrarse es la siguiente:
																						01   02   03   04   05
																						06   07   08   09   10
																						11   12   13   14   15
																						16   17   18   19   20
																						21   22   23   24   25
								Y mientras el usuario va adivinando los cajones a salvo se van a ir colocando caritas felices en las 
								posiciones que se vand dejando vacias :). El juego termina si el usuario encuentra todas las posiciones
								que no contienen minas o pierde automaticamente si encuentra una mina.	
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef enum{ false,true }bool;

#define PREMIO 1
#define MINA 2
#define MAX 5
#define VACIO 0

void Llenar_Matriz(int A[][MAX],int tamf, int tamc);
void Mezclar_Matriz(int A[][MAX],int tamf, int tamc);
void Imprimir_Matriz(int A[][MAX],int tamf, int tamc);
void Imprimir_Matriz_Real(int A[][MAX],int tamf, int tamc);
int Verificar_Posicion(int A[][MAX],int tamf, int tamc ,int pos);
bool Matriz_Vacia(int A[][MAX],int tamf, int tamc);

void main()
{

	int Buscaminas[MAX][MAX];
	int pos;
	srand(time(NULL));

	Llenar_Matriz(Buscaminas,MAX,MAX);
	Mezclar_Matriz(Buscaminas,MAX,MAX);	

	do
	{
	   Imprimir_Matriz(Buscaminas,MAX,MAX);
	   do
	   {
			printf("\n\nEscoja la posicion que desea descubrir:");
			scanf("%d",&pos);
			
			if(pos>0)
							pos=Verificar_Posicion(Buscaminas,MAX,MAX,pos);
	   }while(pos<=0);

	}while(!Matriz_Vacia(Buscaminas,MAX,MAX) && pos!=MINA );

	system("cls");

	printf("\nGAME OVER\nMINAS ESCONDIDAS (*):\n\n");
	Imprimir_Matriz_Real(Buscaminas,MAX,MAX);
	
	if(Matriz_Vacia(Buscaminas,MAX,MAX))
        printf("\n\nFelicidades!!! Usted ha Ganado el juego!!\n\n");
	else
		printf("\n\nMINA!!! Lo lamento has perdido el juego :( \n\n");
	
	getch();

}

void Llenar_Matriz(int A[][MAX],int tamf, int tamc)
{
	int i,j,k=1;

	for(i=0;i<tamf;i++)
	{
		for(j=0;j<tamc;j++)
		{
			if(k<=7)							//Permite llenar 7 minas en la matriz desde A[0][0] hasta A[1][1]
				A[i][j]=MINA;
			else	  
				A[i][j]=PREMIO;			//Permite llenar de premios en las casillas restantes.
			k++;
		}
	}

}
void Mezclar_Matriz(int A[][MAX],int tamf, int tamc)
{
	int i,j,veces,l,m,tmp;

	for(veces=0;veces<100;veces++)									//Se mezclara 100 veces
	{
		i=rand()%tamf;
		j=rand()%tamc;
		l=rand()%tamf;
		m=rand()%tamc;

		tmp=A[i][j];											//Permitira "barajar" el contenido de la matriz(mezclar las minas y premios)
		A[i][j]=A[l][m];
		A[l][m]=tmp;
	}
}


void Imprimir_Matriz(int A[][MAX],int tamf, int tamc)
{
	int i,j,k=1;
	
	system("cls");
	printf("\n\nBUSCAMINAS!!!\n\n\n");
	for(i=0;i<tamf;i++)
	{
		for(j=0;j<tamc;j++)
		{
		    if(A[i][j]==VACIO)	
					printf("%c \t",1);					//Solo si el usuario escogio este cajon y no es una mina se imprime una : )
		    else		
					printf("%.2d\t",k);					//Las casillas restantes que aun no han sido escogidas seguiran mostrando su numero.
		    k++;
		}
		printf("\n\n");
	}
}
void Imprimir_Matriz_Real(int A[][MAX],int tamf, int tamc)
{
	int i,j;
																			//Cuando el juego termina se mostrará la matriz total. Si:
	for(i=0;i<tamf;i++)
	{
		for(j=0;j<tamc;j++)
		{
		    if(A[i][j]==MINA)							//Pondra * en donde habian minas
					printf("* \t");
		    else		
					printf("%c \t",1);					//Pondra :) en donde habian premios
		}
		printf("\n\n");
	}
}

int Verificar_Posicion(int A[][MAX],int tamf, int tamc ,int pos)
{
	int i,j,cont=1;

	for(i=0;i<tamf;i++)
	{
		for(j=0;j<tamc;j++)
		{
			if(cont==pos)				//Se irá dentro de la matriz hasta que cont coincida con la pos que el usuario eligio
			{
			  cont=A[i][j];
			  if(cont!=MINA)
					A[i][j]=VACIO;
			  return cont;			//Retorna el contenido de la matriz en dicha posicion
			}
			cont++;
		}
	}
	return VACIO;						//Retorna VACIO si la posicion ingresada es invalida
}
bool Matriz_Vacia(int A[][MAX],int tamf, int tamc)
{

	int i,j;

	for(i=0;i<tamf;i++)
	{
		for(j=0;j<tamc;j++)
		{
		    if(A[i][j]==PREMIO)      //condicion que verifica si aun existe un premio sin descubrir en el juego
					return false;					//Si la condicion se cumple, retorna false que indicará que la matriz aun no esta vacia
		}
	}
	return true;									//retorna true si en el juego ya se encontro todos los premios
}

