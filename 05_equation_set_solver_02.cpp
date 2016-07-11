//---------------------------------------------
// iteration
// wyu
// vc++ 6.0
//---------------------------------------------
#include <stdio.h>
#include <math.h>

void main()
{
	int i,j,k;
	double a[4][4]={10.0,-1.0,-2.0,2.0,1.0,-10.0,2.0,-1.0,1.0,1.0,-5.0,2.0,1.0,-2.0,2.0,-1.0},
		b[4]={4.0,-14.0,-10.0,2.0},
		x[4]={0.0,0.0,0.0,0.0},
		x1[4]={0.0,0.0,0.0,0.0},
		t0=0.0,t1=0.0,s=0.0000001;
	for(k=0;;k++)
	{
		for(i=0;i<4;i++)
		{
			x1[i]=x[i];
		}
		for(i=0;i<4;i++)
		{
			t0=0.0;
			t1=0.0;
			for(j=0;j<i;j++)
			{
				t1=t1+a[i][j]*x[j];
			}
			for(j=i+1;j<4;j++)
			{
				t0=t0+a[i][j]*x[j];
			}
			x[i]=(b[i]-t0-t1)/a[i][i];
		}
		j=0;
		for(i=0;i<4;i++)
		{
			if((x1[i]-x[i])>=-s&&(x1[i]-x[i])<=s)
				j++;
		}
		if(j==4)
			break;
	}
	printf("k = %d\n",k+1);
	for(k=0;k<4;k++)
	{
		printf("x%d = %lf\n",k+1,x[k]);
	}
}