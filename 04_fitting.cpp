//---------------------------------------------
//fitting 2005-04-03
//wyu
//vc++ 6.0
//---------------------------------------------
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void xh(double *p);// generate random number
double w1();// make one observation
int w3();//average
int w4();//sd

int i,j,N,N1=50,n1,n;
double x=0,r=0,y[50],z[1000],average=0,asd=0;//asd -> averaged SD
double *p = &r;

void main()
{
	double xa=0,ya=0,x2a=0,xya=0,a0=0,a1=0,a=0,b=0,s=0,sa0=0,sa1=0,y1[50],R=0,R1=0,R2=0,R3=0;//R线性相关系数

	srand((unsigned)time(NULL));
	FILE *fp;
	fp=fopen("fitting.xls","w+");
	for(N=1;N<=N1;N++)
	{
		n=1000;
		n1=1000;
		for(i=0;i<n;i++)
		{
			z[i]=0;
			z[i]=w1();
		}
		w3();
		w4();
		y[N-1]=asd;
		y1[N-1]=log(y[N-1]);
		fprintf(fp,"%d\t%.4lf\n",N,y[N-1]);
	}

	for(N=1;N<=N1;N++)
	{
		xa=xa+N;
		ya=ya+y1[N-1];
		x2a=x2a+N*N;
		xya=xya+N*y1[N-1];
	}
	fprintf(fp,"N \t Y(N) \n");
	xa=xa/N1;
	ya=ya/N1;
	x2a=x2a/N1;
	xya=xya/N1;
	a1=(xya-xa*ya)/(x2a-xa*xa);
	a0=ya-a1*xa;
	a=exp(a0);
	b=a1;
	for(N=1;N<=N1;N++)
	{
		y[N-1]=a*exp(b*N);
		fprintf(fp,"%d\t%lf\n",N,y[N-1]);
		s=s+(y1[N-1]-a0-a1*N)*(y1[N-1]-a0-a1*N);
		R1=R1+(N-xa)*(y1[N-1]-ya);
		R2=R2+(N-xa)*(N-xa);
		R3=R3+(y1[N-1]-ya)*(y1[N-1]-ya);
	}
	s=sqrt(s/(N1-2));//sd
	sa0=s*sqrt(x2a/(N1*x2a-xa*xa));
	sa1=s*sqrt(1/(N1*x2a-xa*xa));
	R=R1/sqrt(R2*R3);

	fprintf(fp,"linearity \t %lf \n",R);
	fprintf(fp,"linearity_sd \t %.4lf \n",s);
	fprintf(fp,"A0= %.3lf \tA1= %.4lf \n",a0,a1);
	fprintf(fp,"A0_sd \t %.3lf \n",sa0);
	fprintf(fp,"A1_sd \t %.4lf \n",sa1);
	fprintf(fp,"a=%lf \tb= %lf \n",a,b);

	fclose(fp);
}
//random number
void xh(double *ptr)
{
	*ptr = 0.1*(rand()%10) +0.01*(rand()%10)+ 0.001*(rand()%10)+0.0001*(rand()%10);
}
//generate one observation
double w1()
{
	int a;
	x=0;
	for(a=0;a<N;a++)
	{
		xh(&r);
		x += r;
	}
	x = x/N;
	return (x);
}
// take average
int w3()
{
	double a=0;
	for(j=0;j<n;j++)
	{
		a += z[j];
	}
	a /= n1;
	average=a;
	return(1);
}
//compute sd
int w4()
{
	double a=0;
	for(j=0;j<n;j++)
	{
		a +=z[j]*z[j];
	}
	a /= n1;
	a=sqrt((a-average*average)/(n1-1));
	asd=a;
	return(2);
}