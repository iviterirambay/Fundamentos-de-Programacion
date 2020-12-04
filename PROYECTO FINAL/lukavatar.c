#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct{
	int avance;
	int veces;
	char nombre[11];
}JugadorT;

typedef struct{
	int comodines[5][10];
	char matriz[5][10];
}TableroT;

void colocarFicha(JugadorT gam[], int turno, TableroT *tab, int *fil, int *col);
void analizarCasilla(JugadorT gam[], int turno, TableroT *tab, int *fil, int *col);
void buscarConsecuente(TableroT tab, int num, int *fil, int *col);
void ImprimirMensaje(int num, JugadorT gam[], int turno);
void dibujar_tablero_juego();
int registrarGanador(JugadorT gam[]);
void ordenaTop(JugadorT temp[], int tam);
void guardarPartida(JugadorT gam[], int turno, TableroT tab, FILE *in);
int cargaPartida(JugadorT gam[], int *turno, int *njug);
void menuPrincipal();

void main(){
	FILE *sav, *in;
	int n=0, k, r, r1, r2, nd, fila=-1, columna=-1, temp, option, p1=0, aux;
	char tecla, opt, cadena[30];
	JugadorT gamer[2]={0,0};
	TableroT table={{{0,0,0,7,0,4,0,11,0,0},
	{0,8,2,0,9,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,12},
	{1,0,0,0,0,0,0,0,0,0},
	{0,0,6,0,10,5,0,3,0,0}}};
	srand(time(NULL));


	for(n=0;n<5;n++){
		for(k=0;k<10;k++)
			table.matriz[n][k]=' ';
	}

	do{
		menuPrincipal();
		do{
			scanf("%d",&option);
		}while(option>6||option<1);

		if(option==4){
			printf("Se procedera a reanudar la partid\n");
			aux=cargaPartida(gamer,&r,&n);
			getch();
			if(aux!=0){
				option=3;
				p1=2;
			}else
				option=6;
		}

		if(option==1&&p1==0){
			printf("Elija el numero de jugadores (1 o 2): ");
			do{
				scanf("%d", &n);
			}while(n!=2&&n!=1);
			if(n==2){
				for(k=0; k<n; k++){
					printf("Ingres el nombre de jugador %d: ", k+1);
					fflush(stdin);
					gets(gamer[k].nombre);
				}
				p1=1;
			}else{
				printf("Ingres el nombre del jugador: ");
				fflush(stdin);
				gets(gamer[0].nombre);
				r=0;
				temp=r;
				p1=2;
			}
		}

		if(option==3&&p1==2){
			do{
				system("cls");
				dibujar_tablero_juego();
				printf("Turno: %s\n", gamer[r].nombre);
				printf("Presione + para lanzar dado, barra espaciadora para salir o guardar la partida:");
				do{
					tecla=getch();
				}while(tecla!='+'&&tecla!=' ');
				switch (tecla){
					case '+':
						if(gamer[r].avance!=0)
							printf("\nEsta en la casilla %d",gamer[r].avance);
						nd=(rand()%6)+1;
						gamer[r].avance+=nd;
						if(gamer[r].avance>50)
							gamer[r].avance=50;
						printf("\nDADO: %d", nd);
						colocarFicha(gamer, r, &table, &fila, &columna);
						analizarCasilla(gamer, r, &table, &fila, &columna);
						getch();
						if(n!=1){
							temp=r;
							r=(r+1)%2;
						}
						break;
					case ' ':
						printf("Presiones < s > para salir o < g > para guardar: ");
						do{
							opt=getch();
						}while(opt!='s'&&opt!='g');
						if(opt=='g'){
							printf("\nSu partida se procedera a guardar.....\n");
							guardarPartida(gamer, r, table, &sav);
							printf("Partida salvada\n");
							opt='s';
						}else{
							sav=fopen("juegoSyE.ptd","w");
							fprintf(sav,"-1");
							fclose(sav);
						}
						break;
				}		
			}while(gamer[temp].avance<50&&opt!='s');
			if(opt!='s'){
				gamer[temp].veces=1;
				printf("FELICITACIONES!!!!! < %s > GANO\n",gamer[temp].nombre);
				k=registrarGanador(gamer, temp);
				printf("Se encuentra en el top %d\n", k);
			}
			option=6;
		}

		if(option==2&&p1==1){
			if(n==2){
				do{
					printf("\n< %s > presione + para lanzar dados", gamer[0].nombre);
					while(getch()!='+');
					r1=rand()%6+1;
					printf("\n< %s > presione + para lanzar dados", gamer[1].nombre);
					while(getch()!='+');
					r2=rand()%6+1;
					printf("\n< %s >: %d\n< %s >: %d", gamer[0].nombre, r1,  gamer[1].nombre, r2);
					if(r1==r2){
						printf("\nLos dados salieron iguales");
						r=-1;
					}else{
						if(r1>r2)
							r=0;
						else
							r=1;
						printf("\n%s comienza primero", gamer[r].nombre);
					}
					getch();
				}while(r==-1);
				p1=2;
			}
		}

		if(option==5){
			in=fopen("top.ptd","r");
			if(in==NULL){
				printf("No existe el archivo top 10!!!!!!\n");
				exit(1);
			}else{
				system("cls");
				fscanf(in,"%s",cadena);
				printf("     %s\n", cadena);
				for(k=0;k<10;k++){
					fscanf(in,"%s",cadena);
					fscanf(in,"%d",&temp);
					printf("%10s %2d\n", cadena, temp);
				}
				fclose(in);
			}
			option=6;
		}

	}while(option!=6);
	getch();
}
void colocarFicha(JugadorT gam[], int turno, TableroT *tab, int *fil, int *col){

	if(*fil!=-1&&*col!=-1)
		tab->matriz[*fil][*col]=' ';

	if(gam[turno].avance%10!=0){
		*col=(gam[turno].avance%10)-1;
		*fil=gam[turno].avance/10;
	}else{
		*col=9;
		*fil=(gam[turno].avance/10)-1;
	}

	tab->matriz[*fil][*col]=gam[turno].nombre[0];
	return;
}

