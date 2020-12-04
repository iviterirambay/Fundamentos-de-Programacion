/*
*  Archivo:tareFinal.c
*  Autora: Gianina Anabell Vallejo Gordillo
*  Fecha de creación: 2010-08-20
*  Descripción:
*  El programa es una versión electrónica reducida del juego
*  “Serpientes y Escaleras” version 2.0, la cual permite a un jugador,
*  o dos participar del juego que permite el uso de ciertas funciones.
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

#define TAM 15
#define NOM 30
#define MAX 10

typedef enum
{    
	false = 0,
	true = 1
}bool;

typedef struct{
	char nombre[30];
	int veces;
}jugadorT;

void menuPrincipal();
void ftablero(FILE *tablero);
int definirJugadores(void);
int lanzarDado(void);
int primerJugador(int a, int b);
bool sorteo(int a);
void declararGanador (char * nombre);
int cargarDatos(FILE *archivo);
void guardarPartida(FILE * archivo,int turno,char *nombre1,int casilla1, char *nombre2,int casilla2);
void cargarPartida(FILE * archivo,int *turno,char *nombre1,int *casilla1, char *nombre2,int *casilla2);
int cargarJugadores(jugadorT jugadores[],char jugador[30]);
void ordenarTop(jugadorT jugadores [],int tamanio);
void flogo(FILE *autora);
void ftop(FILE *top);

void main()
{
	//Declaracion de variables
	int n,dado1,dado2,op,numjug=0,sort=0,posicion1=0,posicion2=0,a,w;
	int cargar,espacio,turno=0,ganador=0,resp,tamanio=1,enTop;
	char nombre1[NOM]=" ",nombre2[NOM]=" ",uno[NOM]="-1",turnoNum[TAM]=" ",posicion1a[NOM]=" ",posicion2a[NOM]=" ";
	//Cree el archivo juego
	FILE *tablero,*guardar,*top,*impTop,*autora,*juego;
	jugadorT jug[MAX];

	srand(time(NULL));

	do
	{
		system("cls");
		do
		{
			system("cls");
			menuPrincipal();
			scanf("%d",&op);
		}while(op<1 && op>7);

		switch(op)
		{
		case 1:
			system("cls");
			printf("\n\n\t1. Definir numero de jugadores\n");
			numjug=definirJugadores();		
			printf("\n\tUsted eligio %d jugador(es)",numjug);
			if (numjug==1)
			{
				printf("\n\n\n\tIngrese su nombre:");
				scanf("%s",nombre1);
			}
			else
			{
				printf("\n\n\n\tIngrese su nombre jugador 1:");
				scanf("%s",nombre1);
				printf("\n\tIngrese su nombre jugador 2:");
				scanf("%s",nombre2);
			}
			break;

		case 2:
			if (numjug==0)
			{
				printf("\n\tPrimero debe definir el numero de jugadores");
			}

			if(numjug==1||numjug==2)
			{
				if(numjug==1)
				{
					printf("\n\tEs solo un jugador, no debe sortear los turnos.\n\tPuede iniciar el juego");
					sort=1;
				}
				else
				{
					system("cls");
					printf("\n\n\t2. Sortear turnos\n");
					printf("\n\n\tPresione una tecla para lanzar el dado...\n");
					getch();

					dado1=lanzarDado();
					printf("\n\t %s: el dado cayo en %d",nombre1,dado1);

					dado2=lanzarDado();
					printf("\n\t %s: el dado cayo en %d\n\n",nombre2,dado2);

					a=primerJugador(dado1,dado2);

					if(primerJugador(dado1,dado2)==1)
					{
						printf("\n\tEmpieza el %s\n",nombre1);
						sort=1;
					}
					else
					{
						if(primerJugador(dado1,dado2)==2)
						{
							printf("\n\tEmpieza el %s\n",nombre2);
							sort=1;
						}
						else
						{
							(primerJugador(dado1,dado2)==0);
							printf("\n\tHubo un empate\n\n\tLance el dado otra vez, por favor\n");
							sort=0;
						}
					}
					w=sorteo(a);
					if (w==true)
						printf("\n\tNo se definio que jugador empieza,lance otra vez los dados.");
					else
						printf("\n\tSe definio que jugador empieza");
				}
			}
			getch();
			break;

		case 3:
			system("cls");
			if (numjug==0)
			{
				printf("\n\tPrimero debe definir el numero de jugadores");
			}
			if (numjug==1)
			{
				sort=1;
			}
			if (sort==1)
			{
				tablero = fopen("tablero2.txt","r");
				if (tablero==NULL)
				{
					printf("\n\tError al abrir el archivo");
					getch();
					exit(1);
				}
				ftablero(tablero);

				posicion1=1;
				posicion2=1;
				if(numjug==1)
				{
					printf("\n\tSi en algun momento desea detener la \n\tpartida presione la barra espaciadora\n");
					printf("\n\t%s Su posicion inicial es %d",nombre1,posicion1);
					do
					{
						resp=2;
						printf("\n\n\tPresione una tecla para lanzar el dado...\n\t");
						getch();
						dado1=lanzarDado();
						printf("\n\t%s: el dado cayo en %d",nombre1,dado1);
						switch(posicion1+dado1)
						{
						case 4:
							w=8;
							printf("\n\tUsted ha caido es una escalera, avanza 8 espacios");
							getch();
							break;
						case 8: 
							w=22;
							printf("\n\tUsted ha caido es una escalera, avanza 22 espacios");
							getch();
							break;
						case 15:
							w=20;
							printf("\n\tUsted ha caido es una escalera, avanza 20 espacios");
							getch();
							break;
						case 31: 
							w=-18;
							printf("\n\tUsted ha caido es una serpiente, retrocede 18 espacios");
							getch();
							break;
						case 46: 
							w=-3;
							printf("\n\tUsted ha caido es una serpiente, retrocede 3 espacios");
							getch();
							break;
						case 48: 
							w=-42;
							printf("\n\tUsted ha caido es una serpiente, retrocede 42 espacios");
							getch();
							break;
						default:
							w=0;
							getch();
							break;
						}
						posicion1=posicion1+dado1+w;
						printf("\n\tSu posicion es:%d\n",posicion1);

						espacio=getch();

						if(espacio==32)
						{
							do
							{
								printf("\n\tSi desea salir del juego y grabar la partida\n\tpresione 1 caso contrario presione2: ");
								scanf("%d",&resp);
							}while(resp<1||resp>2);

							if(resp==1)
							{
								guardar=fopen("juegoSyE.ptd","w");
								if(guardar==NULL)
								{
									printf("\n\tError al abrir el archivo");
									getch();
									exit(1);
								}
								turno=1;
								posicion2=0;

								guardarPartida(guardar,turno,nombre1,posicion1,nombre2,posicion2);
								break;

							}
							else
							{
								if(resp==2)
									guardar=fopen("juegoSyE.ptd","w");
								if(guardar==NULL)
								{
									printf("\n\tError al abrir el archivo");
									getch();
									exit(1);
								}
								fputs(uno,guardar);
							}
						}
					}while(posicion1<50&&resp==2);
					if (posicion1>=50)
						declararGanador(nombre1);
					enTop=cargarJugadores(jug,nombre1);
				}
				else
				{
					if(primerJugador(dado1,dado2)==1)
					{
						printf("\n\t%s su posicion inicial es %d",nombre1,posicion1);
						printf("\n\t%s su posicion inicial es %d",nombre2,posicion2);
						//Abri el archivo juego.txt en modo de escritura y le imprimo el nombre del jugador y la posicion
						juego=fopen("juego.txt","w");
						fprintf(juego,"%s: %d\n",nombre1,posicion1);
						fprintf(juego,"%s: %d\n",nombre2,posicion2);

						if(primerJugador(dado1,dado2)==1)
							printf("\n\n\tEmpieza %s\n",nombre1);
						else
						{
							if(primerJugador(dado1,dado2)==2)
								printf("\n\n\tEmpieza %s\n",nombre2);
						}
						do
						{

							resp=2;
							printf("\n\n\tPresione una tecla para lanzar el dado...\n\t");
							getch();
							dado1=lanzarDado();
							printf("\n\t%s: el dado cayo en %d",nombre1,dado1);
							switch(posicion1+dado1)
							{
							case 4:
								w=8;
								printf("\n\tUsted ha caido es una escalera, avanza 8 espacios");
								getch();
								break;
							case 8: 
								w=22;
								printf("\n\tUsted ha caido es una escalera, avanza 22 espacios");
								getch();
								break;
							case 15:
								w=20;
								printf("\n\tUsted ha caido es una escalera, avanza 20 espacios");
								getch();
								break;
							case 31: 
								w=-18;
								printf("\n\tUsted ha caido es una serpiente, retrocede 18 espacios");
								getch();
								break;
							case 46: 
								w=-3;
								printf("\n\tUsted ha caido es una serpiente, retrocede 3 espacios");
								getch();
								break;
							case 48: 
								w=-42;
								printf("\n\tUsted ha caido es una serpiente, retrocede 42 espacios");
								getch();
								break;
							default:
								w=0;
								getch();
								break;
							}
							posicion1=posicion1+dado1+w;
							printf("\n\tSu posicion es:%d",posicion1);
							//le imprimo el nombre del jugador y la posicion
							fprintf(juego,"%s: %d\n",nombre1,posicion1); 

							espacio=getch();

							if(espacio==32)
							{
								do
								{
									printf("\n\n\tSi desea salir del juego y grabar la partida\n\tpresione 1 caso contrario presione2: ");
									scanf("%d",&resp);
								}while(resp<1||resp>2);

								if(resp==1)
								{
									guardar=fopen("juegoSyE.ptd","w");
									if(guardar==NULL)
									{
										printf("\n\tError al abrir el archivo");
										getch();
										exit(1);
									}
									turno=1;
									guardarPartida(guardar,turno,nombre1,posicion1,nombre2,posicion2);
									break;
								}
								else
								{
									if(resp==2)
										guardar=fopen("juegoSyE.ptd","w");
									if(guardar==NULL)
									{
										printf("\n\tError al abrir el archivo");
										getch();
										exit(1);
									}
									fputs(uno,guardar);
								}
							}

							if(turno!=1)
							{
								printf("\n\n\tPresione una tecla para lanzar el dado...\n\t");
								getch();
								dado2=lanzarDado();
								printf("\n\t%s: el dado cayo en %d",nombre2,dado2);
								switch(posicion2+dado2)
								{
								case 4:
									w=8;
									printf("\n\tUsted ha caido es una escalera, avanza 8 espacios");
									getch();
									break;
								case 8: 
									w=22;
									printf("\n\tUsted ha caido es una escalera, avanza 22 espacios");
									getch();
									break;
								case 15:
									w=20;
									printf("\n\tUsted ha caido es una escalera, avanza 20 espacios");
									getch();
									break;
								case 31: 
									w=-18;
									printf("\n\tUsted ha caido es una serpiente, retrocede 18 espacios");
									getch();
									break;
								case 46: 
									w=-3;
									printf("\n\tUsted ha caido es una serpiente, retrocede 3 espacios");
									getch();
									break;
								case 48: 
									w=-42;
									printf("\n\tUsted ha caido es una serpiente, retrocede 42 espacios");
									getch();
									break;
								default:
									w=0;
									getch();
									break;
								}
								posicion2=posicion2+dado2+w;
								printf("\n\t%s su posicion es:%d",nombre2,posicion2);
								//le imprimo el nombre del jugador y la posicion
								fprintf(juego,"%s: %d\n",nombre2,posicion2);

								espacio=getch();

								if(espacio==32)
								{
									do
									{
										printf("\n\n\tSi desea salir del juego y grabar la partida\n\tpresione 1 caso contrario presione2: ");
										scanf("%d",&resp);
									}while(resp<1||resp>2);

									if(resp==1)
									{
										guardar=fopen("juegoSyE.ptd","w");
										if(guardar==NULL)
										{
											printf("\n\tError al abrir el archivo");
											getch();
											exit(1);
										}
										turno=2;
										guardarPartida(guardar,turno,nombre1,posicion1,nombre2,posicion2);
										break;
									}
									else
									{
										if(resp==2)
											guardar=fopen("juegoSyE.ptd","w");
										if(guardar==NULL)
										{
											printf("\n\tError al abrir el archivo");
											getch();
											exit(1);
										}
										fputs(uno,guardar);
									}
								}
							}

						}while(posicion1<50&&posicion2<50&&resp==2);

						if(posicion1>=50||posicion2>=50)
						{

							if(posicion1>posicion2)
							{
								declararGanador(nombre1);
								enTop=cargarJugadores(jug,nombre1);
								printf("en el top %d",enTop);
							}
							else
							{
								if (posicion1<posicion2)
								{
									declararGanador(nombre2);
									ganador=1;
									enTop=cargarJugadores(jug,nombre2);
									printf("en el top %d",enTop);
								}
								else
								{
									printf("\n\n\t*****  Hubo un empate  *****\n\t*****  Vuelvan a jugar  *****");
								}
							}
						}
					}

					else
					{
						if(primerJugador(dado1,dado2)==2)
						{
							printf("\n\t%s su posicion inicial es %d",nombre1,posicion1);
							printf("\n\t%s su posicion inicial es %d",nombre2,posicion2);
							//Abro el archivo juego.txt en modo de escritura, le imprimo el nombre del jugador y la posicion
							juego=fopen("juego.txt","w");
							fprintf(juego,"%s: %d\n",nombre1,posicion1);
							fprintf(juego,"%s: %d\n",nombre2,posicion2);

							if(primerJugador(dado1,dado2)==1)
								printf("\n\n\tEmpieza %s\n",nombre1);
							else
							{
								if(primerJugador(dado1,dado2)==2)
									printf("\n\n\tEmpieza %s\n",nombre2);
							}

							do
							{
								resp=2;
								printf("\n\n\tPresione una tecla para lanzar el dado...\n\t");
								getch();
								dado2=lanzarDado();
								printf("\n\t%s: el dado cayo en %d",nombre2,dado2);
								switch(posicion2+dado2)
								{
								case 4:
									w=8;
									printf("\n\tUsted ha caido es una escalera, avanza 8 espacios");
									getch();
									break;
								case 8: 
									w=22;
									printf("\n\tUsted ha caido es una escalera, avanza 22 espacios");
									getch();
									break;
								case 15:
									w=20;
									printf("\n\tUsted ha caido es una escalera, avanza 20 espacios");
									getch();
									break;
								case 31: 
									w=-18;
									printf("\n\tUsted ha caido es una serpiente, retrocede 18 espacios");
									getch();
									break;
								case 46: 
									w=-3;
									printf("\n\tUsted ha caido es una serpiente, retrocede 3 espacios");
									getch();
									break;
								case 48: 
									w=-42;
									printf("\n\tUsted ha caido es una serpiente, retrocede 42 espacios");
									getch();
									break;
								default:
									w=0;
									getch();
									break;
								}
								posicion2=posicion2+dado2+w;
								printf("\n\t%s su posicion es:%d",nombre2,posicion2);
								//le imprimo el nombre del jugador y la posicion
								fprintf(juego,"%s: %d\n",nombre2,posicion2);

								espacio=getch();

								if(espacio==32)
								{
									do
									{
										printf("\n\n\tSi desea salir del juego y grabar la partida\n\tpresione 1 caso contrario presione2: ");
										scanf("%d",&resp);
									}while(resp<1||resp>2);

									if(resp==1)
									{
										guardar=fopen("juegoSyE.ptd","w");
										if(guardar==NULL)
										{
											printf("\n\tError al abrir el archivo");
											getch();
											exit(1);
										}
										turno=2;
										guardarPartida(guardar,turno,nombre1,posicion1,nombre2,posicion2);
										break;
									}
									else
									{
										if(resp==2)
											guardar=fopen("juegoSyE.ptd","w");
										if(guardar==NULL)
										{
											printf("\n\tError al abrir el archivo");
											getch();
											exit(1);
										}
										fputs(uno,guardar);
									}
								}

								if(turno!=2)
								{
									printf("\n\n\tPresione una tecla para lanzar el dado...\n\t");
									getch();
									dado1=lanzarDado();
									printf("\n\t%s: el dado cayo en %d",nombre1,dado1);
									switch(posicion1+dado1)
									{
									case 4:
										w=8;
										printf("\n\tUsted ha caido es una escalera, avanza 8 espacios");
										getch();
										break;
									case 8: 
										w=22;
										printf("\n\tUsted ha caido es una escalera, avanza 22 espacios");
										getch();
										break;
									case 15:
										w=20;
										printf("\n\tUsted ha caido es una escalera, avanza 20 espacios");
										getch();
										break;
									case 31: 
										w=-18;
										printf("\n\tUsted ha caido es una serpiente, retrocede 18 espacios");
										getch();
										break;
									case 46: 
										w=-3;
										printf("\n\tUsted ha caido es una serpiente, retrocede 3 espacios");
										getch();
										break;
									case 48: 
										w=-42;
										printf("\n\tUsted ha caido es una serpiente, retrocede 42 espacios");
										getch();
										break;
									default:
										w=0;
										getch();
										break;
									}
									posicion1=posicion1+dado1+w;
									printf("\n\t%s su posicion es:%d",nombre1,posicion1);
									//le imprimo el nombre del jugador y la posicion
									fprintf(juego,"%s: %d\n",nombre1,posicion1);

									espacio=getch();

									if(espacio==32)
									{
										do
										{
											printf("\n\n\tSi desea salir del juego y grabar la partida\n\tpresione 1 caso contrario presione2: ");
											scanf("%d",&resp);
										}while(resp<1||resp>2);

										if(resp==1)
										{
											guardar=fopen("juegoSyE.ptd","w");
											if(guardar==NULL)
											{
												printf("\n\tError al abrir el archivo");
												getch();
												exit(1);
											}
											turno=1;
											guardarPartida(guardar,turno,nombre1,posicion1,nombre2,posicion2);
											break;
										}
										else
										{
											if(resp==2)
												guardar=fopen("juegoSyE.ptd","w");
											if(guardar==NULL)
											{
												printf("\n\tError al abrir el archivo");
												getch();
												exit(1);
											}
											fputs(uno,guardar);
										}
									}
								}

							}while(posicion2<50&&posicion1<50&&resp==2);


							if(posicion1>=50||posicion2>=50)
							{
								if(posicion1>posicion2)
								{
									declararGanador(nombre1);
									ganador=1;
									enTop=cargarJugadores(jug,nombre1);
									printf("en el top %d",enTop);
								}
								else
								{
									if (posicion1<posicion2)
									{
										declararGanador(nombre2);
										ganador=1;
										enTop=cargarJugadores(jug,nombre2);
										printf("en el top %d",enTop);
									}
									else
									{
										printf("\n\n\t*****  Hubo un empate  *****\n\t*****  Vuelvan a jugar  *****");
									}
								}
							}
						}
					}
				}
			}
			else
			{
				printf("\n\n\tSe debe realizar el sorteo");
			}
			getch();
			break;

		case 4:
			system("cls");
			if(ganador==1)
			{
				printf("\n\tEl juego anterior sí fue terminado");
				break;
			}
			guardar=fopen("juegoSyE.ptd","r");
			if(guardar==NULL)
			{
				printf("\n\tError al abrir el archivo");
				getch();
				exit(1);
			}
			cargar=cargarDatos(guardar);
			if(cargar==1)
			{
				cargarPartida(guardar,&turno,nombre1,&posicion1,nombre2,&posicion2);

				tablero = fopen("tablero2.txt","r");
				if (tablero==NULL)
				{
					printf("\n\tError al abrir el archivo");
					getch();
					exit(1);
				}
				ftablero(tablero);

				if(posicion2==0)
				{

					printf("\n\tSi en algun momento desea detener la \n\tpartida presione la barra espaciadora\n\t");
					printf("\n\t %s su posicion inicial es %d",nombre1,posicion1);
					do
					{
						resp=2;
						printf("\n\n\t Presione una tecla para lanzar el dado...\n\t");
						getch();
						dado1=lanzarDado();
						printf("\n\t %s: el dado cayo en %d",nombre1,dado1);
						switch(posicion1+dado1)
						{
						case 4:
							w=8;
							printf("\n\tUsted ha caido es una escalera, avanza 8 espacios");
							getch();
							break;
						case 8: 
							w=22;
							printf("\n\tUsted ha caido es una escalera, avanza 22 espacios");
							getch();
							break;
						case 15:
							w=20;
							printf("\n\tUsted ha caido es una escalera, avanza 20 espacios");
							getch();
							break;
						case 31: 
							w=-18;
							printf("\n\tUsted ha caido es una serpiente, retrocede 18 espacios");
							getch();
							break;
						case 46: 
							w=-3;
							printf("\n\tUsted ha caido es una serpiente, retrocede 3 espacios");
							getch();
							break;
						case 48: 
							w=-42;
							printf("\n\tUsted ha caido es una serpiente, retrocede 42 espacios");
							getch();
							break;
						default:
							w=0;
							getch();
							break;
						}
						posicion1=posicion1+dado1+w;
						printf("\n\tSu posicion es:%d\n",posicion1);

						turno=1;
						posicion2=0;

						espacio=getch();

						if(espacio==32)
						{
							do
							{
								printf("\n\tSi desea salir del juego y grabar la partida\n\tpresione 1 caso contrario presione2: ");
								scanf("%d",&resp);
							}while(resp<1||resp>2);

							if(resp==1)
							{
								guardar=fopen("juegoSyE.ptd","w");
								if(guardar==NULL)
								{
									printf("\n\tError al abrir el archivo");
									getch();
									exit(1);
								}
								guardarPartida(guardar,turno,nombre1,posicion1,nombre2,posicion2);
								break;
							}
							else
							{
								if(resp==2)
									guardar=fopen("juegoSyE.ptd","w");
								if(guardar==NULL)
								{
									printf("\n\tError al abrir el archivo");
									getch();
									exit(1);
								}
								fputs(uno,guardar);
							}
						}
					}while(posicion1<50&&resp==2);

					if (posicion1>=50)
						declararGanador(nombre1);
					enTop=cargarJugadores(jug,nombre1);
				}
				else
				{
					if(turno==1)
					{
						turno=3;
						printf("\n\t%s su posicion inicial es %d",nombre1,posicion1);
						printf("\n\t%s su posicion inicial es %d",nombre2,posicion2);
						//Abro el archivo juego.txt en modo de escritura,le imprimo el nombre del jugador y la posicion
						juego=fopen("juego.txt","w");
						fprintf(juego,"%s: %d\n",nombre1,posicion1);
						fprintf(juego,"%s: %d\n",nombre2,posicion2);

						do
						{

							resp=2;
							printf("\n\n\tPresione una tecla para lanzar el dado...\n\t");
							getch();
							dado1=lanzarDado();
							printf("\n\t%s: el dado cayo en %d",nombre1,dado1);
							switch(posicion1+dado1)
							{
							case 4:
								w=8;
								printf("\n\tUsted ha caido es una escalera, avanza 8 espacios");
								getch();
								break;
							case 8: 
								w=22;
								printf("\n\tUsted ha caido es una escalera, avanza 22 espacios");
								getch();
								break;
							case 15:
								w=20;
								printf("\n\tUsted ha caido es una escalera, avanza 20 espacios");
								getch();
								break;
							case 31: 
								w=-18;
								printf("\n\tUsted ha caido es una serpiente, retrocede 18 espacios");
								getch();
								break;
							case 46: 
								w=-3;
								printf("\n\tUsted ha caido es una serpiente, retrocede 3 espacios");
								getch();
								break;
							case 48: 
								w=-42;
								printf("\n\tUsted ha caido es una serpiente, retrocede 42 espacios");
								getch();
								break;
							default:
								w=0;
								getch();
								break;
							}
							posicion1=posicion1+dado1+w;
							printf("\n\tSu posicion es:%d",posicion1);
							//le imprimo el nombre del jugador y la posicion
							fprintf(juego,"%s: %d\n",nombre1,posicion1);

							espacio=getch();

							if(espacio==32)
							{
								do
								{
									printf("\n\n\tSi desea salir del juego y grabar la partida\n\tpresione 1 caso contrario presione2: ");
									scanf("%d",&resp);
								}while(resp<1||resp>2);

								if(resp==1)
								{
									guardar=fopen("juegoSyE.ptd","w");
									if(guardar==NULL)
									{
										printf("\n\tError al abrir el archivo");
										getch();
										exit(1);
									}
									turno=1;
									guardarPartida(guardar,turno,nombre1,posicion1,nombre2,posicion2);
									break;
								}
								else
								{
									if(resp==2)
										guardar=fopen("juegoSyE.ptd","w");
									if(guardar==NULL)
									{
										printf("\n\tError al abrir el archivo");
										getch();
										exit(1);
									}
									fputs(uno,guardar);
								}
							}

							if(turno!=1)
							{
								printf("\n\n\tPresione una tecla para lanzar el dado...\n\t");
								getch();
								dado2=lanzarDado();
								printf("\n\t%s: el dado cayo en %d",nombre2,dado2);
								switch(posicion2+dado2)
								{
								case 4:
									w=8;
									printf("\n\tUsted ha caido es una escalera, avanza 8 espacios");
									getch();
									break;
								case 8: 
									w=22;
									printf("\n\tUsted ha caido es una escalera, avanza 22 espacios");
									getch();
									break;
								case 15:
									w=20;
									printf("\n\tUsted ha caido es una escalera, avanza 20 espacios");
									getch();
									break;
								case 31: 
									w=-18;
									printf("\n\tUsted ha caido es una serpiente, retrocede 18 espacios");
									getch();
									break;
								case 46: 
									w=-3;
									printf("\n\tUsted ha caido es una serpiente, retrocede 3 espacios");
									getch();
									break;
								case 48: 
									w=-42;
									printf("\n\tUsted ha caido es una serpiente, retrocede 42 espacios");
									getch();
									break;
								default:
									w=0;
									getch();
									break;
								}
								posicion2=posicion2+dado2+w;
								printf("\n\t%s su posicion es:%d",nombre2,posicion2);
								//le imprimo el nombre del jugador y la posicion
								fprintf(juego,"%s: %d\n",nombre2,posicion2);

								espacio=getch();

								if(espacio==32)
								{
									do
									{
										printf("\n\n\tSi desea salir del juego y grabar la partida\n\tpresione 1 caso contrario presione2: ");
										scanf("%d",&resp);
									}while(resp<1||resp>2);

									if(resp==1)
									{
										guardar=fopen("juegoSyE.ptd","w");
										if(guardar==NULL)
										{
											printf("\n\tError al abrir el archivo");
											getch();
											exit(1);
										}
										turno=2;
										guardarPartida(guardar,turno,nombre1,posicion1,nombre2,posicion2);
										break;
									}
									else
									{
										if(resp==2)
											guardar=fopen("juegoSyE.ptd","w");
										if(guardar==NULL)
										{
											printf("\n\tError al abrir el archivo");
											getch();
											exit(1);
										}
										fputs(uno,guardar);
									}
								}
							}

						}while(posicion1<50&&posicion2<50&&resp==2);

						if(posicion1>=50||posicion2>=50)
						{

							if(posicion1>posicion2)
							{
								declararGanador(nombre1);
								enTop=cargarJugadores(jug,nombre1);
								printf("en el top %d",enTop);
							}
							else
							{
								if (posicion1<posicion2)
								{
									declararGanador(nombre2);
									enTop=cargarJugadores(jug,nombre2);
									printf("en el top %d",enTop);
								}
								else
								{
									printf("\n\n\t*****  Hubo un empate  *****\n\t*****  Vuelvan a jugar  *****");
								}
							}
						}
					}

					else
					{
						if(turno==2)
						{
							turno=3;
							printf("\n\t%s su posicion inicial es %d",nombre1,posicion1);
							printf("\n\t%s su posicion inicial es %d",nombre2,posicion2);
							//Abro el archivo juego.txt en modo de escritura,le imprimo el nombre del jugador y la posicion
							juego=fopen("juego.txt","w");
							fprintf(juego,"%s: %d\n",nombre1,posicion1);
							fprintf(juego,"%s: %d\n",nombre2,posicion2);
							

							do
							{
								resp=2;
								printf("\n\n\tPresione una tecla para lanzar el dado...\n\t");
								getch();
								dado2=lanzarDado();
								printf("\n\t%s: el dado cayo en %d",nombre2,dado2);
								switch(posicion2+dado2)
								{
								case 4:
									w=8;
									printf("\n\tUsted ha caido es una escalera, avanza 8 espacios");
									getch();
									break;
								case 8: 
									w=22;
									printf("\n\tUsted ha caido es una escalera, avanza 22 espacios");
									getch();
									break;
								case 15:
									w=20;
									printf("\n\tUsted ha caido es una escalera, avanza 20 espacios");
									getch();
									break;
								case 31: 
									w=-18;
									printf("\n\tUsted ha caido es una serpiente, retrocede 18 espacios");
									getch();
									break;
								case 46: 
									w=-3;
									printf("\n\tUsted ha caido es una serpiente, retrocede 3 espacios");
									getch();
									break;
								case 48: 
									w=-42;
									printf("\n\tUsted ha caido es una serpiente, retrocede 42 espacios");
									getch();
									break;
								default:
									w=0;
									getch();
									break;
								}
								posicion2=posicion2+dado2+w;
								printf("\n\t%s su posicion es:%d",nombre2,posicion2);
						        //le imprimo el nombre del jugador y la posicion
								fprintf(juego,"%s: %d\n",nombre2,posicion2);

								espacio=getch();

								if(espacio==32)
								{
									do
									{
										printf("\n\n\tSi desea salir del juego y grabar la partida\n\tpresione 1 caso contrario presione2: ");
										scanf("%d",&resp);
									}while(resp<1||resp>2);

									if(resp==1)
									{
										guardar=fopen("juegoSyE.ptd","w");
										if(guardar==NULL)
										{
											printf("\n\tError al abrir el archivo");
											getch();
											exit(1);
										}
										turno=2;
										guardarPartida(guardar,turno,nombre1,posicion1,nombre2,posicion2);
										break;
									}
									else
									{
										if(resp==2)
											guardar=fopen("juegoSyE.ptd","w");
										if(guardar==NULL)
										{
											printf("\n\tError al abrir el archivo");
											getch();
											exit(1);
										}
										fputs(uno,guardar);
									}
								}

								if(turno!=2)
								{
									printf("\n\n\tPresione una tecla para lanzar el dado...\n\t");
									getch();
									dado1=lanzarDado();
									printf("\n\t%s: el dado cayo en %d",nombre1,dado1);
									switch(posicion1+dado1)
									{
									case 4:
										w=8;
										printf("\n\tUsted ha caido es una escalera, avanza 8 espacios");
										getch();
										break;
									case 8: 
										w=22;
										printf("\n\tUsted ha caido es una escalera, avanza 22 espacios");
										getch();
										break;
									case 15:
										w=20;
										printf("\n\tUsted ha caido es una escalera, avanza 20 espacios");
										getch();
										break;
									case 31: 
										w=-18;
										printf("\n\tUsted ha caido es una serpiente, retrocede 18 espacios");
										getch();
										break;
									case 46: 
										w=-3;
										printf("\n\tUsted ha caido es una serpiente, retrocede 3 espacios");
										getch();
										break;
									case 48: 
										w=-42;
										printf("\n\tUsted ha caido es una serpiente, retrocede 42 espacios");
										getch();
										break;
									default:
										w=0;
										getch();
										break;
									}
									posicion1=posicion1+dado1+w;
									printf("\n\t%s su posicion es:%d",nombre1,posicion1);
									//le imprimo el nombre del jugador y la posicion
									fprintf(juego,"%s: %d\n",nombre1,posicion1);

									espacio=getch();

									if(espacio==32)
									{
										do
										{
											printf("\n\n\tSi desea salir del juego y grabar la partida\n\tpresione 1 caso contrario presione2: ");
											scanf("%d",&resp);
										}while(resp<1||resp>2);

										if(resp==1)
										{
											guardar=fopen("juegoSyE.ptd","w");
											if(guardar==NULL)
											{
												printf("\n\tError al abrir el archivo");
												getch();
												exit(1);
											}
											turno=1;
											guardarPartida(guardar,turno,nombre1,posicion1,nombre2,posicion2);
											break;
										}
										else
										{
											if(resp==2)
												guardar=fopen("juegoSyE.ptd","w");
											if(guardar==NULL)
											{
												printf("\n\tError al abrir el archivo");
												getch();
												exit(1);
											}
											fputs(uno,guardar);
										}
									}
								}

							}while(posicion2<50&&posicion1<50&&resp==2);


							if(posicion1>=50||posicion2>=50)
							{
								if(posicion1>posicion2)
								{
									declararGanador(nombre1);
									enTop=cargarJugadores(jug,nombre1);
									printf("en el top %d",enTop);
								}
								else
								{
									if (posicion1<posicion2)
									{
										declararGanador(nombre2);
										enTop=cargarJugadores(jug,nombre2);
										printf("en el top %d",enTop);
									}
									else
									{
										printf("\n\n\t*****  Hubo un empate  *****\n\t*****  Vuelvan a jugar  *****");
									}
								}
							}
						}
					}
				}

			}

			else
			{
				printf("\n\tNo se han guardado datos");
			}

			getch();
			break;
		case 5:
			system("cls");
			top=fopen("top.txt","r");
			ftop(top);
			getch();
			break;
		case 6:
			system("cls");
			autora=fopen("autora.txt","r");
			flogo(autora);
			break;
		}
	}while(op!=6);
	getch();

}



/*
* Procedimiento: menuPrincipal
* Uso: menuPrincipal();
* ----------------------------------------------------------
* Descripción: Este procedimiento muestra el menú utilizado en el proyecto.
*/
void menuPrincipal()
{
	printf("\n\n\t -----> Bienvenidos a Escalera y Serpientes <-----\n\n");
	printf("\t	Que se diviertan!\n\n");
	printf("\t1.	Definir numero de jugadores\n");
	printf("\t2.	Sortear turnos\n");
	printf("\t3.	Nueva partida\n");
	printf("\t4.	Continuar partida\n");
	printf("\t5.	Top 10\n");
	printf("\t6.	Salir\n");
	printf("\n\n\tIngrese una opcion: ");
}

