#include "TVector2.h"
#include<cstring> 
#include<cmath> 
void Rotate3D(TVector3 & V, TVector3 Rot);

void test(){
TVector3 vec(-0.532,0.45,1);
TVector3 rot(-2,-2,1),rot1(2,2,1);


Rotate3D(vec,rot); 
Rotate3D(vec,rot1); 
//Rotate3D(vec,-rot);

vec.Print();

}


void Rotate3D(TVector3 & V, TVector3 Rot)
{
Double_t a,b,c,theta,x,y,r; TVector3 Rot_Axis;
a=Rot.X();b=Rot.Y();c=Rot.Z();

r=sqrt((a*a)+(b*b));
theta=r/fabs(c);
theta=atan(theta);

x=-b/r;
y=a/r;

Rot_Axis.SetXYZ(x,y,0);
V.Rotate(theta,Rot_Axis);


}
