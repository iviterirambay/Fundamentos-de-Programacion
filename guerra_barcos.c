/*
* Archivo: Guerra_barcos.c
* Autor:Freddy Orosco
* Descripcion:Programa en c que simula una Guerra de Barcos:
							Supongamos que estamos en un barco lejano y tenemos 7 balas de mucho alcance
							Significa  que tenemos 7 oportunidades  para  dispararle a 7 barcos enemigos
							Estos van   a estar moviendose en  20 espacios que  tiene el mar, el usuario 
							decide a que  espacio (del 1-20) disparar y si yo  logro hundir a 4 de los 7
							barcos, entonces  he ganado la Guerra  de Barcos, caso contrario, ha perdido
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define BARCO 7
#define MAX 20

void Arreglo_Inicializar(int A[],int tam);
void Colocar_Barcos(int A[],int tam,int n_barc);
void Mover_Barcos(int A[],int tam);
void main()
{
	int i,balas=0,tiros_acertados=0;
	int Mar[MAX];
	srand(time(NULL));
	printf("Bienvenido a la consola Guerra de Barcos\n");
	Arreglo_Inicializar(Mar,MAX);
	Colocar_Barcos(Mar,MAX,BARCO);
	while(balas<7)
	{	
	  do{
			printf("Oportunidad %d de 7!!\nEspacio de Mar a disparar:",balas+1);
			scanf("%d",&i);
			if(i<1 || i>MAX)
			printf("Espacio de mar incorrecto, debe escoger del 1-20\n");
    }while(i<1 || i>MAX);
		if(Mar[i-1]==BARCO)
		{
			Mar[i-1]=0;
			tiros_acertados++;
			printf("\nFelicidades!! Le has dado a %d\n",tiros_acertados);
		}
		balas++;
		Mover_Barcos(Mar,MAX);
	}
	if(tiros_acertados>3)
		printf("\nFelicidades, usted ha ganado la Guerra hundiendo %d Barcos!!",tiros_acertados);
	else
		printf("\nLastima, no ganaste la Guerra, %d Barcos hundidos,\nPero animate a jugar otra vez!!",tiros_acertados);
	getch();
}
void Arreglo_Inicializar(int A[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
		A[i]=0;
}
void Colocar_Barcos(int A[],int tam,int n_barc)
{
	int i;
	for(i=0;i<n_barc;i++)
		A[rand()%tam]=BARCO;
}
void Mover_Barcos(int A[],int tam)
{
	int tmp,i,r,o;
	for(i=0;i<MAX;i++)
	{
		r=rand()%tam;
		o=rand()%tam;
		tmp=A[r];
		A[r]=A[o];
		A[o]=tmp;
	}
}