void analizarCasilla(JugadorT gam[], int turno, TableroT *tab, int *fil, int *col){
	int aux;
	char temp;
	aux=tab->comodines[*fil][*col];
	temp=tab->matriz[*fil][*col];
	ImprimirMensaje(aux, gam, turno);
	if((aux%2)!=0){
		tab->matriz[*fil][*col]=' ';
		buscarConsecuente( *tab, aux, fil, col);
		tab->matriz[*fil][*col]=temp;
	}
	return;
}

void buscarConsecuente(TableroT tab, int num, int *fil, int *col){
	int i, j;
	for(i=0;i<5;i++){
		for(j=0;j<10;j++){
			if(tab.comodines[i][j]==(num+1)){
				*fil=i;
				*col=j;
				return;
			}
		}
	}
}
void ImprimirMensaje(int num, JugadorT gam[], int turno){
	switch (num){
		case 1:
			printf("\nQue pena callo en una serpiente!!! retroceda a la casilla 13\n");
			gam[turno].avance=13;
			break;
		case 3:
			printf("\nQue pena callo en una serpiente!!! retroceda a la casilla 6\n");
			gam[turno].avance=6;
			break;
		case 5:
			printf("\nQue pena callo en una serpiente!!! retroceda a la casilla 43\n");
			gam[turno].avance=43;
			break;
		case 7:
			printf("\nQue suerte callo en una escalera!!! anvanza a la casilla 12\n");
			gam[turno].avance=12;
			break;
		case 9:
			printf("\nQue suerte callo en una escalera!!! anvanza a la casilla 45\n");
			gam[turno].avance=45;
			break;
		case 11:
			printf("\nQue suerte callo en una escalera!!! anvanza a la casilla 30\n");
			gam[turno].avance=30;
			break;
		default:
			printf("\nAnvanza a la casilla %d\n", gam[turno].avance);
			break;
	}
}
void dibujar_tablero_juego(){
	printf("\n                   ******Serpientes y Escaleras******\n");
	printf("ÚÄÄÄÄÄÄÂÄÄÄÄÄÄÂÄÄÄÄÄÄÂÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄ¿\n");
	printf("³1     ³2     ³3     ³4ÜÜ    ³5      ³6  **³7      ³8   Ü  ³9      ³10     ³\n");
	printf("³      ³      ³   ÜÜÜÜÜ      ³       ³       **      ³     ÜÜÜ       ³       ³\n");
	printf("ÃÄÄÄÄÄÄÅÄÄÄÄÄÄÜÜÜÜÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄ*ÄÄÄÄÄÅÄÄÄÄÄÄÄÅÜÜÜÄÄÄÄÅÄÄÄÄÄÄÄ´\n");
	printf("³11    ³12 ÜÜÜ³13    ³14     ³15ÌÍÍ¹ ³16     ³17*    ³18     ³19 ÜÜ  ³20     ³\n");
	printf("³      ³     **    ³       ³  ÌÍÍ¹ ³       ³  *    ³       ³     ÜÜÜ       ³\n");
	printf("ÃÄÄÄÄÄÄÅÄÄÄÄ*ÄÅÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÌÍÍ¹ÄÅÄÄÄÄÄÄÄÅÄÄÄ*ÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÜÜÜÄÄÄÄ´\n");
	printf("³21    ³22 *  ³23    ³24     ³25ÌÍÍ¹ ³26     ³27  *  ³28     ³29     ³30 ÜÜ  ³\n");
	printf("³      ³  *   ³      ³       ³  ÌÍÍ¹ ³       ³    *  ³       ³       ³       ³\n");
	printf("ÃÄÄÄÄÄÄÅ**ÄÄÄÄÅÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÌÍÍ¹ÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄ*ÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄ´\n");
	printf("³31  ***32    ³33    ³34     ³35ÌÍÍ¹ ³36     ³37    *³38     ³39     ³40     ³\n");
	printf("³      ³      ³      ³       ³  ÌÍÍ¹ ³       ³       *       ³       ³       ³\n");
	printf("ÃÄÄÄÄÄÄÅÄÄÄÄÄÄÅÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÌÍÍ¹ÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅ***ÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄ´\n");
	printf("³41    ³42    ³43    ³44     ³45ÌÍÍ¹ ³46     ³47     ³48 **  ³49     ³50     ³\n");
	printf("³      ³      ³   *³      ****     ³****   ³       ³       ³       ³      ³\n");
	printf("ÀÄÄÄÄÄÄÁÄÄÄÄÄÄÁÄÄÄÄÄÄ*******ÄÁÄÄ******ÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÙ\n");
}

