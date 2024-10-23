#include<iostream>
#include<cmath>
using namespace std;
int test()
{
float pi=acos(-1.0);
//float t1,t2,T1,T2,phi=(-28.0749*pi)/180;

//float t1,t2,T1,T2,phi=(-28.2782 *pi)/180;         // top horizontal	-11.9667	0.200932
//float t1,t2,T1,T2,phi=(-28.243*pi)/180;       // bottom horizontal	-11.9665	0.208392
float t1,t2,T1,T2,phi=(-28.2125*pi)/180;       // vertical		-11.9664	0.214857
//float t1,t2,T1,T2,phi=(-28.0749*pi)/180;       // combined

T1=(-10.4808*pi)/180;
T2=(5.90905*pi)/180;




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
