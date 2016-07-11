//---------------------------------------------
// Ising Model 2005-06-21
// wyu
// vc++ 6.0
//---------------------------------------------
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

double frand();

int main()
{
	int i,j,k,p,q,n,t,dh,N,s[50][50];
	double J,B,r,x,m[8000],tao[3];
	srand((unsigned)time(NULL));
	N=6;
	B=0.5;	
	J=0.55/B;// 0.35 or 0.55
	tao[0]=1;tao[1]=exp(-B*4*J);tao[2]=exp(-B*8*J);
	for(i=0;i<8000;i++)
	{
		m[i]=0;
	}
	for(k=0;k<N;k++)
	{
		for(i=0;i<50;i++)
		{
			for(j=0;j<50;j++)
			{
				s[i][j]=1;
			}
		}
		for(t=1;t<=8000;t++)
		{
			i=frand()*50;
			if(i==50) i=49;
			j=frand()*50;
			if(j==50) j=49;
			s[i][j]=-s[i][j];
			dh=0;
			if(i==0)
				p=49;
			else p=i-1;
			if(j==0)
				q=49;
			else q=j-1;
			dh=dh+s[i][j]*s[p][q];
			if(i==0)
				p=49;
			else p=i-1;
			if(j==49)
				q=0;
			else q=j+1;
			dh=dh+s[i][j]*s[p][q];
			if(i==49)
				p=0;
			else p=i+1;
			if(j==0)
				q=49;
			else q=j-1;
			dh=dh+s[i][j]*s[p][q];
			if(i==49)
				p=0;
			else p=i+1;
			if(j==49)
				q=0;
			else q=j+1;
			dh=dh+s[i][j]*s[p][q];
			if(dh<=0)
				n=0;
			else if(dh==2)
				n=1;
			else n=2;
			r=frand();
			if(r>=tao[n])
				s[i][j]=-s[i][j];
			x=0;
			for(p=0;p<50;p++)
			{
				for(q=0;q<50;q++)
				{
					x=x+s[p][q];
				}
			}
			x=x/2500;
			if(x<0)
				x=-x;
			m[t-1]=m[t-1]+x;
		}
	}
	FILE *fp;
	fp=fopen("Ising(2).xls","w+");
	for(t=1;t<=8000;t++)
	{
		fprintf(fp,"%d\t%lf\n",t,m[t-1]/N);
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
