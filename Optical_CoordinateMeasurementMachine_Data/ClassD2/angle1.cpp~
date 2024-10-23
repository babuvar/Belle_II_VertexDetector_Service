//This is to find the relative angle between the coordinate systems of the kokeshi pins and the reference holes
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
float pi=acos(-1.0);
class vec2{
public:
float X,Y;
vec2();
vec2(float a,float b);
~vec2();
void set(float a,float b);
void print();
float distance(vec2 A);
void translate(vec2 A);
void rotate(float theta);
void copY(vec2 A);
void add(vec2 A);
vec2 sub(vec2 A);
void divide(float d);
void XYAngles();
float mag();
float CrossAngle(vec2 A);

};

float vec2::CrossAngle(vec2 A)
{
float d,m1,m2,t;
d=(X*A.X)+(Y*A.Y);
m1=sqrt((X*X)+(Y*Y));
m2=sqrt((A.X*A.X)+(A.Y*A.Y));
t=d/(m1*m2);
t=acos(t);
//t=t*180/pi;
return t;
}


vec2::vec2()
{
X=0;Y=0;
}

float vec2::mag()
{
float r;
r=sqrt((X*X)+(Y*Y));
return r;
}

void vec2::add(vec2 A)
{vec2 B;
X=X+A.X;
Y=Y+A.Y;
}

vec2 vec2::sub(vec2 A)
{vec2 B;
B.X=X-A.X;
B.Y=Y-A.Y;
return B;
}

void vec2::divide(float d)
{
X=X/d;
Y=Y/d;
}

void vec2::XYAngles()
{
float r,theta1,theta2;
r=sqrt((X*X)+(Y*Y));
theta1=acos(X/r);
theta2=acos(Y/r);
cout<<"theta1 = "<<(theta1*180/pi)<<"    theta2 = "<<(theta2*180/pi)<<endl;
}

vec2::vec2(float a,float b)
{
X=a;Y=b;
}

void vec2::set(float a,float b)
{
X=a;Y=b;
}

void vec2::copY(vec2 A)
{
X=A.X;
Y=A.Y;
}

vec2::~vec2(float a,float b){}

void vec2::print()
{
cout<<X<<"\t"<<Y<<endl;
}

float vec2::distance(vec2 A){
float dist,Xdif,Ydif;
Xdif=X-A.X;
Ydif=Y-A.Y;
dist=sqrt((Xdif*Xdif)+(Ydif*Ydif));
return dist;
}

void vec2::translate(vec2 A){
X=X+A.X;
Y=Y+A.Y;
}

void vec2::rotate(float theta){
float X1,Y1;
X1=X;Y1=Y;
X=(cos(theta)*X1)-(sin(theta)*Y1);
Y=(sin(theta)*X1)+(cos(theta)*Y1);
}


void angle1()
{
vec2 A1,B1,C1,A2,B2,C2;
float theta;
//RefPts
A1.set(432.65559,200.82595);
B1.set(578.67881,201.60715);
C1=B1.sub(A1);

//Kokeshi pins
A2.set(506.55523,63.52049);
B2.set(504.19663,519.45358);
C2=B2.sub(A2);

theta=C1.CrossAngle(C2);
cout<<"Angle between Ref Pts and the Kok Pins is	"<<theta<<endl;


}



//Result
//Angle between Ref Pts and the Kok Pins is	89.9899 (1.57062)

//Correction is 90-89.9899 =
//				(+/-) 0.0101(0.00017)





