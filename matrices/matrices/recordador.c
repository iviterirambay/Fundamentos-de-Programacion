/*
Archivo: memoria.c
Autor: Freddy Orosco
Descripcion:	Simular un juego de memoria. Que se manejará de la siguiente forma:
							Este programa lo que hace es simular un juego memorizador por NIVELES!!
							LOS NIVELES A JUGAR SON 5!!
							Cada vez que se aumenta el nivel aumentaremos la dificultad de la siguiente forma:
	
							Inicialmente se muestra una matriz numerada con ciertos espacios en 00... 
							Los numeros de esos espacios en blanco seran los que el usuario debe memorizar:
							EL PRIMER NIVEL:

							00	02 	03	04	
							00	06	07	00
							09	10	11	12
							13	14	15	16
							17	00	19	20

							En este caso los numeros a memorizar seran 4 y son:	1,5,8,18
							Estos numeros se piden por teclado y si el usuario acierta en los cuatro, pasa al siguiente nivel.
							EL SEGUNDO NIVEL:

							00	02	03	04	
							00	06	07	00
							09	10	11	12
							13	14	15	16
							17	00	19	20  ------>Hasta aqui los mismos del primer nivel
							00	22	23	24
							25	00	27	00

							Ahora los numeros a memorizar son: 1,5,8,18,21,26,28
							Y asi sucesivamente hasta llegar al NIVEL 5!!!

							Cada nivel aumenta 2 filas de numeros, de 4 columnas cada una.
							Si el usuario logro llegar al nivel 5 y logro memorizar todos	entonces GANA!!!!
							Si el usuario se equivoca en un numero PIERDE Y TERMINA EL JUEGO!!!
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define FIL 13
#define COL 5

typedef enum{ false,true }bool;

void Llenar_Matriz(int A[][COL],int tamf, int tamc);
void Insertar_Ceros(int A[][COL],int tamf, int tamc);
void Imprimir_Matriz(int A[][COL],int tamf, int tamc);
void Imprimir_Matriz_Real(int A[][COL],int tamf, int tamc);
int Verificar_Posicion(int A[][COL],int tamf, int tamc ,int pos);
int Numero_de_Ceros(int A[][COL],int tamf, int tamc);

void main()
{
	int Recordador[FIL][COL];
	int pos,nivel=5,turnos,aciertos;
	srand(time(NULL));

	Llenar_Matriz(Recordador,FIL,COL);
  Insertar_Ceros(Recordador,FIL,COL);	
	do
	{
		system("cls");
		printf("\n\nNivel %d\n\n",nivel/2-1);
		Imprimir_Matriz_Real(Recordador,nivel,COL);
	  printf("Digite una tecla para introducir los numeros");
		getch();
	  Imprimir_Matriz(Recordador,nivel,COL);
	  aciertos=0;
	  turnos=Numero_de_Ceros(Recordador,nivel,COL);
	  do
		{
			printf("\n\nDigite los numeros que vio, no importa el orden:");
			scanf("%d",&pos);
		  if(pos>0)
	      pos=Verificar_Posicion(Recordador,nivel,COL,pos);
			if(pos==0)
				aciertos++;
			turnos--;

	   }while(turnos>0);
	
	   turnos=Numero_de_Ceros(Recordador,nivel,COL);
	   if(turnos==aciertos)
		nivel=nivel+2;				// Pasara de nivel y el tamaño de las filas unicamente aumentara en dos si sl usuario memorizo todos numeros anteriores
	   else
		nivel=-1;							//Condicion que permitira terminar el juego. Se sabe q si se falla en un nivel pierdes automaticamente el juego

	}while(nivel<=FIL && nivel>1 );

	system("cls");

	printf("\nGAME OVER\nSUCESION REAL:\n");
	Imprimir_Matriz_Real(Recordador,FIL,COL);
	if(nivel>FIL)
    printf("\n\nFelicidades!!! Usted ha Ganado el juego!!\n\n");
	else
	  printf("\n\nLastima has perdido.\n\n");

	getch();
}

void Llenar_Matriz(int A[][COL],int tamf, int tamc)
{
	int i,j,k=1;

	for(i=0;i<tamf;i++)
	{
		for(j=0;j<tamc;j++)
		{
			A[i][j]=k; //Llena la matriz con numeros consecutivos para cada cajon
			k++;  
		}
	}
}

void Insertar_Ceros(int A[][COL],int tamf, int tamc)
{
	int i,j,k;
	for(k=0;k<13;k++) // Repetira el proceso 13 veces
	{
		do{
		i=rand()%tamf;
		j=rand()%tamc;
		}while(A[i][j]==0);

		A[i][j]=0; //Coloca un cero en una posicion aleatoria de fila y columna de la matriz
	}
}


void Imprimir_Matriz(int A[][COL],int tamf, int tamc)
{
	int i,j,k=1;
	system("cls");
	printf("\n\n***MEMORIZA MEMORIZADOR***\n\n\n");

	for(i=0;i<tamf;i++)
	{
		for(j=0;j<tamc;j++)
		{
		    printf("%.2d\t",k);			//Mostrará en pantalla los cajones disponibles a seleccionar
		    k++;
		}
		printf("\n\n");

	}
}
void Imprimir_Matriz_Real(int A[][COL],int tamf, int tamc)
{
	int i,j;

	for(i=0;i<tamf;i++)
	{
		for(j=0;j<tamc;j++)
		{
		     printf("%.2d\t",A[i][j]);	//Imprime el contenido de la matriz(Puede ser: 0 o el numero del cajon)
		}
		printf("\n\n");
	}
}
int Verificar_Posicion(int A[][COL],int tamf, int tamc ,int pos)
{
	int i,j,cont=1;

	for(i=0;i<tamf;i++)
	{
		for(j=0;j<tamc;j++)
		{
			if(cont==pos)					//condicion que permitira verificar el contenido de la matriz cuando coincida con el cajon seleccionado
			   return A[i][j];	//Retornara el contenido de la posicion seleccinada
			cont++;
		}
	}
	return -1;							// En caso de la posicion ingresada no sea valida retornara -1
}
int Numero_de_Ceros(int A[][COL],int tamf, int tamc)
{
	int i,j,cont=0;

	for(i=0;i<tamf;i++)
	{
		for(j=0;j<tamc;j++)
		{
		  if(A[i][j]==0)	
				cont++;							//Contará el numero de ceros dentro de la matriz.
		}
	}
	return cont;								//retorna el numero de ceros.
}