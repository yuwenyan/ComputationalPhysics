//---------------------------------------------
// RLC
//wyu
//vc++ 6.0
//---------------------------------------------
#include <stdio.h>
#include <math.h>

int main()
{
	double V=5.0,R=2.0,C=1.0,L=4.0,Q0=0.0,I0=0.0;
	double dt=0.02,t,l1,l2,l3,l4,k1,k2,k3,k4,Q,I;
	t=0.0;
	Q=Q0;
	I=I0;
	FILE *fp;
	fp=fopen("RLC·.xls","w+");
	fprintf(fp,"%lf\t%lf\n",t,Q);
	for(t=dt;t<50;t=t+dt)
	{
		k1=I;
		l1=(1.0/L)*(V-Q/C-I*R);
		k2=I+0.5*dt*l1;
		l2=(1.0/L)*(V-(Q+0.5*k1*dt)/C-R*(I+0.5*l1*dt));
		k3=I+0.5*dt*l2;
		l3=(1.0/L)*(V-(Q+0.5*k2*dt)/C-R*(I+0.5*l2*dt));
		k4=I+dt*l3;
		l4=(1.0/L)*(V-(Q+k3*dt)/C-R*(I+l3*dt));
		I=I+(1.0/6)*(l1+2*l2+2*l3+l4)*dt;
		Q=Q+(1.0/6)*(k1+2*k2+2*k3+k4)*dt;
		fprintf(fp,"%lf\t%lf\n",t,Q);
	}
	fclose(fp);
	return (0);
}
