/*
* Autor:Freddy Orosco
* Archivo: Adivina_cerezas.c
* Descripcion:  Programa en c que simula Canastas y cerezas:
								Se tiene 15 canastas, y 5 de ellas contienen cerezas, el usuario va a tener que adivinar
								en cual de las 15 canastas hay cerezas y si este acierta al menos en una de estas,
								el usuario es ganador de un 'premio', caso contrario se le dice al usuario
								que tiene un premio consuelo
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define CEREZA 5
#define MAX 15

void Encerar_canastas(int A[],int tam);
void Colocar_Cerezas(int A[],int tam,int n_cer);
void main()
{
	int i,j=0;
	int Canastas[MAX];
	srand(time(NULL));
	printf("Bienvenido a su juego 'Adivine en donde estan las Cerezas'\n");
	Encerar_canastas(Canastas,MAX);
	Colocar_Cerezas(Canastas,MAX,CEREZA);
	while(j<3)
	{	
	 do{
			printf("\n\nOportunidad %d de 3:\n\n",j+1);
			printf("Usted tiene 15 canastas, en cual de estas cree usted que tiene cerezas??:");
			scanf("%d",&i);
			if(i<1 || i>MAX)
				printf("Canasta incorrecta, debe escoger del 1-15\n");
    }while(i<1 || i>MAX);
	if(Canastas[i-1]==CEREZA)
	   j=MAX;
	else
	   j++;
	}
	if(j==MAX)
		printf("Felicidades Usted encontro cerezas, se lleva un premio!!! :)");
	else
		printf("Sus tres oportunidades terminaron, pero se lleva un premio Consuelo!!\nGracias por jugar!!");
	getch();
}
void Encerar_canastas(int A[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
		A[i]=0;
}
void Colocar_Cerezas(int A[],int tam,int n_cer)
{
	int i;
	for(i=0;i<n_cer;i++)
		A[rand()%tam]=CEREZA;
}