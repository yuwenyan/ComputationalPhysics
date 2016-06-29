//--------------------------------------------
//Diffraction 2005-03-16
//wyu
//vc++ 6.0
//---------------------------------------------
#include <stdio.h>
#include <math.h>
void main(){
	int n=4;
	float pi=3.141593,a=0.4,d=0.8,u,v,k,f,i,y;
	k=2*pi/1e7;d=d/1000;a=a/1000;
	FILE *fp;
	fp=fopen("Diffraction.xls","w+");
	for(f=-320;f<320;f++)
	{
		u=pi*a*sin(f/1e5)/k;
		v=pi*d*sin(f/1e5)/k;
		i=sin(u)/u*sin(n*v)/sin(v);
		y=i*i;
		fprintf(fp,"%f\t%f\n",f,y);
	}
	fclose(fp);
}