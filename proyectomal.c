/*
*	Archivo: proyecto.c
*	Autores: Ruben Lozano Larrea
*			 Wilson Enriquez Saldana
*			 Irwin Viteri Rambay 			
*	Fecha de creación: 2010-07-28 
*	Fecha de modificacion:2010-07-30
*	HORA: 13-13
*	Descripcion:
*	El juego de mesa conocido como serpientes y escaleras es un juego de azar jugado sobre un 
*	tablero con casillas ilustrado sobre el que los participantes compiten por llegar en primer lugar a
*	la meta. Su principal característica son los dibujos de escaleras  y de serpientes que indican si
*	el participante ha de subir o bajar, respectivamente, dependiendo si su turno, al mover su ficha,
*	lo ha llevado a caer en una casilla que indica el inicio de la escalera o una casilla que coincide
*	con el extremo de una de las serpientes.
*/



												/************************************
												*			LIBRERIAS				*
												************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

												/************************************
												*			CONSTANTES				*
												************************************/


#define MAX 2 //número de jugadores
#define GANA 15//Ultimo bumero del tablero
#define ESCALERA_UNO 3//Avanza a la cassilla 6
#define ESCALERA_DOS 8//Avanza a la cassilla 10
#define SERPIENTE_UNO 5//Retrocede a la casilla 2
#define SERPIENTE_DOS 12//Retrocede a la casilla 9
#define PARTIDAS  5 // número de jugadas que se realizan para preguntar si se desea seguir jugando.
#define NUM_SoE  4  //cantidad de casillas con Ocas
#define RETROCEDE 3//Numeros de espacioque retrocede la serpiente

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

void mostrar_posiciones(int valor[],int casilla);
void mostrar_ganador(int jugadores[],int tam);//Muestra las posiciones y el jugador que mas haya avanzado en el tablero 
void ganador(int fin, int turno,int jugadas);//Muestra el ganador del juego
void mayor_posicion(int valor[],int casilla);
void mostrar_dados(int dado_1,int dado_2);
void encerar(int valor[],int casilla);
void posicionJugador(int jugador);
void mostrar_dado(int dado_1);
void dibujaTablero(void);
void menuPrincipal(void);

bool esEsc_SER(int casilla);
bool dados_iguales();
bool sorteo(int a);

int aumentar_jugada(int turno,int tam,int num_jug);
int sgt_turno(int turno,int tam);
int pasos();

												/************************************
												*	  PROGRAMA PRINCIPAL        *
												************************************/

