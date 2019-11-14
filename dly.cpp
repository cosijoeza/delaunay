#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>  //Dibujar figuras
#include <stdio.h>
#define NMAX 100
using namespace std;
using namespace cv;
int main(int argc, char** argv)
{
    Mat image(800,800,CV_8UC3,Scalar(0,0,0)); //Color fondo de nueva imagen
	int x[NMAX],y[NMAX],z[NMAX];
	int n;							/*Numero de puntos*/
	int i,j,k,m;					/**/
	int xn,yn,zn;
	int flag;

	/*Lectura de puntos*/
	scanf("%d\n",&n);
    int thicknessLine = 1;  //Grosor de la linea
    int radiusCircle = 3;
    int thicknessCircle = 3;
    int dx = 20,dy = 20, separacion = 13;
    for(i = 0; i < n; i++)
	{ 
		scanf("%d %d",&x[i],&y[i]);
		z[i] = (x[i] * x[i]) + (y[i] * y[i]); //Suma de los cuadrados
		printf("(%d) x: %d y: %d\n",i,x[i],y[i]);
        circle(image,Point(x[i]*separacion+dx,y[i]*separacion+dy),radiusCircle,Scalar(150,150,0),CV_FILLED);
    }
	for(i = 0; i < (n-2); i++)
	{
		for(j = (i+1); j < n; j++)
		{
			for(k = (i+1); k < n; k++)
			{
				//Calcular triangulo i,j,k
				if(j != k)
				{
					xn = ( (y[j]-y[i])*(z[k]-z[i]) )-( (y[k]-y[i])*(z[j]-z[i]) );
					yn = ( (x[k]-x[i])*(z[j]-z[i]) )-( (x[j]-x[i])*(z[k]-z[i]) );
					zn = ( (x[j]-x[i])*(y[k]-y[i]) )-( (x[k]-x[i])*(y[j]-y[i]) );
				}
				if( flag = (zn < 0))
				{
					//Para cada otro punto m
					for(m = 0; m < n; m++)
					{
						flag = flag && ((x[m]-x[i])*xn + (y[m]-y[i])*yn + (z[m]-z[i])*zn <= 0); 
					}
				}
				if(flag)
				{
                    printf("%d\t%d\t%d\n",i,j,k);//TRIANGULO FINAL
                    line(image,Point(x[i]*separacion+dx,y[i]*separacion+dy),Point(x[j]*separacion+dx,y[j]*separacion+dy),Scalar(255,255,255),thicknessLine);  //Graficar linea
                    line(image,Point(x[j]*separacion+dx,y[j]*separacion+dy),Point(x[k]*separacion+dx,y[k]*separacion+dy),Scalar(255,255,255),thicknessLine);  //Graficar linea
                    line(image,Point(x[i]*separacion+dx,y[i]*separacion+dy),Point(x[k]*separacion+dx,y[k]*separacion+dy),Scalar(255,255,255),thicknessLine);  //Graficar linea
                }
			}
		}
	}
	namedWindow("Delaunay",WINDOW_NORMAL);
    imshow("Delaunay", image);
    waitKey(0);
    return 0;
}