int registrarGanador(JugadorT gam[], int turno){
	JugadorT temp[200];
	int k=0, i, flag=0;
	char cadena[30];
	FILE *top, *temptop;

	temptop=fopen("temptop.ptd","r");

	if(temptop==NULL){
		temptop=fopen("temptop.ptd","w");
		fprintf(temptop,"[TEMPTOP]\n%s %d", gam[turno].nombre, gam[turno].veces);
		top=fopen("top.ptd","w");
		fprintf(top,"[TOP10]\n%s %d", gam[turno].nombre, gam[turno].veces);
	}else{
		fscanf(temptop,"%s",cadena);
		while(!(feof(temptop))){
			fscanf(temptop,"%s",temp[k].nombre);
			fscanf(temptop,"%d",&temp[k].veces);
			k++;
		}
		fclose(temptop);
		for(i=0;i<k;i++){
			if(strcmp(gam[turno].nombre,temp[i].nombre)==0){
				flag=1;
				temp[i].veces++;
				i=k;
			}
		}
		if(flag!=1){
			strcpy(temp[k].nombre,gam[turno].nombre);
			temp[k].veces=1;
		}else
			k--;
		ordenaTop(temp,k+1);
		temptop=fopen("temptop.ptd","w");
		fprintf(temptop,"[TEMPTOP]");
		for(i=0;i<k+1;i++)
			fprintf(temptop,"\n%s %d", temp[i].nombre, temp[i].veces);
		top=fopen("top.ptd","w");
		fprintf(top,"[TOP10]");
		if(k>9)
			k=9;
		for(i=k;i>=0;i--)
			fprintf(top,"\n%s %d", temp[i].nombre, temp[i].veces);
	}
	fclose(temptop);
	fclose(top);
	return (k+1);		
}

