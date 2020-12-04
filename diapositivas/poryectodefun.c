/*
*	Archivo: proyecto.c
*	Autores: Ruben Lozano Larrea
*			 Wilson Enriquez Saldana
*			 Irwin Viteri Rambay 			
*	Fecha de creaci?n:	2010-06-28 
*	Fecha de modificacion:	2010-07-01
*	HORA: 01:51
*	Descripcion:
*	El juego de mesa conocido como serpientes y escaleras es un juego de azar jugado sobre un 
*	tablero con casillas ilustrado sobre el que los participantes compiten por llegar en primer lugar a
*	la meta. Su principal caracter?stica son los dibujos de escaleras  y de serpientes que indican si
*	el participante ha de subir o bajar, respectivamente, dependiendo si su turno, al mover su ficha,
*	lo ha llevado a caer en una casilla que indica el inicio de la escalera o una casilla que coincide
*	con el extremo de una de las serpientes.
*/



												/************************************
												*			LIBRERIAS				*
												************************************/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

												/************************************
												*			CONSTANTES				*
												************************************/


#define MAX 2 //n?mero de jugadores
#define GANA 15//Ultimo bumero del tablero
#define ESCALERA_UNO 3//Avanza a la cassilla 6
#define ESCALERA_DOS 8//Avanza a la cassilla 10
#define SERPIENTE_UNO 5//Retrocede a la casilla 2
#define SERPIENTE_DOS 12//Retrocede a la casilla 9
#define NUM_SoE  4  //cantidad de casillas con Ocas
#define RETROCEDE 3//Numeros de espacio que retrocede la serpiente

typedef enum
{
	false,true
}bool;
typedef enum
{
	UN_JUG=1,DOS_JUG
}menuT;
typedef enum
{
	DEFINIR=1,SORTEAR,INICIAR,SALIR
}menuPrincipalT;


												/************************************
												*			PROTOTIPOS				*
												************************************/

void mostrar_posiciones(int valor[],int casilla);//Muestra las posiciones y el jugador que mas haya avanzado en el tablero 
void ganador(int turno,int jugadas);//Muestra el ganador del juego
void mostrar_dados(int dado_1,int dado_2);
void encerar(int valor[],int casilla);
void posicionJugador(int jugador);
void mostrar_dado(int dado_1);
void dibujaTablero(void);
void menuPrincipal(void);

bool esEsc_SER(int casilla);

int aumentar_jugada(int turno,int tam,int num_jug);
int sgt_turno(int turno,int tam);
int primerJugador(void);
int lanzarDado(void);
int pasos();

												/************************************
												*	  PROGRAMA PRINCIPAL        *
												************************************/

