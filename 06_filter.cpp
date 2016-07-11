//---------------------------------------------
// filter
// wyu
// vc++ 6.0
//---------------------------------------------
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void xh(double *p);//random number
double w1();//observation
int w3();//average
int w4();//sd

int N,N1=50,n=1000;
double r=0,z[1000],average=0,asd=0;//asd
double *p = &r;

void main()
{	
	int i,j,m=2;
	double y[50],y1[5];
	srand((unsigned)time(NULL));
	FILE *fp;
	fp=fopen("filter.xls","w+");
	for(N=1;N<=N1;N++)
	{
		for(i=0;i<n;i++)
		{
			z[i]=0;
			z[i]=w1();
		}
		w3();
		w4();
		y[N-1]=asd;
		fprintf(fp,"%d\t%lf\n",N,y[N-1]);
	}
	//
	for(i=m;i<N1-m;i++)
	{
		y1[0]=(1.0/5.0)*(3*y[i-2]+2*y[i-1]+y[i]-y[i+2]);
		y1[1]=(1.0/10.0)*(4*y[i-2]+3*y[i-1]+2*y[i]+y[i+1]);
		y1[2]=(1.0/5.0)*(y[i-2]+y[i-1]+y[i]+y[i+1]+y[i+2]);
		y1[3]=(1.0/10.0)*(y[i-1]+2*y[i]+3*y[i+1]+4*y[i+2]);
		y1[4]=(1.0/5.0)*(-y[i-2]+y[i]+2*y[i+1]+3*y[i+2]);
		for(j=0;j<(2*m+1);j++)
		{
			y[i-m+j]=y1[j];
		}
	}
	fprintf(fp,"\n");
	for(N=1;N<=N1;N++)
	{
		fprintf(fp,"%d\t%f\n",N,y[N-1]+0.0003);// 0.0003 for better presentation
	}
	//
	for(i=m;i<N1-m;i++)
	{
		y1[0]=(1.0/70.0)*(69*y[i-2]+4*y[i-1]-6*y[i]+4*y[i+1]-y[i+2]);
		y1[1]=(1.0/35.0)*(2*y[i-2]+27*y[i-1]+12*y[i]-8*y[i+1]+2*y[i+2]);
		y1[2]=(1.0/35.0)*(-3*y[i-2]+12*y[i-1]+17*y[i]+12*y[i+1]-3*y[i+2]);
		y1[3]=(1.0/35.0)*(2*y[i-2]-8*y[i-1]+12*y[i]+27*y[i+1]+2*y[i+2]);
		y1[4]=(1.0/70.0)*(-y[i-2]+4*y[i-1]-6*y[i]+4*y[i+1]+69*y[i+2]);
		for(j=0;j<(2*m+1);j++)
		{
			y[i-m+j]=y1[j];
		}
	}
	fprintf(fp,"\n");
	for(N=1;N<=N1;N++)
	{
		fprintf(fp,"%d\t%f\n",N,y[N-1]+0.0006);//0.0006 for plotting
	}
	fclose(fp);
}
//
void xh(double *ptr)
{
	*ptr = 0.1*(rand()%10) +0.01*(rand()%10)+ 0.001*(rand()%10)+0.0001*(rand()%10);
}
//one observation
double w1()
{
	int a;
	double b=0;
	for(a=0;a<N;a++)
	{
		xh(&r);
		b += r;
	}
	b = b/N;
	return (b);
}
//average
int w3()
{
	int b;
	double a=0;
	for(b=0;b<n;b++)
	{
		a += z[b];
	}
	a /= n;
	average=a;
	return(1);
}
//sd
int w4()
{
	int	b;
	double a=0;
	for(b=0;b<n;b++)
	{
		a +=z[b]*z[b];
	}
	a /= n;
	a=sqrt((a-average*average)/(n-1));
	asd=a;
	return(2);
}