void ordenaTop(JugadorT temp[], int tam){
	int i, j, aux;
	char cadena[30];
	for(i=0;i<tam;i++){
		for(j=i+1;j<tam;j++){
			if(temp[i].veces<temp[j].veces){
				strcpy(cadena,temp[i].nombre);
				aux=temp[i].veces;
				temp[i].veces=temp[j].veces;
				strcpy(temp[i].nombre,temp[j].nombre);
				temp[j].veces=aux;
				strcpy(temp[j].nombre,cadena);
			}
		}
	}
}

void guardarPartida(JugadorT gam[], int turno, TableroT tab, FILE *in){	
	in=fopen("juegoSyE.ptd","w");
	fprintf(in,"Turno: %d",turno+1);
	fprintf(in,"\n#datos del jugador %d", turno+1);
	fprintf(in,"\n%s,%d", gam[turno].nombre, gam[turno].avance);
	fprintf(in,"\n#datos del jugador %d", (turno+1)%2+1);
	fprintf(in,"\n%s,%d", gam[(turno+1)%2].nombre, gam[(turno+1)%2].avance);
	fclose(in);
}

int cargaPartida(JugadorT gam[], int *turno, int *njug){
	int k, cont=0, aux;
	char cadena[30];
	FILE *launch;
	launch=fopen("juegoSyE.ptd","r");

	if(launch==NULL){
		printf("No tiene partidas guardadas...");
		return 0;
	}else{
		fscanf(launch,"%s",cadena);
		if((strcmp(cadena,"-1"))==0){
			printf("No tiene partidas guardadas...");
			return 0;
		}else{
			fscanf(launch,"%d",&k);
			*turno=k-1;
			aux=*turno;
			while(!feof(launch)){
				for(k=0; k<4; k++)
					fscanf(launch,"%s",cadena);

				fscanf(launch,"%[^,],%d",gam[aux].nombre,&gam[aux].avance);
				aux=(*turno+1)%2;
				cont++;
			}
			*njug=cont;
			return 1;
		}
	}
}

void menuPrincipal(){
	system("cls");
	system("color  9b");
	printf(" ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ\n");
	printf("Û   Ü                                                                    Ü\n");
	printf("Û Û Û               . SERPIENTES Y ESCALERAS V2.0                        Û\n");
	printf("Û Û Û ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ \n");
	printf("Û ² Û\n");
	printf("Û ² Û              ÜÜÜ ÜÜ  ÜÜÜ ÜÜÜ ÜÜÜ ÜÜ  ÜÜÜ ÜÜ\n");
	printf("Û ² Û              Û Û ÛÜÛ Û    Û  Û Û Û Û ÛÜ  ÛÜÜ\n");
	printf("Û ² Û              ÛÜÛ Û   ÛÜÜ ÜÛÜ ÛÜÛ Û Û ÛÜÜ  ÜÛ\n");
	printf("Û ± Û\n");
	printf("Û ± Û                 1: Definir numero de jugadores\n");
	printf("Û ± Û                 2: Sortear turnos\n");
	printf("Û ° Û                 3: Iniciar juego\n");
	printf("Û ° Û                 4: reaunudar partida\n");
	printf("Û ° Û                 5: Top 10\n");
	printf("Û ° Û                 6: Salir\n");
	printf("ÜÜÜÜÛ\n\n");
}