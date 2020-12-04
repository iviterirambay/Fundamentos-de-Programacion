#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "juego.h"
#define DIM 15
#define WORDS 94699
/*
* Procedimiento: mostrar_tablero
* Uso: mostrar_tablero(int premios[DIM][DIM],char pal[],int palsent,cahr lista[DIM][DIM]);
* --------------------------
* Procedimiento de crea el tablero y lo colorea segun nuestra conveniencia.
*/
void mostrar_tablero(int premios[DIM][DIM],char pal[],int palsent,char lista[DIM][DIM]){
	int i,j,cont=0;
	if (palsent==0){
		for(i=(7-((strlen(pal))/2));cont<(strlen(pal));i++){
			lista[7][i]=pal[cont];
			cont++;
		}
	}
	else{
		for(i=(7-((strlen(pal))/2));cont<(strlen(pal));i++){
			lista[i][7]=pal[cont];
			cont++;
		}
	}
	printf("\n   ");
	for(i=1;i<16;i++){
		textcolor(15);
		printf("%3d",i);
		if(i==15)
			printf("\n");
	}
	printf("\n");
	for(i=1;i<16;i++){
		textcolor(15);
		for(j=1;j<16;j++){
			if(j==1){
				textcolor(15);
				printf("%2d  ",i);
			}
			if(premios[i-1][j-1]==30)
				textcolor(208);
			else if(premios[i-1][j-1]==0)
				textcolor(176);
			else if(premios[i-1][j-1]==20)
				textcolor(223);
			else if(premios[i-1][j-1]==2)
				textcolor(63);
			else if(premios[i-1][j-1]==3)
				textcolor(31);
			printf(" %c ",lista[i-1][j-1]);		
		}
		printf("\n");
	}
}
/*
* Procedimiento: show_option
* Uso: show_option();
* --------------------------
* Procedimiento que muestra el menudo principal
*/
void show_option(){
	printf("\t HELLO EVERY BODY. (presione enter para continuar)");
	getch();
	system("cls");
	printf("\nAHORA COMPROBAREMOS SI LA VISTA ES MUCHO MEJOR QUE LA MANO !!!");
	getch();
	system("cls");
	printf("\nPONGASE SUS ANTEOJOS Y SIENTESE BIEN!!!");
	getch();
	system("cls");
	printf("\nTHIS IS \n\n");
	getch();
	system("cls");
	printf("\n\n\n\t************ S----C----R----A----B----B----L----E **************\n\n");
	getch();
	system("cls");
	printf("        ************ S----C----R----A----B----B----L----E **************\n\n");
	printf("\t MENU PRINCIPAL \n\n");
	printf("\t1)     Nuevo juego \n");
	printf("\t2)     Cargar	  \n");
	printf("\t3)     Salir   \n\n");

}
/*
* Procedimiento: manual()
* Uso: manual();
* --------------------------
* Procedimiento que muestra el manual de usuario del jugador.
*/
void manual(){
	printf("\n\n");
	printf("INSTRUCCIONES:\n\n");
	printf("Como funciona ScrabbleFP? \n\n");
	printf("Cuando comienza la partida la maquina selecciona aleatoriamente:");
	printf("\n1. Una palabra del diccionario\n2. La direccion en la cual se colocara esa palabra (horizontal o verticalmente) y  la palabra seleccionada aleatoriamente se escribe");
	printf("en el centro del tablero.\nLuego se te repartiran 7 letras del stock \nhe intentaras formar una palabra con dos o mas de  de estas letras. ");
	printf("\nA partir de la primera palabra formada por usted, la computadora va reponiendo fichas al usuario obteniendolas del stock. Las fichas se reponen para reemplazar las fichas usadas en la ultima palabra formada.");
	printf("\nCada vez que se obtiene una ficha del stock, este disminuye en esa letra en particular. \nUsted es quien decide seguir o terminar una partida unicamente   colocando este mensaje:\n* FINISH,0,0,0\n o puede decidir escoger otro stock de letras con el comando\n* NEXT,0,0,0. \nEl juego termina cuando usted decide terminar con el comando FINISH ");
	printf("o cuando el stock de letras haya terminado.\nCuando el juego termina le pediremos un nombre de jugador, y si deseas seguir jugando en otra ocacion tendras que seleccionar la opcion 2 del menu y escribir dicho nombre");
	printf(".\nEn cada jugada mostraremos tu puntaje, mucha suerte!!!!");


	getch();
}
/*
* Procedimiento: textcolor
* Uso: textcolor(int color);
* --------------------------
* Procedimiento que colorea todo a partir del punto en que fue usada
*/
void textcolor(int color){
   HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute( handle, 1);
   SetConsoleTextAttribute( handle, color);
}
/*
* Funcion: **loadWords
* Uso: **loadWords(char nomDic[], int num_pal)
* --------------------------
* Esto es un char que devuelve una palabra extraida del diccionario
*/
char **loadWords(char nomDic[], int num_pal){
    int i=0;
    char pal[100];
    char **miDiccionario;
    FILE *fp=fopen(nomDic,"r");
    miDiccionario = (char **)malloc(sizeof(char*)*num_pal);
    while(!feof(fp)) {
        fscanf(fp,"%s",pal);
        miDiccionario[i] = (char*)malloc(sizeof(char)*strlen(pal)+1);
        strcpy(miDiccionario[i],pal);
        i++;
    }
    return miDiccionario;
}
/*
* Funcion: minusculas
* Uso: minusculas(char pal[])
* --------------------------
* Esto es un char que recibe una palabra y las devuelve en minuscula
*/
char minusculas(char pal[]){
	int i;
	for(i=0;i<(strlen(pal));i++)
		pal[i]=tolower(pal[i]);
}
/*
* Funcion: palabradiccionario
* Uso: palabradiccionario(char **miDic,  int numPal,char string[])
* --------------------------
* Esto es un char que recibe el diccionario, el numero de palabras y una palabra ingresada previa-
mente por el usuario y la compara con el diccionario
*/
int palabradiccionario(char **miDic,  int numPal,char string[]){
    int i;
    for(i=0; i<numPal; i++){
        if(strcmp(miDic[i],string)==0)
            return i;
    }
    return -1;
}
/*
* Procedimiento: dealer
* Uso: dealer(abcT lista[],char mano[7],int *disponible);
* --------------------------
* Procedimiento que genera las letras del stock
*/
void dealer(abcT lista[],char mano[7],int *disponible){
	int i,r,k;
	for(i=0;i<7;i++){
		if((mano[i]=='/')&& (*disponible>0)){
			do{
				r=rand()%24;
			}while(lista[r].cantidad<1);
			mano[i]=lista[r].letra;
			(lista[r].cantidad)--;	
			(*disponible)--;
		}		
	}
	printf("\nLetras: ");
	for(k=0;k<7;k++)
		printf("%c  ",mano[k]);
	printf("\n\n");
}
/*
* Funtion: juego
* Uso: juego(char ingreso[],char direccion,int letrax,int letray,char tabpalabras[DIM][DIM],char mano[7])
* --------------------------
* Esta es la funcion mas importante del juego, este permite verificar las palabras ingersadas por el usuario y las valida.
*/
int juego(char ingreso[],char direccion,int letrax,int letray,char tabpalabras[DIM][DIM],char mano[7]){
	int casilla_vacia=0,casilla_llena=0,coincidenT=0,coincidenB=0,i,j;
	char tmp[7];
	for(i=0;i<7;i++)
		tmp[i]=mano[i];
	if(direccion=='h'){
		if((letray+strlen(ingreso))>15){
			printf(":::::::SE TE PASO LA MANO:::::::\nLa palabra se sale del tablero\n");
			return 0;
		}
		for(i=0;i<strlen(ingreso);i++){
			if(tabpalabras[letrax][letray+i]==' ')
				casilla_vacia++;
			else
				casilla_llena++;
		}
		if(casilla_vacia==(strlen(ingreso))){
			printf("******HABLA SERIO....******\nLa casilla esta vacia\n");
			return 1;
		}
		for(i=0;i<strlen(ingreso);i++){
			if(tabpalabras[letrax][letray+i]==ingreso[i])
				coincidenT++;
		}
		if(casilla_llena!=coincidenT){
			printf("::::::COMPRATE UN DICCIONARIO DE BOLSILLO::::\nLas letras no coinciden con las del tablero\n");
			return 2;
		}
		for(i=0;i<strlen(ingreso);i++){
			if(tabpalabras[letrax][letray+i]!=ingreso[i]){
				for(j=0;j<7;j++){		
					if(ingreso[i]==tmp[j]){
						tmp[j]='/';
						coincidenB++;
						j=7;
					}
				}
			}
		}
		if(coincidenB!=casilla_vacia){
			printf("*******ummm. TE HACEN FALTA UNOS ANTEOJOS TACO DE BOLLETA*******\nLas letras no existen en su baraja\n");
			return 3;
		}
	}
	else if(direccion=='v'){
		if((letrax+strlen(ingreso))>15){
			printf(":::::::SE TE PASO LA MANO:::::::\nLa palabra se sale del tablero\n");
			return 0;
		}
		for(i=0;i<strlen(ingreso);i++){
			if(tabpalabras[letrax+i][letray]==' ')
				casilla_vacia++;
			else
				casilla_llena++;
		}
		if(casilla_vacia==(strlen(ingreso))){
			printf("******HABLA SERIO....\nLa casilla esta vacia\n");
			return 1;
		}
		for(i=0;i<strlen(ingreso);i++){
			if(tabpalabras[letrax+i][letray]==ingreso[i])
				coincidenT++;
		}
		if(casilla_llena!=coincidenT){
			printf("::::::COMPRATE UN DICCIONARIO DE BOLSILLO::::\nLas letras no coinciden con las del tablero\n");
			return 2;
		}
		for(i=0;i<strlen(ingreso);i++){
			if(tabpalabras[letrax+i][letray]!=ingreso[i]){
				for(j=0;j<7;j++){
					if(ingreso[i]==tmp[j]){
						tmp[j]='/';
						coincidenB++;
						j=7;
					}
				}
			}
		}
		if(coincidenB!=casilla_vacia){
			printf("*******ummm. TE HACEN FALTA UNOS ANTEOJOS TACO DE BOLLETA*******\nLas letras no existen en su baraja\n");
			return 3;
		}
	}
	for(i=0;i<7;i++)
		mano[i]=tmp[i];
	return 4;
}

