//---------------------------------------------
// Monte Carlo balancing process
//wyu
//vc++ 6.0
//---------------------------------------------
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

double frand();

int main()
{
	int t,i,j,m,n[25000],N=10000,s[10000];// t is tmc
	double x,y;
	m=10;// average 10 times
	for(t=0;t<2.5*N;t++)
	{
		n[t]=0;
	}
	srand((unsigned)time(NULL));
	FILE *fp;
	for(j=1;j<=m;j++)
	{
		for(i=0;i<10000;i++)
		{                                                                     
			s[i]=1;
		}
		for(t=0;t<2.5*N;t++)
		{
			i=int(N*frand());
			if(i==N)
				i=i-1;
			s[i]=-s[i];
			for(i=0;i<N;i++)
			{
				if(s[i]==-1)
					n[t]++;
			}
		}
	}
	fp=fopen("balancing.xls","w+");
	for(t=0;t<2.5*N;t++)
	{
		x=(double)n[t]/m;
		y=((double)N/2)*(1-exp(-2*(double)(t+1)/N));
		fprintf(fp,"%d\t%lf\t%lf\n",t,x,y);
	}
	fclose(fp);
	
	return(0);
}

double frand()
{
	double f;
	f=(double)rand()/(RAND_MAX+1.0);
	return (f);
}
