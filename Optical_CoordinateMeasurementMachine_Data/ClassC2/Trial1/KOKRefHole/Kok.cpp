//This is to find the relative angle between the coordinate systems of the kokeshi pins and the reference holes
//Steps to Follow
//1) Get angle of misalignment of Kok-Pin (subtract 90 degrees) sys w.r.t. CMM coordinates by providing X,Y coordinates of Kok-Pin points to vec2 A & B
//2) Convert into radians
//3) Input angle of step 2 in radians to get the correct transformed Tilt/ Normal Angles. Make sure to give the correct data text file as input



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
void XYAngles();
double mag();
double CrossAngle(vec2 A);
vec2 vec2::GetUnit();
vec2 vec2::Rotate(double theta);
double vec2::dot(vec2 A);
};

double vec2::dot(vec2 A)
{double dt;
dt=(X*A.X)+(Y*A.Y);
return dt;
}

vec2 vec2::Rotate(double theta){
double X1,Y1; vec2 A;
X1=X;Y1=Y;
A.X=(cos(theta)*X1)-(sin(theta)*Y1);
A.Y=(sin(theta)*X1)+(cos(theta)*Y1);
return A;
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

void vec2::XYAngles()
{
double r,theta1,theta2;
r=sqrt((X*X)+(Y*Y));
theta1=acos(X/r);
theta2=asin(Y/r);
cout<<"theta1 = "<<(theta1*180/pi)<<"    theta2 = "<<(theta2*180/pi)<<endl;
//cout<<"theta1 = "<<theta1-(pi/2)<<"    theta2 = "<<theta2<<endl;
//cout<<"theta1 = "<<theta1<<"    theta2 = "<<theta2<<endl;
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

vec2::~vec2(double a,double b){}

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














void Kok()
{

//Ref pts 
vec2 A,B,C,UnitX,UnitY;//,D(1,-0.1);
A.set(432.65559,200.82595);
B.set(578.67881,201.60715);
C=B.sub(A);
//C.XYAngles();
UnitX=C.GetUnit();
UnitX.print();
UnitY=UnitX.Rotate(pi/2);
UnitY.print();

UnitX.XYAngles();

//Kok pins 
vec2 A1,B1,C1,UnitX1,UnitY1;//,D(1,-0.1);
A1.set(506.55523,63.52049);
B1.set(504.19663,519.45358);
C1=B1.sub(A1);
UnitY1=C1.GetUnit();
UnitY1.print();
UnitX1=UnitY1.Rotate(-pi/2);
UnitX1.print();

double x1,x2,y1,y2;
x1=UnitX1.dot(UnitX);
y1=UnitX1.dot(UnitY);

cout<<"************************"<<endl;
x2=UnitY1.dot(UnitX);
y2=UnitY1.dot(UnitY);


//Testing
vec2 UnitX2(x1,y1),UnitY2(x2,y2);
UnitX2.print();
UnitY2.print();
cout<<"************************"<<endl;
double x,y;vec2 Cp(0,0),Cpp(0,0);

x=C.dot(UnitX);y=C.dot(UnitY);
Cp.set(x,y);

Cp.print();
cout<<"************************"<<endl;

x=Cp.dot(UnitX2);y=Cp.dot(UnitY2);

Cpp.set(x,y);

Cpp.print();


}









