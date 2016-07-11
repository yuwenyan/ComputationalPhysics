//---------------------------------------------
//interpolation 2005-03-26
//wyu
//vc++ 6.0
//---------------------------------------------
#include <stdio.h>
#include <math.h>

void main()
{
	int a,b,i,j,n;
	double m=0,pi=3.141593;
	double u=50.0;
	double s=15.0;
	double c,t,x[9],f[9][9],y[3];
	FILE *fp;
	fp=fopen("N_interpolation.xls","w+");
	fprintf(fp,"x\t f(x)\n");
	for(m=5;m<=95;m=m+1)				
	{
		c=0.0;
		c=(1.0/(s*sqrt(2*pi)))*exp( (-1.0/2)*((m-u)/s)*((m-u)/s) );
		fprintf(fp,"%lf\t%lf\n",m,c);
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
		for(j=0;j<=n;j++)
		{
			f[0][j]=0.0;
			f[0][j]=(1.0/(s*sqrt(2*pi)))*exp( (-1.0/2)*((x[j]-u)/s)*((x[j]-u)/s) );
		}
		for(b=1;b<9;b++)
		{
			for(a=0;a<9;a++)
			{
				f[b][a]=0.0;
			}
		}
		for(b=0;b<n;b++)
		{
			for(a=b;a<n;a++)
			{
				f[b+1][a+1]=(f[b][a+1]-f[b][b])/(x[a+1]-x[b]);			
			}
		}		
		if(n==2)
		{
			fprintf(fp,"\n n=2\n");
			for(t=5.0;t<=95.0;t=t+1.0)				
			{
				y[0]=f[0][0]+(t-x[0])*f[1][1]+(t-x[0])*(t-x[1])*f[2][2];
				fprintf(fp,"%.6lf\t%.6lf\n",t,y[0]);
			}
		}
		if(n==4)
		{
			fprintf(fp,"\n n=4\n");
			for(t=5.0;t<=95.0;t=t+1.0)				
			{
				y[1]=f[0][0]+(t-x[0])*f[1][1]+(t-x[0])*(t-x[1])*f[2][2]+(t-x[0])*(t-x[1])*(t-x[2])*f[3][3]+(t-x[0])*(t-x[1])*(t-x[2])*(t-x[3])*f[4][4];
				fprintf(fp,"%.6lf\t%.6lf\n",t,y[1]);
			}
		}
		if(n==6)
		{	
			fprintf(fp,"\n n=6\n");
			for(t=5.0;t<=95.0;t=t+1.0)				
			{
				y[2]=f[0][0]+(t-x[0])*f[1][1]+(t-x[0])*(t-x[1])*f[2][2]+(t-x[0])*(t-x[1])*(t-x[2])*f[3][3]+(t-x[0])*(t-x[1])*(t-x[2])*(t-x[3])*f[4][4]+(t-x[0])*(t-x[1])*(t-x[2])*(t-x[3])*(t-x[4])*f[5][5]+(t-x[0])*(t-x[1])*(t-x[2])*(t-x[3])*(t-x[4])*(t-x[5])*f[6][6];
				fprintf(fp,"%lf\t%lf\n",t,y[2]);
			}
		}
	}
	fclose(fp);
}