/*
* Funtion: letra_puntaje
* Uso: letra_puntaje(abcT lista[24],char letra)
* --------------------------
* esta funcion devuelve un puntaje si la letra coincide con el Stock de letras
*/
int letra_puntaje(abcT lista[24],char letra){
	int i;
	for(i=0;i<24;i++){
		if (letra==lista[i].letra)
			return lista[i].puntos;
	}
}
/*
* Funtion: puntaje
* Uso: puntaje(char pal[],int premios[DIM][DIM],abcT lista[24], char direccion,int fil, int col)
* --------------------------
* esta funcion valida las palabras ingresadas, su orientacion y su posicion,  en caso de estar
todo correcto acumula puntos por tanto de letra o tanto de palabra y lo devuelve.
*/
int puntaje(char pal[],int premios[DIM][DIM],abcT lista[24], char direccion,int fil, int col){
	int i,ptos=0,bono=1,puntos;
	if (direccion=='h'){
		for(i=0;i<strlen(pal);i++){
			switch (premios[fil][col+i]){
				case 0:{
					ptos=ptos+(letra_puntaje(lista,pal[i]));
					break;
				}
				case 2:{
					ptos=ptos+(2*(letra_puntaje(lista,pal[i])));
					break;
				}
				case 3:{
					ptos=ptos+(3*(letra_puntaje(lista,pal[i])));
					break;
				}
				case 20:{
					ptos=ptos+(letra_puntaje(lista,pal[i]));
					bono=bono*2;
					break;
				}
				case 30:{
					ptos=ptos+(letra_puntaje(lista,pal[i]));
					bono=bono*3;
					break;
				}
			}
		}
	}
	if (direccion=='v'){
		for(i=0;i<strlen(pal);i++){
			switch (premios[fil+i][col]){
				case 0:{
					ptos=ptos+(letra_puntaje(lista,pal[i]));
					break;
				}
				case 2:{
					ptos=ptos+(2*(letra_puntaje(lista,pal[i])));
					break;
				}
				case 3:{
					ptos=ptos+(3*(letra_puntaje(lista,pal[i])));
					break;
				}
				case 20:{
					ptos=ptos+(letra_puntaje(lista,pal[i]));
					bono=bono*2;
					break;
				}
				case 30:{
					ptos=ptos+(letra_puntaje(lista,pal[i]));
					bono=bono*3;
					break;
				}
			}
		}
	}
	puntos=ptos*bono;
	return puntos;
}
/*
* Procedimiento: guardaJuego
* Uso: guardaJuego(char jugador[30],char tabpalabras[DIM][DIM],abcT stock[24],char mano[7],int puntaje,int disponible, char pal[], int palsent)
* --------------------------
* Procedimiento guarda el juego si el usuario decide dejar la partida para otro momento, eso si con un nombre personal.
*/
void guardaJuego(char jugador[30],char tabpalabras[DIM][DIM],abcT stock[24],char mano[7],int puntaje,int disponible, char pal[], int palsent){
	FILE *saveprofile;
	int i,j;
	strcat(jugador,".txt");
	saveprofile=fopen(jugador,"w");
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			fprintf(saveprofile,"%c",tabpalabras[i][j]);
			if(j<(DIM-1))
				fprintf(saveprofile,",");
			if(j==(DIM-1))
				fprintf(saveprofile,"\n");
		}
	}
	for(i=0;i<24;i++){
		fprintf(saveprofile,"%d,%d,%c",stock[i].cantidad,stock[i].puntos,stock[i].letra);
		fprintf(saveprofile,"\n");
	}
	for(i=0;i<7;i++){
		fprintf(saveprofile,"%c",mano[i]);
		if(i<6)
			fprintf(saveprofile,",");
		if(i==6)
			fprintf(saveprofile,"\n");
	}
	fprintf(saveprofile,"%d\n",disponible);
	fprintf(saveprofile,"%d\n",puntaje);
	fprintf(saveprofile,"%s\n",pal);
	fprintf(saveprofile,"%d\n",palsent);
	fclose(saveprofile);
}
/*
* Funtion: loadGame
* Uso: loadGame(FILE *in,char tabpalabras[DIM][DIM],abcT stock[24],char mano[7],int *disponible, char pal[], int palsent[])
* --------------------------
* Esta funcion carga el juego nuevamente y devuelve el puntaje anteriormente obtenido.
*/
int loadGame(FILE *in,char tabpalabras[DIM][DIM],abcT stock[24],char mano[7],int *disponible, char pal[], int palsent[]){
	int i,j,puntaje;
	while(!feof(in)){
		for(i=0;i<DIM;i++){
			for(j=0;j<DIM;j++){
				fscanf(in,"%c,",&tabpalabras[i][j]);
			}
			fscanf(in,"%c",&tabpalabras[i][j]);
		}
		for(i=0;i<24;i++){
			fscanf(in,"%d,%d,%c",&stock[i].cantidad,&stock[i].puntos,&stock[i].letra);
		}
		for(j=0;j<7;j++){
				fscanf(in," %c,",&mano[j]);		
		}
		fscanf(in,"%d",disponible);
		fscanf(in,"%d",&puntaje);
		fscanf(in,"%s",pal);
		fscanf(in,"%d",&palsent[0]);
		return puntaje;
	}
}
/*
* Procedimiento: top10
* Uso: top10(userT user)
* --------------------------
* ESte procedimiento como su nombre lo indica, hace una clasificacion del los puntajes 
desde el mas alto hasta el mas bajo....
*/
void top10(userT user){
	int pts[12];
	char jug[12][30];
	int i,j,cont=0,tmp;
	char tmp1[30];
	FILE *archivo;
	for(i=0;i<12;i++){
		pts[i]=0;
		strcpy(jug[i],"");
	}
	archivo=fopen("puntaje.txt","r");
	if(archivo!=NULL){
		while(!feof(archivo))
		{
			fscanf(archivo,"%d,%s",&pts[cont],jug[cont]);
			cont++;
		}
	}
	fclose(archivo);
	pts[cont]=user.puntaje;
	strcpy(jug[cont],user.nombre);
	for(i=0;i<(cont+1);i++){
		for(j=(i+1);j<(cont+1);j++)
		{
			if(pts[j]>=pts[i])
			{
				tmp=pts[i];
				pts[i]=pts[j];
				pts[j]=tmp;
				strcpy(tmp1,jug[i]);
				strcpy(jug[i],jug[j]);
				strcpy(jug[j],tmp1);
			}
		}
	}
	archivo=fopen("puntaje.txt","w");
	for(i=0;i<10;i++)
		fprintf(archivo,"%d,%s\n",pts[i],jug[i]);
	fclose(archivo);	
}