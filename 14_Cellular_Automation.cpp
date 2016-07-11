//---------------------------------------------
// Cellular Automata One dimension
// wyu
//vc++ 6.0
//---------------------------------------------
#include <stdio.h>
#include <math.h>

int main()
{
	int i,t,N,T,s[52],x,r;
	N=50;
	T=50;
	t=0;
	for(i=0;i<N+2;i++)
	{
		s[i]=0;
	}
	s[10]=1;s[23]=1;s[24]=1;s[25]=1;s[40]=1;
	FILE *fp;
	fp=fopen("cell.xls","w+");
	fprintf(fp,"%d\t",t);
	for(i=1;i<=N;i++)
	{
		if(s[i]==1)
			fprintf(fp,"%d\t",i);
	}
	fprintf(fp,"\n");
	for(t=1;t<=T;t++)
	{
		fprintf(fp,"%d\t",t);
		r=s[50];s[51]=s[1];
		for(i=1;i<=N;i++)
		{
			x=s[i]+s[i+1];
			if(x==1&&r==0)
			{
				r=s[i];
				s[i]=1;
			}
			else
			{
				r=s[i];
				s[i]=0;
			}
			if(s[i]==1)
				fprintf(fp,"%d\t",i);

		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	return(0);
}
