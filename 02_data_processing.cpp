//---------------------------------------------
//wyu 2005-03-22
//vc++ 6.0
//---------------------------------------------
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void xh(double *p); // generate a random number
double w1(); // generate an observation
int w2(); // compute the frequency distribution
int w3(); // compute the average
int w4(); // SD 
int w5(); // remove the abnormal values (> 3*sigma)
int f(); // build output file

int i,j,k,l=0,N,n,n1;
double r=0,x=0,average=0,asd=0; //asd => SD
double *p = &r;
double z[1000],distribution[10];
char name[8][32]={"DistributionN=3.xls","AverageN=3.xls","DistributionNewN=3.xls","AverageNewN=3.xls","DistributionN=10.xls","AverageN=10.xls","DistributioNewN=10.xls","AverageNewN=10.xls"};

void main()
{
	srand((unsigned)time(NULL));
	N=1;
	FILE *fp;
	fp=fopen("SD.xls","w+");
	for(N=1;N<=50;N++)
	{
		n=1000;
		n1=1000;
		for(j=0;j<n;j++)
		{
			z[j]=0;
			z[j]=w1();
		}
		w3();
		w4();
		fprintf(fp,"%d\t%.4lf\n",N,asd);
		if(N==3||N==10)
		{
			int p=0;
			for(p=0;p<2;p++)
			{
				w2();	
				w3();
				w4();
				f();
				w5();
			}
		}
	}
	fclose(fp);
}
// generate a random number 4 digits
void xh(double *ptr)
{
	*ptr = 0.1*(rand()%10) +0.01*(rand()%10)+ 0.001*(rand()%10)+0.0001*(rand()%10);
}
//generate an observation
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
// compute the distribution
int w2()
{
	int a=0;
	for(k=0;k<10;k++)
	{
		distribution[k]=0;
		a=0;
		for(j=0;j<n;j++)
		{
			if( (z[j]>=(double)k*0.1) && (z[j]<(double)(k+1)*0.1) )
				a++;
		}
		distribution[k]=(double)a/n1;
	}
	return(0);
}
// compute average
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
// compute SD
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
// remove abnormal
int w5()
{
	int a=0;
	for(j=0;j<n;j++)
	{
		if( ( (z[j]-average)<=3*sqrt(n)*asd)&&((z[j]-average)>=-3*sqrt(n)*asd) )
			a++;
		else z[j]=0;
	}
	n1=a;
	return(3);
}
// build output file
int f()
{
	FILE *fp1;
	fp1=fopen(name[l],"w+");
	for(k=0;k<10;k++)
	{
		fprintf(fp1,"%lf\t%lf\n",(double)k*0.1+0.05,distribution[k]);
	}
	fclose(fp1);
	l++;
	FILE *fp2;
	fp2 = fopen(name[l],"w+");
	fprintf(fp2,"Average x：%.4lf\nSD：%.4lf",average,asd);
	fclose(fp2);
	l++;
	return(4);
}