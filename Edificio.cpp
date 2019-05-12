#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;



int main {

	double tiempo = 6;
	double dt = 0.006; 
	int N = int (tiempo/dt);
	double m = 1000.0;
	double gamma = 0.0;
	int k = 2000;
	double omega = 1.0 * sqrt(k/m);

	double *u_1;
	u_1 = new   double [N];
	double *v_1;
	v_1 = new   double [N];
	double *u_2;
	u_2 = new   double [N];
	double *v_2;
	v_2 = new   double [N];
	double *u_3;
	u_3 = new   double [N];
	double *v_3;
	v_3 = new   double [N];

	double *t;
	t= new double [N];

	u_1[0]=0;
	u_2[0]=0;
	u_3[0]=0;

	v_1[0]=0;
	v_2[0]=0;
	v_3[0]=0;

	int i =1;
	t[0] = 0; 

	double U_1k_1, U_1k_2, U_1k_3, U_1k_4, U_2k_1, U_2k_2, U_2k_3, U_2k_4, U_3k_1, U_3k_2, U_3k_3, U_3k_4 ;
	double V_1k_1, V_1k_2, V_1k_3, V_1k_4, V_2k_1, V_2k_2, V_2k_3, V_2k_4, V_3k_1, V_3k_2, V_3k_3, V_3k_4 ;



	while (i < N)
	{
	
	t[i] =t[i-1] + dt;

	U_1k_1 = dt * v_1[i-1];
	U_2k_1 = dt * v_2[i-1];
	U_3k_1 = dt * v_3[i-1];

	V_1k_1 = dt * (1/m) * (-gamma * v_1[i-1] - 2*k * u_1[i-1] + k*u_2[i-1] + sin(omega*t[i-1])  ;
	V_2k_1 = dt * (1/m) * (-gamma * v_2[i-1] + k * u_1[i-1] -2* k*u_2[i-1] + k*u_3[i-1])  ;
	V_3k_1 = dt * (1/m) * (-gamma * v_3[i-1] + k*u_2[i-1] - k*u_3[i-1]);
	
	U_1k_2 = dt * (v_1[i-1] + V_1k_1/2);
	U_2k_2 = dt * (v_2[i-1] + V_2k_1/2);
	U_3k_2 = dt * (v_3[i-1] + V_3k_1/2);

	V_1k_2 = dt * (1/m) * (-gamma * (v_1[i-1] + V_1k_1/2) - 2*k * (u_1[i-1] + U_1k_1/2)  + k* (u_2[i-1] + U_2k_1/2)   + sin(omega*(t[i-1] +dt/2))  ;
	V_2k_2 = dt * (1/m) * (-gamma * (v_2[i-1] + V_2k_1/2) + k * (u_1[i-1] + U_1k_1/2) -2* k*(u_2[i-1] + U_2k_1/2) + k*(u_3[i-1] + U_3k_1/2))  ;
	V_3k_2 = dt * (1/m) * (-gamma * (v_3[i-1]+ V_3k_1/2) + k * (u_2[i-1] + U_2k_1/2) - k * (u_3[i-1] + U_3k_1/2));

	U_1k_3 = dt * (v_1[i-1] + V_1k_1/2 + V_1k_2/3);
	U_2k_3 = dt * (v_2[i-1] + V_2k_1/2 + V_2k_2/3);
	U_3k_3 = dt * (v_3[i-1] + V_3k_1/2 + V_3k_2/3);


	V_1k_3 = dt * (1/m) * (-gamma * (v_1[i-1] + V_1k_2/2) - 2*k * (u_1[i-1] + U_1k_2/2)  + k* (u_2[i-1] + U_2k_2/2)   + sin(omega*(t[i-1] +dt/2))  ;
	V_2k_3 = dt * (1/m) * (-gamma * (v_2[i-1] + V_2k_2/2) + k * (u_1[i-1] + U_1k_2/2) -2* k*(u_2[i-1] + U_2k_2/2) + k*(u_3[i-1] + U_3k_2/3))  ;
	V_3k_3 = dt * (1/m) * (-gamma * (v_3[i-1]+ V_3k_2/2) + k * (u_2[i-1] + U_2k_2/2) - k * (u_3[i-1] + U_3k_2/3));

	
	U_1k_4 = dt * (v_1[i-1] + V_1k_1/2 + V_1k_2/3);
	U_2k_4 = dt * (v_2[i-1] + V_2k_1/2 + V_2k_2/3);
	U_3k_4 = dt * (v_3[i-1] + V_3k_1/2 + V_3k_2/3);
	
	
	
	u_1[i] = u_1[i-1] + 1/6*(U_1k_1 + 2*U_1k_2 + 2*U_1k_3 + U_1k_4);
	u_2[i] = u_2[i-1] + 1/6*(U_2k_1 + 2*U_2k_2 + 2*U_2k_3 + U_2k_4);
	u_3[i] = u_3[i-1] + 1/6*(U_3k_1 + 2*U_3k_2 + 2*U_3k_3 + U_3k_4);
	v_1[i] = v_1[i-1] + 1/6*(V_1k_1 + 2*V_1k_2 + 2*V_1k_3 + V_1k_4);
	v_2[i] = v_2[i-1] + 1/6*(V_2k_1 + 2*V_2k_2 + 2*V_2k_3 + V_2k_4);
	v_3[i] = v_3[i-1] + 1/6*(V_3k_1 + 2*V_3k_2 + 2*V_3k_3 + V_3k_4);

	i++;
	}

ofstream file ;
file.open("edificioplot.dat");

for ( int j = 0; j<N; j++)
{
file << t[i] <<" "<<u_1[i] << " "<< v_1[i] <<endl;
}
file.close();

ofstream file2 ;
file2.open("edificioplot_2.dat");
for ( int j = 0; j<N; j++)
{
file2 << t[i] <<" "<<u_2[i] << " "<< v_2[i] <<endl;
}
file2.close();


ofstream file3 ;
file3.open("edificioplot_3.dat");
for ( int j = 0; j<N; j++)
{
file3 << t[i] <<" "<<u_3[i] << " "<< v_3[i] <<endl;
}
file3.close();





return 0;
}
