/*Archivo: num_romanos.c
Autor:José Bedón
Descripcion:
	MSOTRAR LSO NUMERO ROMANOS DEL 1-100
	EJEMPLO: 98-->>> XCVIII

**************************************************************/

# include<stdio.h>
void imprimir(int n);

void main(){
	int n=39,i=0,c=0;
	
	int arreglo[9]={100,90,50,40,10,9,5,4,1};



	for(c=1;c<100;c++){
		i=0;
		n=c;
		printf("%d : ",n);
		do{
			if(n>=arreglo[i]){
				n=n-arreglo[i];
				imprimir(arreglo[i]);
			}
			else
				i++;
		}while(n!=0);
		printf("\n");
	}
	getch();
}
void imprimir(int n){
	switch(n){
		case 100:
			printf("C");
			break;
		case 90:
			printf("XC");
			break;
		case 50:
			printf("L");
			break;
		case 40:
			printf("XL");
			break;
		case 10:
			printf("X");
			break;
		case 9:
			printf("IX");
			break;
		case 5:
			printf("V");
			break;
		case 4:
			printf("IV");
			break;
		case 1:
			printf("I");
			break;

	}
}