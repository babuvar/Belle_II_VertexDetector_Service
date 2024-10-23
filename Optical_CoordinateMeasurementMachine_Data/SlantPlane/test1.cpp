#include<iostream>
#include<cmath>
using namespace std;
int test1()
{
float pi=acos(-1.0);
//float t1,t2,T1,T2,phi=(-28.0749*pi)/180;

//float t1,t2,T1,T2,phi=(-0.938675 *pi)/180;         // top horizontal	-11.9825 	0.210289
//float t1,t2,T1,T2,phi=(-0.960606*pi)/180;       // bottom horizontal	-11.9824	0.214944	 
float t1,t2,T1,T2,phi=(-359.012*pi)/180;       // vertical		-11.9823	0.222513
//float t1,t2,T1,T2,phi=(*pi)/180;       // combined		

T1=(-11.9842*pi)/180;
T2=(0.0110495*pi)/180;




t1=(cos(phi)*tan(T1))+(sin(phi)*tan(T2));
t1=atan(t1);
t2=(-sin(phi)*tan(T1))+(cos(phi)*tan(T2));
t2=atan(t2);


cout<<endl<<"CORRECTED VALUES"<<endl;
cout<<endl<<"Fit parameters:"<<endl;
cout<<"Tilt angle(degrees) ="<<t1*180/pi<<endl;
cout<<"Normal angle(degrees) ="<<t2*180/pi<<endl;
return 0;
}
