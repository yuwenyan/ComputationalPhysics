//---------------------------------------------
//Oscillation 2005-03-15
//wyu 3020621061
//vc++ 6.0
//---------------------------------------------
#include <stdio.h>
#include <math.h>
void main(){
	int a1=50, a2=40, t=0, n=1500;
	int y1, y2, y;
	float w1=0.05,w2=0.03;
	FILE *fp;
	fp=fopen("Oscillation.xls","w+");
	for (t=0;t<=n;t++)
	{
		y1 = a1*cos(w1*t)+60;
		y2 = a2*cos(w2*t)+160;
		y = y1 + y2;
		fprintf(fp,"%d\t%d\n",t,y);
	}
	fclose(fp);
}