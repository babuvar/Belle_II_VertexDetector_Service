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
float distance(vec3 A);
};

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
cout<<X<<"\t"<<Y<<"\t"<<Z<<endl;
}

float vec3::distance(vec3 A){
float dist,Xdif,Ydif,Zdif;
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


void fgap()
{

float x,y,z; int i=-1;
vec3 U[20],V[20],W[20],A1;
vec2 U1[20],V1[20],W1[20],A,B,C,UnitX,UnitY;
//Reading Data
ifstream fin;
fin.open("FW_F");
//fin.open("fwf0.txt");
while(!fin.eof())
{i++;
fin>>x>>y>>z;
U[i].set(x,y,z);
U1[i].set(x,y);
//V[i].print();
}
fin.close();
i=-1;

fin.open("CE_F");
//fin.open("cef0.txt");
while(!fin.eof())
{i++;
fin>>x>>y>>z;
V[i].set(x,y,z);
V1[i].set(x,y);
//V[i].print();
}
fin.close();
i=-1;
fin.open("BW_F");
//fin.open("bwf0.txt");
while(!fin.eof())
{i++;
fin>>x>>y>>z;
W[i].set(x,y,z);
W1[i].set(x,y);
//V[i].print();
}
fin.close();

/*
//Aligning w.r.t.  reference before assembly
vec3 UnitX1,UnitY1;
B.set(571.164,212.1); 
A.set(425.167,214.3);
C=B.sub(A);
UnitX=C.GetUnit();
UnitY=UnitX.Rotate(pi/2);
//UnitY.print();
//UnitX.print();
*/

//Aligning w.r.t.  reference after assembly
vec2 A,B,C,UnitX,UnitY;//,D(1,-0.1);
vec3 UnitX1,UnitY1;
B.set(554.271,208.549);
A.set(408.275,206.991);
C=B.sub(A);
UnitX=C.GetUnit();
UnitY=UnitX.Rotate(pi/2);


UnitX1.set(UnitX.X,UnitX.Y,0);
UnitY1.set(UnitY.X,UnitY.Y,0);

/*
//FW-CE gap

vec2 P1(0,0),P2(0,0),P3(0,0),P4(0,0),Q1,Q2;
P1.add(U1[4]);P1.add(U1[5]);P1.add(U1[6]);P1.add(U1[7]);P1.divide(4);
P2.add(U1[8]);P2.add(U1[9]);P2.add(U1[10]);P2.add(U1[11]);P2.divide(4);
P3.add(V1[0]);P3.add(V1[1]);P3.add(V1[2]);P3.add(V1[3]);P3.divide(4);
P4.add(V1[12]);P4.add(V1[13]);P4.add(V1[14]);P4.add(V1[15]);P4.divide(4);

float d1,d2;
Q1=P1.sub(P3);d1=Q1.dot(UnitY);
Q2=P2.sub(P4);d2=Q2.dot(UnitY);
Q1.print();
Q2.print();

cout<<"d1 = "<<d1<<endl;
cout<<"d2 = "<<d2<<endl;

//CE-BW gap

P1.add(V1[4]);P1.add(V1[5]);P1.add(V1[6]);P1.add(V1[7]);P1.divide(4);
P2.add(V1[8]);P2.add(V1[9]);P2.add(V1[10]);P2.add(V1[11]);P2.divide(4);
P3.add(W1[0]);P3.add(W1[1]);P3.add(W1[2]);P3.add(W1[3]);P3.divide(4);
P4.add(W1[12]);P4.add(W1[13]);P4.add(W1[14]);P4.add(W1[15]);P4.divide(4);

Q1=P1.sub(P3);d1=Q1.dot(UnitY);
Q2=P2.sub(P4);d2=Q2.dot(UnitY);

Q1.print();
Q2.print();
cout<<"d3 = "<<d1<<endl;
cout<<"d4 = "<<d2<<endl;
*/

//FW-CE gap

vec3 P11(0,0,0),P12(0,0,0),P13(0,0,0),P14(0,0,0),Q11,Q12;
P11.add(U[4]);P11.add(U[5]);P11.add(U[6]);P11.add(U[7]);P11.divide(4);
//P11.print();
P12.add(U[8]);P12.add(U[9]);P12.add(U[10]);P12.add(U[11]);P12.divide(4);
P13.add(V[0]);P13.add(V[1]);P13.add(V[2]);P13.add(V[3]);P13.divide(4);
//P13.print();
P14.add(V[12]);P14.add(V[13]);P14.add(V[14]);P14.add(V[15]);P14.divide(4);

float d1,d2;
Q11=P11.sub(P13);d1=Q11.dot(UnitY1);
Q12=P12.sub(P14);d2=Q12.dot(UnitY1);
//Q11.print();
//Q12.print();

cout<<"d1 = "<<d1*1000<<" μm"<<endl;
cout<<"d2 = "<<d2*1000<<" μm"<<endl;

//CE-BW gap
P11.set(0,0,0);P12.set(0,0,0);P13.set(0,0,0);P14.set(0,0,0);
P11.add(V[4]);P11.add(V[5]);P11.add(V[6]);P11.add(V[7]);P11.divide(4);
//P11.print();
P12.add(V[8]);P12.add(V[9]);P12.add(V[10]);P12.add(V[11]);P12.divide(4);
P13.add(W[0]);P13.add(W[1]);P13.add(W[2]);P13.add(W[3]);P13.divide(4);
//P13.print();
P14.add(W[12]);P14.add(W[13]);P14.add(W[14]);P14.add(W[15]);P14.divide(4);

Q11=P11.sub(P13);d1=Q11.dot(UnitY1);
Q12=P12.sub(P14);d2=Q12.dot(UnitY1);

//Q11.print();
//Q12.print();
cout<<"d3 = "<<d1*1000<<" μm"<<endl;
cout<<"d4 = "<<d2*1000<<" μm"<<endl;




}//void Align()
















