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
float XYAngles();
float mag();
float CrossAngle(vec2 A);
vec2 vec2::Rotate(float theta);
};



float vec2::dot(vec2 A)
{float dt;
dt=(X*A.X)+(Y*A.Y);
return dt;
}

vec2 vec2::GetUnit()
{
vec2 B;
float r,x,y;
r=sqrt((X*X)+(Y*Y));
x=X/r;y=Y/r;
B.set(x,y);
return B;
}

float vec2::CrossAngle(vec2 A)
{
float d,m1,m2,t;
d=(X*A.X)+(Y*A.Y);
m1=sqrt((X*X)+(Y*Y));
m2=sqrt((A.X*A.X)+(A.Y*A.Y));
t=d/(m1*m2);
t=acos(t);
t=t*180/pi;
return t;
}

vec2 vec2::Rotate(float theta){
float X1,Y1; vec2 A;
X1=X;Y1=Y;
A.X=(cos(theta)*X1)-(sin(theta)*Y1);
A.Y=(sin(theta)*X1)+(cos(theta)*Y1);
return A;
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

float vec2::XYAngles()
{
float r,theta1,theta2;
r=sqrt((X*X)+(Y*Y));
theta1=acos(X/r);
theta2=asin(Y/r);
//cout<<"theta1 = "<<(theta1*180/pi)<<"    theta2 = "<<(theta2*180/pi)<<endl;
//cout<<"theta1 = "<<theta1-(pi/2)<<"    theta2 = "<<theta2<<endl;
//cout<<"theta1 = "<<theta1<<"    theta2 = "<<theta2<<endl;
return theta2;
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

vec2::~vec2(){}

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

class vec3{
public:
float X,Y,Z;
vec3();
vec3(float a,float b,float c);
~vec3();
void set(float a,float b,float c);
void print();
float distance(vec3 A);
void translate(vec3 A);
void rotate(float theta);
void copY(vec3 A);
void add(vec3 A);
vec2 sub(vec3 A);
void divide(float d);
float mag();
float CrossAngle(vec3 A);
void Rot3D(float a, float b, float c);
float dot(vec3 A);
vec3 vec3::GetUnit();
};

vec3 vec3::GetUnit()
{
vec3 B;
float r,x,y,z;
r=sqrt((X*X)+(Y*Y)+(Z*Z));
x=X/r;y=Y/r;z=Z/r;
B.set(x,y,z);
return B;
}

float vec3::distance(vec3 A){
float dist,Xdif,Ydif,Zdif;
Xdif=X-A.X;
Ydif=Y-A.Y;
Zdif=Z-A.Z;
dist=sqrt((Xdif*Xdif)+(Ydif*Ydif)+(Zdif*Zdif));
return dist;
}

float vec3::dot(vec3 A)
{float dt;
dt=(X*A.X)+(Y*A.Y)+(Z*A.Z);
return dt;
}

void vec3::Rot3D(float a, float b, float c)
{vec3 A,B,C,V; float c1,c2,c3,ap,bp,app,cpp;
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

void vec3::rotate(float theta){
float X1,Y1;
X1=X;Y1=Y;
X=(cos(theta)*X1)-(sin(theta)*Y1);
Y=(sin(theta)*X1)+(cos(theta)*Y1);
}

float vec3::CrossAngle(vec3 A)
{
float d,m1,m2,t;
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

float vec3::mag()
{
float r;
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

void vec3::divide(float d)
{
X=X/d;
Y=Y/d;
Z=Z/d;
}


vec3::vec3(float a,float b,float c)
{
X=a;Y=b;Z=c;
}

void vec3::set(float a,float b,float c)
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
cout<<X<<"\t\t"<<Y<<"\t\t"<<Z<<endl;
}


void vec3::translate(vec3 A){
X=X+A.X;
Y=Y+A.Y;
Z=Z+A.Z;
}


void AlignFW_Kok()
{

float x,y,z; int i=-1;
vec3 V[20],A1,B1;
vec2 U[20],E[20],V1[20],A,B,C,UnitX,UnitY;
//Reading Data
ifstream fin;

//fin.open("FW1.txt");
//fin.open("FW2.txt");
fin.open("FW_F");


while(!fin.eof())
{i++;
fin>>x>>y>>z;x=x*(-1);
V[i].set(y,x,z);
V1[i].set(y,x);
}
fin.close();

B.set(558.764,-456.385);
A.set(102.850,-450.684); A1.set(102.850,-450.684,106.297);
C=B.sub(A);
//C.XYAngles();
UnitX=C.GetUnit();
UnitY=UnitX.Rotate(pi/2);


/*
//Center of Moment
vec3 CM(0,0,0),CM1,CM4; vec2 CM2,CM3;
for(i=0;i<=15;i++){CM.add(V[i]);}
CM.divide(16);CM3.set(CM.X,CM.Y);CM4.set(CM.X,CM.Y,CM.Z);
//CM.print();
CM1=CM.sub(A1); CM2.set(CM1.X,CM1.Y);
x =CM2.dot(UnitX);
y =CM2.dot(UnitY);
z=CM1.Z;
CM.set(x,y,z);
*/

//Center of Moment
vec3 CM(0,0,0),CM1,CM4; vec2 CM2,CM3; vec3 vecB(0,0,0),vecA(0,0,0),vecD(0,0,0),vecdiff,vecnunit;
for(i=4;i<=7;i++){CM.add(V[i]);} for(i=12;i<=15;i++){CM.add(V[i]);}CM.divide(8);
for(i=0;i<=3;i++){vecA.add(V[i]);} for(i=4;i<=7;i++){vecB.add(V[i]);}for(i=12;i<=15;i++){vecD.add(V[i]);}
vecA.divide(4);vecB.divide(4);vecD.divide(4);
vecdiff=vecB.sub(vecA); vecnunit=vecA.sub(vecD); vecnunit=vecnunit.GetUnit();
double factor=(-2)/(vecnunit.dot(vecdiff)); vecnunit=vecnunit.divide(factor);
CM.add(vecnunit);
CM3.set(CM.X,CM.Y);CM4.set(CM.X,CM.Y,CM.Z);
//CM.print();
CM1=CM.sub(A1); CM2.set(CM1.X,CM1.Y);
x =CM2.dot(UnitX);
y =CM2.dot(UnitY);
z=CM1.Z;
CM.set(x,y,z);
//CM.print();
cout<<(x-365.073)*1000<<"μm\t"<<(y-0.15)*1000<<"μm\t"<<(z-0.1045)*1000<<"μm"<<endl;//FW sensor after asswmbly


//3-D Rotations
float SumSqErr,BestErr=100000,Err,BestTheta,theta;
vec3 U1[20],E1[20];
float xytheta=UnitX.XYAngles();
U1[0].set(62.05+0.1,-20.219-0.1,0);
U1[1].set(62.05-0.1,-20.219-0.1,0);
U1[2].set(62.05-0.1,-20.219+0.1,0);
U1[3].set(62.05+0.1,-20.219+0.1,0);

U1[4].set(-62.05+0.1,-30.007-0.1,0);
U1[5].set(-62.05-0.1,-30.007-0.1,0);
U1[6].set(-62.05-0.1,-30.007+0.1,0);
U1[7].set(-62.05+0.1,-30.007+0.1,0);

//U1[8].set(-62.05+0.1,29.55-0.1,0);
//U1[9].set(-62.05-0.1,29.55-0.1,0);
//U1[10].set(-62.05-0.1,29.55+0.1,0);
//U1[11].set(-62.05+0.1,29.55+0.1,0);

U1[12].set(62.05+0.1,20.519-0.1,0);
U1[13].set(62.05-0.1,20.519-0.1,0);
U1[14].set(62.05-0.1,20.519+0.1,0);
U1[15].set(62.05+0.1,20.519+0.1,0);

BestErr=1000000;
cout<<endl;

/*
vec3 CM5(-CM4.X,-CM4.Y,-CM4.Z);
for(i=0;i<=15;i++)
{
V[i].translate(CM5);
V[i].Rot3D(-0.211407,-0.0024031,1);
V[i].print();
}*/

for(theta=-pi/20;theta <= pi/20;theta=theta+0.0001){
//for(theta=0;theta <= 0;theta=theta+0.0001){

SumSqErr=0;

float parA=-0.211407,parB=-0.0024031;//Values got from fitting Random pts on surface   BW

for(i=0;i<=7;i++)
{
E1[i].copY(U1[i]);
E1[i].rotate(xytheta);
E1[i].rotate(theta);
E1[i].Rot3D(-parA,-parB,1);
E1[i].translate(CM4);
//E1[i].print();
//V[i].print();
Err=V[i].distance(E1[i]);
//cout<<"Err = "<<Err<<endl;
SumSqErr=SumSqErr+(Err*Err);
}

for(i=12;i<=15;i++)
{
E1[i].copY(U1[i]);
E1[i].rotate(xytheta);
E1[i].rotate(theta);
E1[i].Rot3D(-parA,-parB,1);
E1[i].translate(CM4);
//E1[i].print();
//V[i].print();
Err=V[i].distance(E1[i]);
//cout<<"Err = "<<Err<<endl;
SumSqErr=SumSqErr+(Err*Err);
}




if(BestErr >= SumSqErr)
{
BestErr = SumSqErr;
BestTheta = theta;
}
//cout<<endl;
//cout<<"theta = "<<theta<<"\t SumSqErr = "<<SumSqErr<<endl;
}// theta loop


cout<<"Rot of sensor about its normal direction = "<<(BestTheta*180)/pi<<endl;


}//void Align()
