void main()
{	

												/************************************
												*	      VARIABLES	            *
												************************************/

	int asigna,opcion,seleccion,turno,avanza,oport,num_jugadas,fin;
	int jugador[MAX];
	int contador[MAX];
	int a;
												/************************************
												*	CUERPO DEL PROGRAMA         *
												************************************/


srand(time(NULL));
do{
	do
		{
			system("cls");
			menuPrincipal();
			scanf("%d",&opcion);
		}while(opcion<UN_JUG || opcion>SALIR);

switch(opcion)
{
	
case DEFINIR://Opcion que define el numero de jugadores
		definirJugadores();
		
case SORTEAR://Sortea entre dos juagadores 
	a=definirJugadores();
	asigna=sorteo(a);
			if(asigna==0)
			{	printf("VUELVAN A LANZAR EL DADO");
			}else{
				printf("EL SORTEO SALIO: %d\n",asigna);
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
					oport=3;
					num_jugadas=1;
					fin=0;		
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
								//si esta en una de estás casillas la variable con dicho nombre está con el valor de 1
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
							
							if((jugador[turno]<GANA))//verifico si el jugador esta en la última casilla
							{						
								turno=sgt_turno(turno,a);//si no lo está se pasa el turno al siguiente jugador	
							num_jugadas=aumentar_jugada(turno,a,num_jugadas);//si estoy en el último jugador se aumenta el número de jugadas realizadas
							}
						}while(jugador[turno]<GANA);//si el jugador en turno no está en la última casilla se repite el juego dando el turno al siguiente jugador
						if(oport!=1)
							ganador(fin,turno,num_jugadas);						
				break;
				
				
										/***********CASO DE SER 2 JUGADORES************/
			  case DOS_JUG:
				  	turno=0;
					encerar(jugador,a);
					oport=3;
					num_jugadas=1;
					fin=0;		
					printf("\n\t\t\tJUGARAN %d PERSONAS",a);
					getch();
						do	
						{
							system("cls");
							printf("\t\tjugada numero:%d\n\n",num_jugadas);
							mostrar_posiciones(jugador,a);
							printf("JUGADOR:%d\n",turno+1);	
				if(jugador[turno]!=3 && jugador[turno]!=5 && jugador[turno]!=8 && jugador[turno]!=12)
					//se verifica si está en las casillas Escalera o Serpiente
								{
									//si esta en una de estás casillas la variable con dicho nombre está con el valor de 1
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
							
							if((jugador[turno]<GANA))//verifico si el jugador esta en la última casilla
							{						
								turno=sgt_turno(turno,seleccion);//si no lo está se pasa el turno al siguiente jugador	
								num_jugadas=aumentar_jugada(turno,a,num_jugadas);//si estoy en el último jugador se aumenta el número de jugadas realizadas
							}
						}while(jugador[turno]<GANA);//si el jugador en turno no está en la última casilla se repite el juego dando el turno al siguiente jugador
						if(oport!=1)
							ganador(fin,turno,num_jugadas);						
				break;
			default:
				break;
			
		}		
}while(a<0 || a>MAX);
			break;
		
case SALIR://Opcion salir del juego
			printf("\n\n\n\t\tGracias por usar el programa\n");
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
* Descripción:Esta función retorna true si la casilla enviada como parametro representa una
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
* Descripción:Esta función retorna el número de casillas que el jugador en turno tiene que avanzar.
*/
int pasos()
{	
	int dado_1;
	dado_1=1+rand()%6;
	mostrar_dado(dado_1);
	return (dado_1);
}


/*
* Funcion:sgt_turno
* Uso:sgt_turno(turno,sel);	
* ----------------------------------------------------------
* Descripción:Esta función retorna el turno correspondiente al siguiente jugador
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
* Descripción:Esta función retorna el número de la jugada actual aumentada en 1.
*/
int aumentar_jugada(int turno,int tam,int num_jug)
{
	if(turno==0)
		return num_jug+1;
	return num_jug;
}


/*
* Funcion:dados_iguales
* Uso:dados_iguales();
* ----------------------------------------------------------
* Descripción:Esta función retorna true si los valores de los dados son iguales caso contrario retorna false
*/
bool dados_iguales()
{
	int dado_1,dado_2;
		dado_1=1+rand()%6;
		dado_2=1+rand()%6;
		mostrar_dados(dado_1,dado_2);
		if(dado_1==dado_2)
			return true;
		else 
			return false;
}

/*
* Funcion:sorteo
* Uso:sorteo(seleccion);
* ----------------------------------------------------------
* Descripción:Retorna true si el usuario realizó el sorteo
*/
bool sorteo(int a)
{
	do{
	if(a==0)
	return false;
	else
	{
	if(a==1)
	return true;
	if(a==2)
	return true;
	}
	}while(a<0 || a>MAX);
}

/*
* Funcion:definirJugadores
* Uso:definirJugadores(void);
* ----------------------------------------------------------
* Descripción:Retorna un entero que en este caso puede ser 1 o 2, que es el número de jugadores definidos por el usuario.
*/
int definirJugadores(void)
{	
	int numjugador;
	do{
	printf("\n\nInserte el numero de jugadores:");
	scanf("%d",&numjugador);
	}while(numjugador<1 || numjugador>MAX);
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



												/************************************
												*	      PROCEDIMIENTOS        *
												************************************/

/*
* Procedimiento:mostrar_ganador
* Uso:mostrar_ganador(jugador,sel);
* ----------------------------------------------------------
* Descripción: Este procedimiento Muestra en pantalla el ganador luego de realizarse cada 5 jugadas.
*/
void mostrar_ganador(int jugadores[],int tam)
{
	mostrar_posiciones(jugadores,tam);
	mayor_posicion(jugadores,tam);
return;
}



/*
* Procedimiento:ganador
* Uso:ganador(fin,turno,num_jugadas);
* ----------------------------------------------------------
* Descripción: Este procedimiento Muestra en pantalla el ganador del juego.
*/
void ganador(int fin, int turno,int jugadas)
{
	if(fin!=1)
	{
		
		printf("EL GANADOR ES EL\a\a\n");
		printf("  =============\n");
		printf("  ==JUGADOR %d==\n",turno+1);
		printf("  =============\n");
	}
	printf("\nSE REALIZARON %d JUGADAS",jugadas);
return;
}


/*
* Procedimiento:posicionJugador
* Uso:posicionJugador(jugador[turno]);
* ----------------------------------------------------------
* Descripción: Este procedimiento Muestra en pantalla un mensaje que indica la posición del jugador en pantalla. 
*			   Si la posición en el tablero tiene alguna representación (Serpiente o escalera) el mensaje también lo 
*			   indicará.
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
* Descripción:Esta Procedimiento muestra en pantalla el valor del dado lanzado.
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
* Procedimiento:mostrar_dados
* Uso:mostrar_dados(dado_1,dado_2);
* ----------------------------------------------------------
* Descripción:Esta Procedimiento muestra en pantalla el valor de cada dado lanzado.
*/
void mostrar_dados(int dado_1,int dado_2)
{
	printf("\n\t***************************************\n");
	printf("\t*\tDADO 1\t   *\tDADO 2        *\n");
	printf("\t*\t=======\t   *\t=======       *\n");
	printf("\t*\t=  %d  =\t   *\t=  %d  =       * \n",dado_1,dado_2);
	printf("\t*\t=======\t   *\t=======       *\n");
	printf("\t***************************************\n");

	return;

}


/*
* Procedimiento:encerar
* Uso:encerar(jugador,sel);
* ----------------------------------------------------------
* Descripción:Esta Procedimiento llena de ceros un arreglo de tamaño n enviado como parametro.
*/
void encerar(int valor[],int casillas)
{
	int i;
	for(i=0;i<casillas;i++)
		valor[i]=1;
	return;
}


/*
* Procedimiento:mayor_posicion
* Uso:mayor_posicion(jugador,sel);
* ----------------------------------------------------------
* Descripción:Esta Procedimiento muestra por pantalla el jugador que este mas adelante en el tablero y su posición.
*/
void mayor_posicion(int valor[],int casilla)
{
	int i,jugador;
	int posicion=0;
	for(i=0;i<casilla;i++)
		{
			if(valor[i]>posicion)
			{
				posicion=valor[i];
				jugador=i+1;
			}

		}
	printf("\nEl ganador es el judador:%d\n\n",jugador);
	printf("Se encuentra en la casilla:%d\n",posicion);
return;
}


/*
* Procedimiento:tablero
* Uso:tablero();
* ----------------------------------------------------------
* Descripción:Esta Procedimiento muestra en pantalla un tablero del juego
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
* Descripción:Esta Procedimiento muestra por pantalla los jugadores y sus posiciones en el tablero.
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
* Descripción:Muestra las opciones del menú
*/

void menuPrincipal(void)
{
	system("cls");
	printf("\t	========================================\n");
	printf("\t	============== \t  MENU\t  ==============\n");
	printf("\t	====      \t          \t    ====\n");
	printf("\t\t==== 1. Un Jugador     \t            ====\n");
	printf("\t\t==== 2. Dos Jugadores \t\t    ====\n");
	printf("\t\t==== 3. Iniciar juego \t\t    ====\n");
	printf("\t\t==== 4. Salir \t\t\t    ====\n");
	printf("\t	====      \t          \t    ====\n");
	printf("\t	========================================\n\n");
	printf("\t\t        Escoja una opcion: ");
}