void main()
{	

												/************************************
												*	      VARIABLES	            *
												************************************/

	int opcion,turno,avanza,oport,num_jugadas,fin;
	int jugador[MAX];
	int contador[MAX];
	int a=0,b=0,c=0;
												/************************************
												*	CUERPO DEL PROGRAMA         *
												************************************/


srand(time(NULL));
do{
	do{
			system("cls");
			menuPrincipal();
			scanf("%d",& opcion);
	}while(opcion<UN_JUG || opcion>SALIR);

switch(opcion)
{
	
case DEFINIR://Opcion que define el numero de jugadores
		a=definirJugadores();
	break;

case SORTEAR://Sortea entre dos juagadores 
	
		if((a==0) && (b==0) && (c==0))
		{	
			system("cls");
			printf("No se puede sortear mientras no defina jugadores");
		}else{
			c=primerJugador();
			if(a==2 && c!=0)
			{
				printf("EL SORTEO SALIO: %d\n",c);
				printf("\nEl jugador %d sera el primero en tirar",c);
			}else{
				if(c==0)
				{			
				printf("\nVUELVAN A LANZAR EL DADO");
				}
			}
			if(a==1)
			{	
				system("cls");
				printf("\n\tNO SE SORTEA TURNO PARA UN JUGADOR");	
			}
			
		}
			getch();
				break;

case INICIAR://Opcion inicia el juego

			do{
		switch(a)
		{		
									/***********CASO DE SER 1 JUGADOR**************/
			case UN_JUG:
					turno=0;
					encerar(jugador,a);
					num_jugadas=1;	
					printf("\n\t\t\tJUGARAN %d PERSONAS",a);
					getch();
						do	
						{
							system("cls");
							printf("\t\tjugada numero:%d\n\n",num_jugadas);
							mostrar_posiciones(jugador,a);
							printf("JUGADOR:%d\n",turno+1);
								
								if(jugador[turno]!=3 && jugador[turno]!=5 && jugador[turno]!=8 && jugador[turno]!=12)
								{													 
								//Si esta en una de est?s casillas la variable con dicho nombre est? con el valor de 1
									contador[turno]=0;
									printf("\nTirar DADO\n");
									getch();
									avanza=pasos();
									printf("\navance %d\n\n",avanza);
									jugador[turno]=jugador[turno]+avanza;
									posicionJugador(jugador[turno]);
									switch(jugador[turno])//Identifica la casilla en la que se encuentra el jugador 
									{					  //poniendo la penitencia correspondiente
									
									case ESCALERA_UNO:
										jugador[turno]=6;
										break;
									case ESCALERA_DOS:
										jugador[turno]=10;
										break;
									case SERPIENTE_UNO:
										jugador[turno]=2;
										break;
									case SERPIENTE_DOS:
										jugador[turno]=9;
										break;
									default:
										break;								
									}						
								}
							getch();
							
							if((jugador[turno]<GANA))//verifico si el jugador esta en la ?ltima casilla
							{						
								turno=sgt_turno(turno,a);//si no lo est? se pasa el turno al siguiente jugador	
							num_jugadas=aumentar_jugada(turno,a,num_jugadas);//Si estoy en la ?ltimo casilla jugador se aumenta el n?mero de jugadas realizadas
							}
						}while(jugador[turno]<GANA);//Si el jugador en turno no est? en la ?ltima casilla se repite el juego dando el turno al siguiente jugador
							ganador(turno,num_jugadas);						
				break;
				
				
										/***********CASO DE SER 2 JUGADORES************/
			  case DOS_JUG:
				  	turno=0;
					encerar(jugador,a);
					num_jugadas=1;
					printf("\n\t\t\tJUGARAN %d PERSONAS",a);
					getch();
						do	
						{
							system("cls");
							printf("\t\tjugada numero:%d\n\n",num_jugadas);
							mostrar_posiciones(jugador,a);
							if(c==1)
							{
								printf("JUGADOR:%d\n",turno+1);
							}else{
								printf("JUGADOR:%d\n",turno+c);
							}
				if(jugador[turno]!=3 && jugador[turno]!=5 && jugador[turno]!=8 && jugador[turno]!=12)
					//se verifica si est? en las casillas Escalera o Serpiente
								{
									//si esta en una de est?s casillas la variable con dicho nombre est? con el valor de 1
									contador[turno]=0;
									printf("\nTirar DADO\n");
									getch();
									avanza=pasos();
									printf("\navance %d\n\n",avanza);
									jugador[turno]=jugador[turno]+avanza;
									posicionJugador(jugador[turno]);
									switch(jugador[turno])//identifica la casilla en la que se encuentra el jugador 
									{					  //poniendo la penitencia correspondiente
									
									case ESCALERA_UNO:
										jugador[turno]=6;
										break;
									case ESCALERA_DOS:
										jugador[turno]=10;
										break;
									case SERPIENTE_UNO:
										jugador[turno]=2;
										break;
									case SERPIENTE_DOS:
										jugador[turno]=9;
										break;
									default:
										break;								
									}						
								}
							getch();
							
							if((jugador[turno]<GANA))//verifico si el jugador esta en la ?ltima casilla
							{						
								turno=sgt_turno(turno,a);//si no lo est? se pasa el turno al siguiente jugador	
								num_jugadas=aumentar_jugada(turno,a,num_jugadas);//si estoy en el ?ltimo jugador se aumenta el n?mero de jugadas realizadas
							}
						}while(jugador[turno]<GANA);//si el jugador en turno no est? en la ?ltima casilla se repite el juego dando el turno al siguiente jugador
						ganador(turno,num_jugadas);						
				break;
			default:
				break;
			
		}		
}while((a<0 || a>MAX) && (c<0 || c>MAX));
			break;
		
case SALIR://Opcion salir del juego
			printf("\n\n\n\n\t\t\tGRACIAS POR USAR EL PROGRAMA\n");
		default:
				break;
}
	getch();
	}while(opcion!=SALIR);
}

												/************************************
												*	      FUNCIONES             *
												************************************/

