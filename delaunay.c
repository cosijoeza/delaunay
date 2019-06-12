#include <stdio.h>
#define NMAX 100
int main()
{
	int x[NMAX],y[NMAX],z[NMAX];
	int n;							/*Numero de puntos*/
	int i,j,k,m;					/**/
	int xn,yn,zn;
	int flag;

	/*Lectura de puntos*/
	scanf("%d\n",&n);
	for(i = 0; i < n; i++)
	{ 
		scanf("%d %d",&x[i],&y[i]);
		z[i] = (x[i] * x[i]) + (y[i] * y[i]);
		printf("%d\n",z[i]);
	}
	for(i = 0; i < (n-2); i++)
	{
		for(j = (i+1); j < n; j++)
		{
			for(k = (i+1); k < n; k++)
			{
				/*Calcular triangulo i,j,k*/
				if(j != k)
				{
					xn = ( (y[j]-y[i])*(z[k]-z[i]) )-( (y[k]-y[i])*(z[j]-z[i]) );
					yn = ( (x[k]-x[i])*(z[j]-z[i]) )-( (x[j]-x[i])*(z[k]-z[i]) );
					zn = ( (x[j]-x[i])*(y[k]-y[i]) )-( (x[k]-x[i])*(y[j]-y[i]) );
				}
				/**/
				if( flag = (zn < 0))
				{
					/*Para cada otro punto m*/
					for(m = 0; m < n; m++)
					{
						flag = flag && ((x[m]-x[i])*xn + (y[m]-y[i])*yn + (z[m]-z[i])*zn <= 0); 
					}
				}
				if(flag)
					{printf("%d\t%d\t%d\n",i,j,k);}

			}
		}
	}

	return 0;
}