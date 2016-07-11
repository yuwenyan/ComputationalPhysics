//---------------------------------------------
//fft
//wyu
//vc++ 6.0
//---------------------------------------------
#include <stdio.h>
#include <math.h>

#define pi 3.1415926

double f(int);
double w(int);
int pt(int);

int N=64,r=6;

int main()
{
	int l,k,p,m,M,a,b,c;
	double x[64],temp,fr;
	for(k=0;k<N;k++)
	{
		x[k]=f(k);
	}
	for(l=1;l<=r;l++)
	{	
		M=pow(2,l)/2-1;
		for(m=0;m<=M;m++)
		{
			a=2*m*N/pow(2,l);
			b=((2*m+1)*N/pow(2,l))-1;
			for(k=a;k<=b;k++)
			{
				p=pt(k);
				c=k+N/pow(2,l);
				temp=x[k];
				x[k]=temp+w(p)*x[c];
				x[c]=temp-w(p)*x[c];
			}
		}
	}
	FILE *fp;
	fp=fopen("fft.xls","w+");
	for(k=0;k<N;k++)
	{
		fr=k/(2*pi);
		fprintf(fp,"%lf\t%lf\n",fr,x[k]);
	}
	fclose(fp);
	
	return (0);
}

double f(int t)
{
	double f;
	f=cos(2*pi*t/N)+0.5*cos(2*pi*2*t/N)+0.8*cos(2*pi*5*t/N);
	return(f);
}

double w(int t)
{
	double w;
	w=cos(-2*pi*t/N);
	return(w);
}

int pt(int k)
{
	int i,n;
	n=0;
	for(i=1;;i++)
	{
		n=n+k%2;
		if(i==r)
			break;
		n=n*10;
		k=k/2;
	}
	k=0;
	for(i=0;i<r;i++)
	{
		k=k+(n%10)*pow(2,i);
		n=n/10;
	}
	return(k);
}