/*
* Funcion:esEsc_SER
* Uso:esEsc_SER(jugador[turno]);
* ----------------------------------------------------------
* Descripci?n:Esta funci?n retorna true si la casilla enviada como parametro representa una
			  escalera o una sepiente caso contrario retorna false
*/
bool esEsc_SER(int casilla)
{	
	int i;
	int Comodin[NUM_SoE]={3,5,8,12};
	for (i=0;i<NUM_SoE;i++)
	{
		if(casilla==Comodin[i])
			return true;
	}
	return false;
}


/*
* Funcion:pasos()
* Uso:pasos();
* ----------------------------------------------------------
* Descripci?n:Esta funci?n retorna el n?mero de casillas que el jugador en turno tiene que avanzar.
*/
int pasos()
{	
	int dado_1;
	dado_1=1+rand()%6;
	mostrar_dado(dado_1);
	return (dado_1);
}

/*
* Funcion:lanzarDado
* Uso:lanzarDado();
* ----------------------------------------------------------
* Descripci?n:Esta Retorna un valor valor aleatorio entre 1 y 6 .
*/
int lanzarDado(void)
{
	int dado;	
	dado=1+rand()%6;
	return dado;

}

/*
* Funcion:sgt_turno
* Uso:sgt_turno(turno,sel);	
* ----------------------------------------------------------
* Descripci?n:Esta funci?n retorna el turno correspondiente al siguiente jugador
*/
int sgt_turno(int turno,int tam)
{
	if(turno==tam-1)
		return 0;		
	else
		return turno+1;
}
/*
* Funcion:aumentar_jugada
* Uso:aumentar_jugada(turno,sel,num_jugadas);
* ----------------------------------------------------------
* Descripci?n:Esta funci?n retorna el n?mero de la jugada actual aumentada en 1.
*/
int aumentar_jugada(int turno,int tam,int num_jug)
{
	if(turno==0)
		return num_jug+1;
	return num_jug;
}


/*
* Funcion:definirJugadores
* Uso:definirJugadores(void);
* ----------------------------------------------------------
* Descripci?n:Retorna un entero que en este caso puede ser 1 o 2, que es el n?mero de jugadores definidos por el usuario.
*/
int definirJugadores(void)
{	
	int numjugador;
	do{
		system("cls");
	printf("\n\nInserte el numero de jugadores:");
	scanf("%d",&numjugador);
	}while(numjugador<0 || numjugador>MAX);
	if(numjugador==1)
	{
		return 1;
		}
		else
		{
		if(numjugador==MAX)
		{
		return 2;
		
		}
	}
}

