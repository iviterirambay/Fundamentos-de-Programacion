/* Archivo: Loteria Nacional
	 Autor: Freddy Orosco
	 Descripción: Simule el juego de la loteria nacional que consiste en lo siguiente.
	 El numero a participar consta de 4 numeros el cual será generado aleatoriamente entre 1000 y 9999,
	 el usuario deberá elegir el número que desea comprar. El usuario gana unicamente si:
	 Tiene el número ganador gana 25000
	 Tiene los tres ultimos números gana 500
	 Tiene los dos ultimos números gana 50
	 Tiene el ultimo numero ganará un reintegro(1 dolar para que juegue de nuevo).
	 El usuario contará al inicio con tres dolares, tome en cuenta cada numero de loteria 
	 cuesta 1 dolar y unicamente puede comprar un boleto por sorteo. 
	 El juego termina cuando a usted se le termine el dinero o cuando usted
	 desee retirarse del mismo presionando 0.
	 Finalmente presente en pantalla el monto total de dinero que acumuló y en cuantos 
	 sorteos lo hizo.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int aleatorio,num,dinero=3,opcion,cont=0,acumulado=0;
	srand(time(NULL));
	do{
		aleatorio=1000+rand()%9000;
		printf("%d",aleatorio);
		printf("Que numero desea comprar:");scanf("%d",&num);
		if(aleatorio==num)
		{
			printf("Gano el premio mayor. FELICIDADES gana 25000!!!\n");
			acumulado=acumulado+25000;
		}
		else
		{
			if(aleatorio%1000==num%1000)
			{
				printf("Gano el segundo premio de 500 dolares\n");
				acumulado=acumulado+500;
			}
			else
			{
				if(aleatorio%100==num%100)
				{
				printf("Gano el tercero premio de 50 dolares\n");
				acumulado=acumulado+50;
				}
				else
				{
					if(aleatorio%10==num%10)
					{
						printf("Gano el cuarto premio, un reintegro\n");
						dinero++;
					}
					else
					{
							printf("No ha ganado\n");
					}
				}
			}
		}
		if(dinero!=1)
		{
			printf("Tiene disponibles %d dolares para comprar numeros.",dinero-1);
			printf("Desea comprar un nuevo numero para seguir jugando: 0.NO 1.SI: ");scanf("%d",&opcion);
		if(opcion==0)
			dinero=0;
		}
		dinero--;
		cont++;
	}while(dinero>=1);
	printf("Usted ha ganado un acumulado de %d dolares en %d sorteos",acumulado,cont);
getch();
}
