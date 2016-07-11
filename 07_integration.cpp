//---------------------------------------------
// integral 2005-04-28
// wyu
// vc++ 6.0
//---------------------------------------------
#include <stdio.h>
#include <math.h>

double f(double m);// 

int main()
{
	int i,j,k;
	double e,A,S,S1,RP,RC,H,D;
	S1=0.0;
	e=0.001;
	j=1;
	A=50.0;
	RP=f(-A)+f(A);
	RC=0;
	H=2*A;
	for(i=0;;i++)
	{
		for(k=1;k<=j;k++)
		{
			RC=RC+f(-A-H/2+k*H);
		}
		S=H/6*(RP+4*RC);
		j=j*2;
		D=(S-S1);
		if(D>-e&&D<e)
			break;
		S1=S;
		H=H/2;
		RP=RP+2*RC;
		RC=0.0;
	}
	FILE *fp;
	fp=fopen("result.txt","w+");
	fprintf(fp,"S=%lf\tn-1=%d",S,j);
	fclose (fp);
	return (0);
}
//
double f(double m)
{
	m=m+50.0;
	double n,pi=3.141593,u=50.0,s=15.0;
	n=(1.0/(s*sqrt(2*pi)))*exp( (-1.0/2)*((m-u)/s)*((m-u)/s) );
	return (n);
}
