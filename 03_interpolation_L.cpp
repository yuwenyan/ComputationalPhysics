//---------------------------------------------
//Interpolation
//wyu
//vc++ 6.0
//---------------------------------------------
#include <stdio.h>
#include <math.h>

void main()
{
	double pi=3.141593;
	double u=50.0;
	double s=15.0;
	double c=0.0,t=0.0,x[9],f[9][9];
	int a,b,i,j,n;
	FILE *fp;
	fp=fopen("L_interpolation.xls","w+");
	fprintf(fp,"x\t f(x)\n");
	for(t=5.0;t<=95.0;t=t+1.0)				
	{
		c=(1.0/(s*sqrt(2*pi)))*exp( (-1.0/2)*((t-u)/s)*((t-u)/s) );
		fprintf(fp,"%lf\t%lf\n",t,c);
	}
	for(n=2;n<=6;n=n+2)
	{
		x[0]=5.0;
		x[n]=95.0;
		i=0;j=0;a=0;b=0;t=0;
		for(i=1;i<n;i++)
		{
			x[i]=0.0;
			x[i]=x[0]+(double)i*(x[n]-x[0])/n;
		}
		for(b=0;b<9;b++)
		{
			for(a=0;a<9;a++)
			{
				f[b][a]=0.0;
			}
		}
		for(j=0;j<=n;j++)
		{
			f[0][j]=(1.0/(s*sqrt(2*pi)))*exp( (-1.0/2)*((x[j]-u)/s)*((x[j]-u)/s) );
		}
		fprintf(fp,"n=%d\n",n);
		for(t=5.0;t<=95.0;t=t+1.0)
		{
			for(b=0;b<n;b++)
			{
				for(a=b;a<n;a++)
				{
					f[b+1][a+1]=(t-x[b])/(x[a+1]-x[b])*f[b][a+1]+(t-x[a+1])/(x[b]-x[a+1])*f[b][b];					
				}
				c=f[a][b+1];
			}
			fprintf(fp,"%lf\t%lf\n",t,c);
		}
	}
	fclose(fp);
}