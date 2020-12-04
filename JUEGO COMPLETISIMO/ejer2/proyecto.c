/**********************************************************************************
* Tarea: PROYECTO PARCIAL SEGUNDA PARTE, FUNDAMENTOS DE PROGRAMACION
* Descripcion:SCRABBLE es un juego que permite al usuario escoger las letras de un stock presentados
	por pantalla, un tablero de colores y una palabra en el centro del tablero.
	El usuario va fomando frases de derecha a isquierda y de arriba hasta abajo.
	Todas las fichas usadas en un turno para formar una palabra deben colocarse en una sola fila o en una
	sola columna y de forma adyacente.

* Autor: Gisselle Mariuxi Arcentales Erazo	
		 Mario Andres Barzola Vera
		 Adrian Arturo Alvarado Lay
			
* Clase: FP, 2010-1, Par 2
* Fecha: 8 de Septiembre del 2010
* Prof: Carmen Vaca
* Declaro:	No he recibido ayuda no autorizada
*			para escribir este programa.
* NOMBRE: Juego SCRABBLE
* Input: el jugador ingresara estas palabras añandiendo una o mas fichas a una
	palabra que este colocada en el tablero o colocando una palabra que se cruce con otra que ya esta
	colocada en el tablero el comando es. PALABRAMAGICA,FILA,COLUMNA,ORIENTACION
	Existe el comando FINISH,0,0,0 si no desea seguir jugando y NEXT,0,0,0 si el usuario decide tomar otras
	letras del stock

* Output: Las palabras ingresadas por el usuario se muestran por pantalla en el tablero
	de tal manera que la palabra pueda ser leida horizontal o verticalmente, siempre y cuando 
	el usuario las este ingresando adecuadamente y si dicha palabra existe en el diccionario.
***********************************************************************************/
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "dicc.h"
#include "juego.h"
#define DIM 15
#define WORDS 94699
void main()
{	
	int premios[DIM][DIM]={ 
	{30,0,0,2,0,0,0,30,0,0,0,2,0,0,30},
    {0,20,0,0,0,3,0,0,0,3,0,0,0,20,0},
	{0,0,20,0,0,0,2,0,2,0,0,0,20,0,0},
	{2,0,0,20,0,0,0,2,0,0,0,20,0,0,2},
	{0,0,0,0,20,0,0,0,0,0,20,0,0,0,0},
	{0,3,0,0,0,3,0,0,0,3,0,0,0,3,0},
	{0,0,2,0,0,0,2,0,2,0,0,0,2,0,0},
	{30,0,0,2,0,0,0,20,0,0,0,2,0,0,30},
	{0,0,2,0,0,0,2,0,2,0,0,0,2,0,0},
	{0,3,0,0,0,3,0,0,0,3,0,0,0,3,0},
	{0,0,0,0,20,0,0,0,0,0,20,0,0,0,0},
	{2,0,0,20,0,0,0,2,0,0,0,20,0,0,2},
	{0,0,20,0,0,0,2,0,2,0,0,0,20,0,0},
	{0,20,0,0,0,3,0,0,0,3,0,0,0,20,0},
	{30,0,0,2,0,0,0,30,0,0,0,2,0,0,30},
	}; 
	
	abcT  stock[24];
	userT user;
	FILE *letras;
	FILE *saveprofile;
	
	int letrax,letray,total=0,palIndice,palsent[1],i,j,cont=0,repite,fin=1,next=1;
	char **diccionario;
	long aleatdir;
	char jugador[30],mano[7],tabpalabras[DIM][DIM],ingreso[20],ingresoY[10],ingresoX[10],pal_ramdom[20];
	int *disponible=94;
	char escoge,direccion;

	srand(time(NULL));
	diccionario=loadWords("diccionario.txt",WORDS);	
	show_option();
	do{
		printf("Opcion: ");
		fflush(stdin);
		escoge=getchar();																				
	}while(escoge!=49 && escoge!=50 && escoge!=51);
	switch(escoge){
		
		case (49):{
			system("cls");
			letras=fopen("letras.txt","r");
			while(!feof(letras)){
				fscanf(letras,"%d,%d,%c",&stock[cont].cantidad,&stock[cont].puntos,&stock[cont].letra);
				cont++;
			}
			fclose(letras);
			palsent[0]=(rand()%2);
			aleatdir=1+(rand()%WORDS);
			strcpy(pal_ramdom,diccionario[aleatdir]);
			for(i=0;i<DIM;i++)
				for(j=0;j<DIM;j++)
					tabpalabras[i][j]=' ';
			for(i=0;i<7;i++)
				mano[i]='/';
			manual();
			do{
				system("cls");
				mostrar_tablero(premios,pal_ramdom,palsent[0],tabpalabras);
				textcolor(15);
				dealer(stock,mano,&disponible);
				do{
					do{
						if(next==0){
							next=1;
							system("cls");
							mostrar_tablero(premios,pal_ramdom,palsent[0],tabpalabras);
							textcolor(15);
							dealer(stock,mano,&disponible);
						}
						do{
							printf("Palabra,Fila,Columna,Direccion\n");
							fflush(stdin);
							scanf("%[^,],%[^,],%[^,],%c",ingreso,ingresoX,ingresoY,&direccion);
							letrax=atoi(ingresoX);
							letray=atoi(ingresoY);
							direccion=tolower(direccion);
							if((strcmp(ingreso,"FINISH")==0) && letrax==0 && letray==0 && direccion=='0')
								fin=0;
							if((strcmp(ingreso,"NEXT")==0) && letrax==0 && letray==0 && direccion=='0')
								next=0;
							minusculas(ingreso);
							palIndice=palabradiccionario(diccionario,WORDS,ingreso);
							if(palIndice==-1 && fin!=0 && next!=0)
								printf("La palabra no esta en el diccionario\n\n");
							if(!(letrax>0 && letrax<16 && letray>0 && letray<16)&& fin!=0 && next!=0)
								printf("Fila o Columnas incorrectas\n\n");
							if((direccion!='h'&& direccion!='H'&& direccion!='V'&& direccion!='v') && fin!=0 && next!=0)
								printf("Direccion incorrecto\n\n");

						}while(((palIndice==-1)||(!(letrax>0 && letrax<16 && letray>0 && letray<16))||((direccion!='h'&& direccion!='v'))) && fin!=0 && next!=0);
						if(fin==0){
							printf("\nNombre: ");
							fflush(stdin);
							gets(jugador);
							strcpy(user.nombre,jugador);
							user.puntaje=total;
							top10(user);
							guardaJuego(jugador,tabpalabras,stock,mano,total,disponible,pal_ramdom,palsent[0]);
							exit(0);
						}
						if(next==0){
							mano[rand()%7]='/';
							total=total-3;
							if (total<0)
								total=0;			
						}
					}while(next==0);				
					letrax=letrax-1;
					letray=letray-1;
					repite=juego(ingreso,direccion,letrax,letray,tabpalabras,mano);
				}while(repite<4);
				total=total+puntaje(ingreso,premios,stock,direccion,letrax,letray);
				for(i=0;i<strlen(ingreso);i++){
					if(direccion=='h')
						tabpalabras[letrax][letray+i]=ingreso[i];

					if(direccion=='v')
						tabpalabras[letrax+i][letray]=ingreso[i];					
				}
				printf("Correcto ");Sleep(700);
			}while(disponible>0);
			if(total>50)
				printf("Ganastes");
			else
				printf("Necesitas practicar mas");
			printf("\nIngrese su nombre: ");
			fflush(stdin);
			gets(jugador);
			strcpy(user.nombre,jugador);
			user.puntaje=total;
			top10(user);
			guardaJuego(jugador,tabpalabras,stock,mano,total,disponible,pal_ramdom,palsent[0]);
			break;
		}
		case (50):{
			do{
				printf("\nNombre de partida: ");
				fflush(stdin);
				gets(jugador);
				strcat(jugador,".txt");
				saveprofile=fopen(jugador,"r");
				if((saveprofile)==NULL)
					printf("No existe el archivo %s \n\n",jugador);
			}while(saveprofile==NULL);
			total=loadGame(saveprofile,tabpalabras,stock,mano,&disponible,pal_ramdom,palsent);
			fclose(saveprofile);
			manual();
			do{
				system("cls");
				mostrar_tablero(premios,pal_ramdom,palsent[0],tabpalabras);
				textcolor(15);
				dealer(stock,mano,&disponible);
				do{
					do{
						if(next==0){
							next=1;
							system("cls");
							mostrar_tablero(premios,pal_ramdom,palsent[0],tabpalabras);
							textcolor(15);
							dealer(stock,mano,&disponible);
						}
						do{
							printf("Palabra,Fila,Columna,Direccion\n");
							fflush(stdin);
							scanf("%[^,],%[^,],%[^,],%c",ingreso,ingresoX,ingresoY,&direccion);
							letrax=atoi(ingresoX);
							letray=atoi(ingresoY);
							direccion=tolower(direccion);
							if((strcmp(ingreso,"FINISH")==0) && letrax==0 && letray==0 && direccion=='0')
								fin=0;
							if((strcmp(ingreso,"NEXT")==0) && letrax==0 && letray==0 && direccion=='0')
								next=0;
							minusculas(ingreso);
							palIndice=palabradiccionario(diccionario,WORDS,ingreso);
							if(palIndice==-1 && fin!=0 && next!=0)
								printf("BUSCA EL DICCIONARIO MAS CERCANO\nLa palabra no esta en el diccionario\n\n");
							if(!(letrax>0 && letrax<16 && letray>0 && letray<16)&& fin!=0 && next!=0)
								printf("HABLA BIEN, ESCRIBE CORRECTAMENTE\nFila o Columnas incorrectas\n\n");
							if((direccion!='h'&& direccion!='H'&& direccion!='V'&& direccion!='v') && fin!=0 && next!=0)
								printf("HABLA BIEN, ESCRIBE CORRECTAMENTE\nDireccion incorrecto\n\n");

						}while(((palIndice==-1)||(!(letrax>0 && letrax<16 && letray>0 && letray<16))||((direccion!='h'&& direccion!='v'))) && fin!=0 && next!=0);
						if(fin==0){
							printf("\nNombre: ");
							fflush(stdin);
							gets(jugador);
							strcpy(user.nombre,jugador);
							user.puntaje=total;
							top10(user);
							guardaJuego(jugador,tabpalabras,stock,mano,total,disponible,pal_ramdom,palsent[0]);
							exit(0);
						}
						if(next==0){
							mano[rand()%7]='/';
							total=total-3;
							if (total<0)
								total=0;			
						}
					}while(next==0);				
					letrax=letrax-1;
					letray=letray-1;
					repite=juego(ingreso,direccion,letrax,letray,tabpalabras,mano);
				}while(repite<4);
				total=total+puntaje(ingreso,premios,stock,direccion,letrax,letray);
				for(i=0;i<strlen(ingreso);i++){
					if(direccion=='h')
						tabpalabras[letrax][letray+i]=ingreso[i];

					if(direccion=='v')
						tabpalabras[letrax+i][letray]=ingreso[i];					
				}
				printf("SIMON. Correcto ");Sleep(700);
			}while(disponible>0);
			if(total>50)
				printf("EXCELENTE SUPILINDO\nGanastes");
			else
				printf("QUE PENA... Necesitas practicar mas");
			printf("\nIngrese su nombre: ");
			fflush(stdin);
			gets(jugador);
			strcpy(user.nombre,jugador);
			user.puntaje=total;
			top10(user);
			guardaJuego(jugador,tabpalabras,stock,mano,total,disponible,pal_ramdom,palsent[0]);
			break;
		}
		case(51):{
			printf("\nGracias, juegue otro dia con mas calma...\n\n");
			break;
		}
	}
}
