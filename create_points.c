/*Genero n puntos con coordenadas aleatorias(x,y)*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(NULL));
	int P = 0,U = 20;		/*Rango para generar coordenadas*/
	int n = 10;			/*Numero de puntos*/
	int x,y;				/*Coordenadas*/
	int i;					/*Indice*/
	printf("%d\n",n);
	for(i = 0; i < n; i++)
	{
		x = P + (int) (((U - P + 1.0) * rand()) / (RAND_MAX + 1.0)); 
		y = P + (int) (((U - P + 1.0) * rand()) / (RAND_MAX + 1.0));
		printf("%d %d\n",x,y);
	}
	return 0;
}

/*Código basado en "Generación de números aleatorios en C"
	de la Universidad Autónoma de Madrid, 2004-2005
*/