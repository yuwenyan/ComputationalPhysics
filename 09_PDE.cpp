//---------------------------------------------
//partial differential equation
//wyu
//vc++ 6.0
//---------------------------------------------
#include <stdio.h>
#include <math.h>

int main()
{
	int	i,k,M,N;
	double h,t,T,l,a;
	h=0.1;
	l=1.0;
	T=0.06;
	a=1.0/6;
	t=a*h*h;
	M=T/t+1;//此处计算机的结果总是比精确值少1，是舍位造成的，故补1
	N=floor(l/h);
//	printf("t=%lf M=%d N=%d\n",t,M,N);
	double u[50][50];
	for(i=0;i<=N;i++)
	{
		u[i][0]=4*i*h*(1-i*h);
	}
	for(k=0;k<=M;k++)
	{
		u[0][k]=0.0;
		u[N][k]=0.0;
	}
	for(k=0;k<M;k++)
	{
		for(i=1;i<N;i++)
		{
			u[i][k+1]=a*u[i+1][k]+(1-2*a)*u[i][k]+a*u[i-1][k];
		}
	}
	FILE *fp;
	fp=fopen("pde.xls","w+");
	for(k=0;k<=M;k++)
	{
		for(i=0;i<=N;i++)
		{
			fprintf(fp,"%d\t%d\t%lf\n",i,k,u[i][k]);
		}
	}
	fclose(fp);
	return (0);
}
