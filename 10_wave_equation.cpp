//---------------------------------------------
//wave equation
//wyu
//vc++ 6.0
//---------------------------------------------
#include <stdio.h>
#include <math.h>

#define pi 3.1415926

int main()
{
	int	i,k,M,N;
	double h,v,t,T,l,a;
	v=1.0;
	h=0.1;
	T=0.5;
	a=0.5;
	l=1.0;
	t=a*h/v;
	N=(int)floor(l/h);
	M=(int)floor(T/t);
	//	printf("t=%lf M=%d N=%d\n",t,M,N);
	double y[20][20];
	for(k=0;k<=M;k++)
	{
		y[0][k]=0.0;
		y[N][k]=0.0;
	}
	for(i=0;i<=N;i++)
	{
		y[i][0]=sin(pi*i*h);
	}
	for(i=0;i<=N;i++)
	{
		y[i][1]=(1-a*a)*sin(pi*i*h)+a*a/2*(sin(pi*h*(i+1))+sin(pi*h*(i-1)))+t*(i*h)*(1-i*h);
	}
	for(k=1;k<M;k++)
	{
		for(i=1;i<N;i++)
		{
			y[i][k+1]=2*(1-a*a)*y[i][k]+a*a*(y[i+1][k]+y[i-1][k])-y[i][k-1];
		}
	}
	FILE *fp;
	fp=fopen("wave.xls","w+");
	for(k=0;k<=M;k++)
	{
		for(i=0;i<=N;i++)
		{
			fprintf(fp,"%d\t%d\t%lf\n",i,k,y[i][k]);
		}
	}
	fclose(fp);
	return (0);
}
