#ifndef _JUEGO_H
#define _JUEGO_H
#define DIM 15
#define WORDS 94699


typedef struct{
	int puntaje;
	char nombre[30];
}userT;

typedef struct{
	int cantidad;
	int puntos;
	char letra;
}abcT;

void mostrar_tablero(int premios[DIM][DIM],char word[],int palsent,char lista[DIM][DIM]);
void textcolor(int color); 
char **loadWords(char nomDic[], int num_pal);
char minusculas(char word[]);
int letra_puntaje(abcT lista[24],char letra);
int puntaje(char pal[],int premios[DIM][DIM],abcT lista[24], char direccion,int fil, int col);
void guardaJuego(char jugador[30],char tabpalabras[DIM][DIM],abcT stock[24],char mano[7],int puntaje,int disponible, char pal[], int palsent);
int loadGame(FILE *in,char tabpalabras[DIM][DIM],abcT stock[24],char mano[7],int *disponible, char pal[], int palsent[1]);
void top10(userT user);
int palabradiccionario(char **miDic,  int numPal,char pal[]);
void show_option();
void manual();
void dealer(abcT lista[], char mano[7],int *disponible);
int juego(char ingreso[],char direccion,int letrax,int letray,char tabpalabras[DIM][DIM],char mano[7]);
#endif