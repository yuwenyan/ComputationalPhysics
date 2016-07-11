//---------------------------------------------
//Irons Scattering 2005-03-16
//wyu
//vc++ 6.0
//---------------------------------------------
#include <stdio.h>
#include <math.h>
int main(){
	int i;
	float k=0.75,dt=0.05,x,y,x0,y0,vx,vy,ax,ay,r;
	FILE *fp;
	fp=fopen("Scattering.xls","w+");
	for(i=-2;i<=2;i++)
	{
		y0=2.5*i;y=y0;x=x0=2;vx=1.5;vy=0;
		do
		{
			r=sqrt(pow(x-40,2)+pow(y-0,2));
			ax=k*(x-40)/pow(r,3);
			ay=k*(y-0)/pow(r,3);
			vx=vx+ax*dt;
			vy=vy+ay*dt;
			x=x+vx*dt;
			y=y+vy*dt;
			fprintf(fp,"%f\t%f\n",x,y);
		}while(x<=64&&x>0&&y<=30&&y>=-30);
		fprintf(fp,"\n");
	}
	fclose(fp);
	return 0;
}