/*
*	Archivo: triangulo.c
*	Autor: Freddy Orosco
*	Descripcion:	Escriba el procedimiento triangulo, el cual dado un número entero n 
*								imprime un triángulo rectángulo de n líneas, de la siguiente forma:
*
*								Si n = 4				
*								triangulo (4);	
*								1					
*								2 3 2				
*								3 4 5 4 3		
*								4 5 6 7 6 5 4			
*/

#include <stdio.h>

void triangulo(int numero); 
void triangulo(int numero)
{
	int i,j;
	printf("1\n");
	for(i=2;i<=numero;i++)
	{
		for(j=i;j<=2*i-1;j++)
		{
			printf("%d ",j);
		}
		for(j=2*i-2;j>=i;j--)
		{
			printf("%d ",j);
		}
		printf("\n");
	}
}

void main()
{
	int num;
	printf("Ingrese un numero:");
	scanf("%d",&num);
	triangulo(num);
	getch();
}
