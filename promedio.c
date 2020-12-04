/*
*	Archivo: promedio.c
*	Descripcion:	Hacer  un Programa  que pida al  usuario  ingresar  dos notas de un estudiante,
*							  luego  calcular  la  suma, si la suma  es  mayor a  120  presentar en  pantalla 
*               "Aprobo la Materia",caso contrario ingresar  una tercera  nota, luego sumar las 
*               dos notas mas altas ingresadas y si la suma es 120 presentar "Aprobo la materia" 
*               caso contrario "Reprobo la materia".
*/

#include <stdio.h>

void main()
{
	int nota1,nota2,nota3,suma=0,menor,mayor;

	printf("Ingrese la primer nota: ");
	scanf("%d",&nota1);
	printf("Ingrese a segunda nota: ");
	scanf("%d",&nota2);
	suma=nota1+nota2;
	if(nota1>=nota2)//Condicion para hallar la mayor de las dos notas
	{
		mayor=nota1;
		menor=nota2;
	}
	else
	{
		mayor=nota2;
		menor=nota1;
	}
	if(suma>=120)
		printf("Aprobo la materia\n");
	else
	{
		printf("No ha completado el puntaje minimo\n");
		if(suma<120)
		{
			printf("Ingrese la tercer nota: ");
			scanf("%d",&nota3);
			if(nota3>=mayor)//Comprobacion de cual es mayor si la nota nueva ingresada o la anterior encontrada
				suma=mayor+nota3;
			else
			{
				if(nota3>=menor)
					suma=nota3+mayor;
				else
					suma=mayor+menor;
			}
			printf("La suma total es: %d\n",suma);
		}
		if(suma>=120)//Comprobamos si la suma es mayor o igual a 120
			printf("Aprobo la Materia");
		else
			printf("Reprobo la Materia");
	}
	getch();
}