/*
* Funcion:primerJugador
* Uso:primerJugador(a,b);
* ----------------------------------------------------------
* Descripci?n:Recibe los dos valores de dado que cada jugador recibi? al sortear los turnos. 
*/
int primerJugador(void)
{
	int a; 
	int b;
	system("cls");
	a=lanzarDado();
	b=lanzarDado();
	mostrar_dados(a,b);
	if(a==b)
	{
		return 0;
	}
	else
		{
		if(a>b)
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
}




												/************************************
												*	      PROCEDIMIENTOS        *
												************************************/



/*
* Procedimiento:mostrar_dados
* Uso:mostrar_dados(dado_1,dado_2);
* ----------------------------------------------------------
* Descripci?n:Esta Procedimiento muestra en pantalla el valor de cada dado lanzado.
*/
void mostrar_dados(int dado_1,int dado_2)
{
	printf("\n\t***************************************\n");
	printf("\t*\tDADO 1\t   *\tDADO 2        *\n");
	printf("\t*\tJUGADOR 1  *\tJUGADOR 2     *\n");
	printf("\t*\t=======\t   *\t=======       *\n");
	printf("\t*\t=  %d  =\t   *\t=  %d  =       * \n",dado_1,dado_2);
	printf("\t*\t=======\t   *\t=======       *\n");
	printf("\t***************************************\n");

	return;

}


/*
* Procedimiento:ganador
* Uso:ganador(fin,turno,num_jugadas);
* ----------------------------------------------------------
* Descripci?n: Este procedimiento Muestra en pantalla el ganador del juego.
*/
void ganador(int turno,int jugadas)
{
		
		printf("EL GANADOR ES EL\a\a\n");
		printf("  =============\n");
		printf("  ==JUGADOR %d==\n",turno+1);
		printf("  =============\n");
	
	printf("\nSE REALIZARON %d JUGADAS",jugadas);
return;
}


/*
* Procedimiento:posicionJugador
* Uso:posicionJugador(jugador[turno]);
* ----------------------------------------------------------
* Descripci?n: Este procedimiento Muestra en pantalla un mensaje que indica la posici?n del jugador en pantalla. 
*			   Si la posici?n en el tablero tiene alguna representaci?n (Serpiente o escalera) el mensaje tambi?n lo 
*			   indicar?.
*/
void posicionJugador(int jugador)
{
	int n; 
	printf("Posicion actual %d\n\n",jugador);
	if(esEsc_SER(jugador))
	{
	switch(jugador)
		{	
	case ESCALERA_UNO:
		n=6;
		printf("\nUsted ha caido en una escalera, avanza hasta la casilla %d :)\n",n);
		break;
	case ESCALERA_DOS:
		n=10;
		printf("\nUsted ha caido en una escalera, avanza hasta la casilla %d :)\n",n);
		break;
	case SERPIENTE_UNO:
		n=2;
		printf("\nUsted ha caido en una serpiente, retrocede hasta la casilla %d :(\n",n);
		break;
	case SERPIENTE_DOS:
		n=9;
		printf("\nUsted ha caido en una serpiente, retrocede hasta la casilla %d :(\n",n);
		break;
	default:
		break;
			}
	}
	return;
}




/*
* Procedimiento:mostrar_dado
* Uso:mostrar_dados(dado_1);
* ----------------------------------------------------------
* Descripci?n:Esta Procedimiento muestra en pantalla el valor del dado lanzado.
*/
void mostrar_dado(int dado_1)
{
	printf("\n");
	printf("  DADO  \t   \n");
	printf(" =======\t   \n");
	printf(" =  %d  =\t    \n",dado_1);
	printf(" =======\t   \n");
	return;

}


/*
* Procedimiento:encerar
* Uso:encerar(jugador,seleccion);
* ----------------------------------------------------------
* Descripci?n:Esta Procedimiento llena de ceros un arreglo de tama?o n enviado como parametro.
*/
void encerar(int valor[],int casillas)
{
	int i;
	for(i=0;i<casillas;i++)
		valor[i]=1;
	return;
}


/*
* Procedimiento:tablero
* Uso:tablero();
* ----------------------------------------------------------
* Descripci?n:Esta Procedimiento muestra en pantalla un tablero del juego
*/
void dibujaTablero(void)
{
printf("\n  ============================================================================\n");
printf("  || 1||  2||  3||  4||  5||  6||  7||  8||  9|| 10|| 11|| 12|| 13|| 14|| 15||\n");
printf("  ||  ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||   ||\n");
printf("  ||  || %c || %c  |   || %c || %c ||   || %c || %c || %c ||   || %c ||   ||   || %c ||\n",21,35,21,35,35,21,35,21,01);
printf("  ||  ||   || %c ||   || %c ||   ||   || %c ||   ||   ||   || %c ||   ||   ||   ||\n",16,17,16,17);
printf("  ============================================================================ \n");	
}


/*
* Procedimiento:mostrar_posiciones
* Uso:mostrar_posiciones(jugador,sel);
* ----------------------------------------------------------
* Descripci?n:Esta Procedimiento muestra por pantalla los jugadores y sus posiciones en el tablero.
*/
void mostrar_posiciones(int valor[],int casilla)
{
	int i;
		dibujaTablero();
		printf("\n\t\tJUGADOR\tCASILLA\n");
		for(i=0;i<casilla;i++)
			printf("\t\t%d\t%d\n",i+1,valor[i]);
return;
}


/*
* Procedimiento:menuPrincipal
* Uso:menuPrincipal();
* ----------------------------------------------------------
* Descripci?n:Muestra las opciones del men?
*/

void menuPrincipal(void)
{
	system("cls");
	printf("\t	========================================\n");
	printf("\t	============== \t  MENU\t  ==============\n");
	printf("\t	====      \t          \t    ====\n");
	printf("\t\t====    1. Definir Jugadores  \t    ====\n");
	printf("\t\t====    2. Sortear Turno \t    ====\n");
	printf("\t\t====    3. Iniciar Juego \t    ====\n");
	printf("\t\t====    4. Salir \t\t    ====\n");
	printf("\t	====      \t          \t    ====\n");
	printf("\t	========================================\n\n");
	printf("\t\t        Escoja una opcion: ");