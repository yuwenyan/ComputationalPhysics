//---------------------------------------------
// elimination approach 
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
		x[4],
		t=0.0;
	for(k=0;k<4;k++)
	{
		for(i=k+1;i<4;i++)
		{
			if(a[i][k]>a[k][k])
			{
//				printf("yes\n");
				for(j=0;j<4;j++)
				{
					t=a[k][j];
					a[k][j]=a[i][j];
					a[i][j]=t;
				}
				t=b[k];
				b[k]=b[i];
				b[i]=t;
			}
		}
		b[k]=b[k]/a[k][k];
		for(j=k+1;j<4;j++)
		{
			a[k][j]=a[k][j]/a[k][k];
		}
		for(i=k+1;i<4;i++)
		{
			for(j=k+1;j<4;j++)
			{
				a[i][j]=a[i][j]-a[i][k]*a[k][j];
			}
		}
		for(i=k+1;i<4;i++)
		{
			b[i]=b[i]-a[i][k]*b[k];
		}
	}	
	x[3]=b[3];
	x[2]=b[2]-a[2][3]*x[3];
	x[1]=b[1]-a[1][2]*x[2]-a[1][3]*x[3];
	x[0]=b[0]-a[0][1]*x[1]-a[0][2]*x[2]-a[0][3]*x[3];
	FILE *fp;
	fp=fopen("solution.txt","w+");
	for(k=0;k<4;k++)
	{
		fprintf(fp,"x%d = %lf\n",k+1,x[k]);
	}
	fclose(fp);
}
