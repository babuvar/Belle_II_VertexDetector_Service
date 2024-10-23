#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
double pi=acos(-1.0);
class vec2{
public:
double X,Y;
vec2();
vec2(double a,double b);
~vec2();
void set(double a,double b);
void print();
double distance(vec2 A);
void translate(vec2 A);
void rotate(double theta);
void copY(vec2 A);
void add(vec2 A);
vec2 sub(vec2 A);
void divide(double d);
double XYAngles();
double mag();
double CrossAngle(vec2 A);
vec2 vec2::Rotate(double theta);
};



double vec2::dot(vec2 A)
{double dt;
dt=(X*A.X)+(Y*A.Y);
return dt;
}

vec2 vec2::GetUnit()
{
vec2 B;
double r,x,y;
r=sqrt((X*X)+(Y*Y));
x=X/r;y=Y/r;
B.set(x,y);
return B;
}

double vec2::CrossAngle(vec2 A)
{
double d,m1,m2,t;
d=(X*A.X)+(Y*A.Y);
m1=sqrt((X*X)+(Y*Y));
m2=sqrt((A.X*A.X)+(A.Y*A.Y));
t=d/(m1*m2);
t=acos(t);
t=t*180/pi;
return t;
}

vec2 vec2::Rotate(double theta){
double X1,Y1; vec2 A;
X1=X;Y1=Y;
A.X=(cos(theta)*X1)-(sin(theta)*Y1);
A.Y=(sin(theta)*X1)+(cos(theta)*Y1);
return A;
}

vec2::vec2()
{
X=0;Y=0;
}

double vec2::mag()
{
double r;
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

void vec2::divide(double d)
{
X=X/d;
Y=Y/d;
}

double vec2::XYAngles()
{
double r,theta1,theta2;
r=sqrt((X*X)+(Y*Y));
theta1=acos(X/r);
theta2=asin(Y/r);
//cout<<"theta1 = "<<(theta1*180/pi)<<"    theta2 = "<<(theta2*180/pi)<<endl;
//cout<<"theta1 = "<<theta1-(pi/2)<<"    theta2 = "<<theta2<<endl;
//cout<<"theta1 = "<<theta1<<"    theta2 = "<<theta2<<endl;
return theta2;
}

vec2::vec2(double a,double b)
{
X=a;Y=b;
}

void vec2::set(double a,double b)
{
X=a;Y=b;
}

void vec2::copY(vec2 A)
{
X=A.X;
Y=A.Y;
}

vec2::~vec2(){}

void vec2::print()
{
cout<<X<<"\t"<<Y<<endl;
}

double vec2::distance(vec2 A){
double dist,Xdif,Ydif;
Xdif=X-A.X;
Ydif=Y-A.Y;
dist=sqrt((Xdif*Xdif)+(Ydif*Ydif));
return dist;
}

void vec2::translate(vec2 A){
X=X+A.X;
Y=Y+A.Y;
}

void vec2::rotate(double theta){
double X1,Y1;
X1=X;Y1=Y;
X=(cos(theta)*X1)-(sin(theta)*Y1);
Y=(sin(theta)*X1)+(cos(theta)*Y1);
}

class vec3{
public:
double X,Y,Z;
vec3();
vec3(double a,double b,double c);
~vec3();
void set(double a,double b,double c);
void print();
double distance(vec3 A);
void translate(vec3 A);
void rotate(double theta);
void copY(vec3 A);
void add(vec3 A);
vec2 sub(vec3 A);
void divide(double d);
double mag();
double CrossAngle(vec3 A);
void Rot3D(double a, double b, double c);
double dot(vec3 A);
double distance(vec3 A);
};

double vec3::distance(vec3 A){
double dist,Xdif,Ydif,Zdif;
Xdif=X-A.X;
Ydif=Y-A.Y;
Zdif=Z-A.Z;
dist=sqrt((Xdif*Xdif)+(Ydif*Ydif)+(Zdif*Zdif));
return dist;
}

double vec3::dot(vec3 A)
{double dt;
dt=(X*A.X)+(Y*A.Y)+(Z*A.Z);
return dt;
}

void vec3::Rot3D(double a, double b, double c)
{vec3 A,B,C,V; double c1,c2,c3,ap,bp,app,cpp;
c1=((a*a)+(b*b)); c1=sqrt(c1); c2=((a*a)+(b*b)+(c*c)); c2=sqrt(c2);
ap=a/c1; bp=b/c1; app=c1/c2; cpp=c/c2;

A.set((cpp*ap*ap)+(bp*bp),(cpp*ap*bp)-(ap*bp),ap*app);
B.set((cpp*ap*bp)-(ap*bp),(cpp*bp*bp)+(ap*ap),app*bp);
C.set(-ap*app,-app*bp,cpp);

V.set(X,Y,Z);
X=A.dot(V);
Y=B.dot(V);
Z=C.dot(V);
}

void vec3::rotate(double theta){
double X1,Y1;
X1=X;Y1=Y;
X=(cos(theta)*X1)-(sin(theta)*Y1);
Y=(sin(theta)*X1)+(cos(theta)*Y1);
}

double vec3::CrossAngle(vec3 A)
{
double d,m1,m2,t;
d=(X*A.X)+(Y*A.Y)+(Z*A.Z);
m1=sqrt((X*X)+(Y*Y)+(Z*Z));
m2=sqrt((A.X*A.X)+(A.Y*A.Y)+(A.Z*A.Z));
t=d/(m1*m2);
t=acos(t);
t=t*180/pi;
return t;
}


vec3::vec3()
{
X=0;Y=0;Z=0;
}

double vec3::mag()
{
double r;
r=sqrt((X*X)+(Y*Y)+(Z*Z));
return r;
}

void vec3::add(vec3 A)
{vec2 B;
X=X+A.X;
Y=Y+A.Y;
Z=Z+A.Z;
}

vec3 vec3::sub(vec3 A)
{vec3 B;
B.X=X-A.X;
B.Y=Y-A.Y;
B.Z=Z-A.Z;
return B;
}

void vec3::divide(double d)
{
X=X/d;
Y=Y/d;
Z=Z/d;
}


vec3::vec3(double a,double b,double c)
{
X=a;Y=b;Z=c;
}

void vec3::set(double a,double b,double c)
{
X=a;Y=b;Z=c;
}

void vec3::copY(vec3 A)
{
X=A.X;
Y=A.Y;
Z=A.Z;
}

vec3::~vec3(){}

void vec3::print()
{
cout<<X<<"\t"<<Y<<"\t"<<Z<<endl;
}

double vec3::distance(vec3 A){
double dist,Xdif,Ydif,Zdif;
Xdif=X-A.X;
Ydif=Y-A.Y;
Zdif=Z-A.Z;
dist=sqrt((Xdif*Xdif)+(Ydif*Ydif)+(Zdif*Zdif));
return dist;
}

void vec3::translate(vec3 A){
X=X+A.X;
Y=Y+A.Y;
Z=Z+A.Z;
}


void test()
{











}