/*
* Procedimiento: flogo
* Uso: ftablero(tablero);
* -------------------------------------------------------------------------
* Descripción: Este procedimiento grafica el tablero guardado en un archivo
*/
void ftablero(FILE *tablero)
{
	//Declaracion de variables
	char c='0';
	while((c=getc(tablero))!=EOF)
	{
		printf("%c",c);
	}
}
/*
* Función: definirJugadores
* Uso: definirJugadores();
* ----------------------------------------------------------
* Descripción: Retorna un entero que en este caso puede ser 1 o 2,
* que es el número de jugadores definidos por el usuario. Se debe
* validar que el usuario ingrese solamente el número 1 o 2.
*/
int definirJugadores(void)
{
	//Declaracion de variables
	int def;

	do{
		printf("\n\tDefina el numero de jugadores:");
		scanf("%d",&def);
	}while(def<1 || def>2);
	return def;

}

/*
* Función: lanzarDado
* Uso: lanzarDado();
* ----------------------------------------------------------
* Descripción: Retorna un número aleatorio del 1 al 6 que representa
* que el jugador lanzara un dado para jugar.
*/
int lanzarDado(void)
{
	//Declaracion de variables
	int dado;
	dado = rand()%6+1;
	return dado;
}

/*
* Función: primerJugador
* Uso: primerJugador(a,b);
* ----------------------------------------------------------
* Descripción: Recibe los dos valores de dado que cada jugador 
* recibió al sortear los turnos. El entero a representa al jugador 1,
* el entero b representa al jugador 2. Retorna el entero 1 o 2 para
* indicar el jugador que inicia la partida. El jugador que inicia la
* partida es el que tuvo el número mayor Retorna 0 si los valores de 
* a y b son iguales y hay un empate
*/
int primerJugador(int a, int b)
{
	if(a>b)
	{
		return 1;
	}
	else
	{
		if (a<b)
		{
			return 2;
		}
		return 0;
	}
}
/*
* Función: sorteo
* Uso: sorteo(a);
* ----------------------------------------------------------
* Descripción: Retorna true si el usuario realizó el sorteo.
* El entero a es el primer jugador, el cual puede ser 0, 1 ó 2.
* Retorna false si a es 0, ya que no se definido quién empieza
* primero, de lo contrario retorna true.
*/
bool sorteo(int a)
{
	if (a==false)
		return true;
	else 
		return false;
}
/*
* Procedimiento: declararGanador
* Uso: declararGanador(nombre1);
* ----------------------------------------------------------
* Descripción: Este procedimiento recibe el nombre del ganador 
* e imprime en pantalla una felicitación por ganar el juego
*/
void declararGanador (char *nombre)
{
	//Declaracion de variables
	int ganador;

	printf("\n\n\t*****  %s Usted ha ganado  *****\n\t*****  Felicidades  *****",nombre);
	ganador=1;
}
/*
* Procedimiento: guardarPartida
* Uso: guardarPartida(guardar,turno,nombre1,posicion1,nombre2,posicion2);
* -----------------------------------------------------------------------------------------------------
* Descripción: Este procemiento graba en un archivo llamado juegoSyE.ptd los datos que permitirán 
* dar continuidad a una partida iniciada. A parte de recibir el archivo en el cual se guardará, 
* recibe turno en juego, nombre del jugador1, casilla del jugador 1, nombre del jugador2 
* y casilla del jugador 2. El archivo se guarda con el formato especificado en la descripción del proyecto.
*/
void guardarPartida(FILE *archivo,int turno,char *nombre1,int casilla1, char *nombre2,int casilla2)
{
	//Declaracion de variables
	char turnop[7]="turno ";

	fputs(turnop,archivo);
	fprintf(archivo," %d",turno);
	fputs("\n",archivo);
	fputs(nombre1,archivo);
	fprintf(archivo," %d",casilla1);
	fputs("\n",archivo);
	fputs(nombre2,archivo);
	fprintf(archivo," %d",casilla2);
}
/*
* Función: cargarDatos
* en Uso: cargar=cargarDatos(guardar);
* ----------------------------------------------------------------
* Descripción: Esta función lee un archivo y retorna un entero que 
* en este caso puede ser -1, que indica que no hay ningún juego 
* grabado ya que el archivo llamado juegoSyE.ptd contendrá el valor 
* de -1. La función retorna 1 si hay un juego grabado 
*/
int cargarDatos(FILE *archivo)
{
	//Declaracion de arreglos
	char turnoAbajo[TAM]=" ";
	char *comp;

	fgets(turnoAbajo,2,archivo);
	comp=strstr(turnoAbajo,"-");
	if(comp=="-1")
		return -1;
	else
		return 1;
}
/*
* Procedimiento: cargarPatida
* Uso: cargarPartida(guardar);
* ----------------------------------------------------------------
* Descripción: Este procedimiento lee un archivoy obtiene el turno en juego,
* nombre del jugador1, casilla del jugador 1, nombre del jugador2 y casilla del jugador 2.
*/
void cargarPartida(FILE * archivo,int *turno,char *nombre1,int *casilla1, char *nombre2,int *casilla2)
{
	char temp[NOM]=" ";
	int turnoa,posiciona,posicionb;
	fscanf(archivo,"%[^ ] %d",temp,&turnoa);
	*turno=turnoa;
	fscanf(archivo,"%[^ ] %d",nombre1,&posiciona);
	*casilla1=posiciona;
	fscanf(archivo,"%[^ ] %d",nombre2,&posicionb);
	*casilla2=posicionb;
}
/*
* Función: cargarJugadores
* Uso: cargarJugadores(jug,nombre1);
* ----------------------------------------------------------------------
* Descripción: Esta función Recibe el archivo que contiene los jugadores 
* top, el arreglo de estructuras de jugador y el nombre del nuevo jugador 
* a ingresar. Devuelve el número de jugadores en el archivo top. 
*/
int cargarJugadores(jugadorT jugadores[],char jugador[30])
{
	int i=0, k=0,j=0;
	//Creo la variable total y la inicializo con cero.
	int flag=0,total=0;
	FILE *top;
	FILE *ganadores;
	jugadorT temp[101]={0,0};
	char cadena[NOM];
	ganadores=fopen("ganadores.txt","r");

	if (ganadores==NULL)
	{
		top=fopen("ganadores.txt","w");
		strcpy(temp[i].nombre,jugador);
		temp[i].veces=1;
		fprintf(ganadores,"[TOP10]\n%s %d",temp[i].nombre,temp[i].veces);
	}
	else
	{
		fscanf(ganadores,"%s",cadena);
		while(!(feof(ganadores))){

			fscanf(ganadores,"%s",temp[k].nombre);
			fscanf(ganadores,"%d",&temp[k].veces);
			k++;
		}
		for(i=0;i<10;i++){
			if(strcmp(temp[i].nombre,jugador)==0){
				temp[i].veces++;
				flag=1;
			}
		}
		if(flag!=1){
			strcpy(temp[k].nombre,jugador);
			temp[k].veces=1;
		}else
			k--;
		ordenarTop(temp,k+1);
		fclose(ganadores);
		top=fopen("top.txt","w");
		fprintf(top,"[TOP10]\n");
		for(i=0;i<=10;i++)
		{	fprintf(top,"%s %d\n",temp[i].nombre,temp[i].veces);
			//Calculo el total de los puntajes en el top
			total=total+temp[i].veces;
		}
		fprintf(top,"%s %d\n","Total:",total);
		ganadores=fopen("ganadores.txt","w");
		fprintf(ganadores,"[TOP10]\n");
		for(j=0;j<k;j++)
			fprintf(ganadores,"%s %d\n",temp[j].nombre,temp[j].veces);
	}
	fclose(top);
	fclose(ganadores);
	if (k<10)
		return k;
	else
		return 10;
}
/*
* Procedimiento: ordenarTop
* Uso: ordenarTop(jug,enTop);
* ------------------------------------------------------------------------
* Descripción: Este procedimiento Recibe el archivo donde se guardarán 
* jugadores top, el arreglo de estructuras de nombre y jugador y su tamaño,
* para poder ordenarlos de menor a mayor.
*/
void ordenarTop(jugadorT jugadores[],int tamanio)
{
	int i;
	jugadorT abajo[NOM];

	if(tamanio==1)
		return;
	else
	{
		for(i=0;i<(tamanio-2);i++)
		{
			if((jugadores[i].veces)==(jugadores[i+1].veces))
			{

			}
			else
				if((jugadores[i].veces)<(jugadores[i+1].veces))
				{
				}
				else
				{
					strcpy(abajo[0].nombre,jugadores[i].nombre);
					abajo[0].veces=jugadores[i].veces;
					strcpy(jugadores[i].nombre,jugadores[i+1].nombre);
					jugadores[i].veces=jugadores[i+1].veces;
					strcpy(jugadores[i+1].nombre,abajo[0].nombre);
					jugadores[i+1].veces=abajo[0].veces;
				}
		}
	}
}
/*
* Procedimiento: flogo
* Uso: flogo(autora);
* ----------------------------------------------------------------------------------------
* Descripción: Este procedimiento muestra un mensaje de fin de programa incluyendo mi logo.
*/
void flogo(FILE *autora)
{
	//Declaracion de variables
	char c='0';
	while((c=getc(autora))!=EOF)
	{
		printf("%c",c);
	}
}
/*
* Procedimiento: ftop
* Uso: ftop(FILE *top)
* ----------------------------------------------------------------------------------------
* Descripción: Este procedimiento muestra un mensaje de fin de programa incluyendo mi logo.
*/
void ftop(FILE *top)
{
	//Declaracion de variables
	char c='0';
	while((c=getc(top))!=EOF)
	{
		if(c=='\n')
			printf("\n");
		printf("%c",c);
	}
}