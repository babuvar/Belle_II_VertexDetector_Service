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


void fshifts()
{

float x,y,z; int i=-1;
vec3 U[20],V[20],W[20],A1;
vec2 U1[20],V1[20],W1[20],A,B,C,UnitX,UnitY;
//Reading Data
ifstream fin;
//fin.open("fwf.txt");
fin.open("FW1.txt");
while(!fin.eof())
{i++;
fin>>x>>y>>z;
U[i].set(x,y,z);
U1[i].set(x,y);
//V[i].print();
}
fin.close();
i=-1;

//fin.open("cef.txt");
fin.open("CE1.txt");
while(!fin.eof())
{i++;
fin>>x>>y>>z;
V[i].set(x,y,z);
V1[i].set(x,y);
//V[i].print();
}
fin.close();
i=-1;
//fin.open("bwf.txt");
fin.open("BW1.txt");
while(!fin.eof())
{i++;
fin>>x>>y>>z;
W[i].set(x,y,z);
W1[i].set(x,y);
//V[i].print();
}
fin.close();


//Aligning w.r.t.  reference before assembly
vec2 A,B,C,UnitX,UnitY;//,D(1,-0.1);
vec3 UnitX1,UnitY1;
B.set(456.385,558.764);
A.set(450.684,102.850);
C=B.sub(A);
//C.XYAngles();
UnitY=C.GetUnit();
UnitY.print();
UnitX=UnitY.Rotate(-pi/2);
UnitX.print();

UnitX1.set(UnitX.X,UnitX.Y,0);
UnitY1.set(UnitY.X,UnitY.Y,0);

vec3 temp;
for(i=0;i<=15;i++){
temp=U[i].sub(A1);x=temp.dot(UnitX1);y=temp.dot(UnitY1);U[i].set(x,y,temp.Z);
temp=V[i].sub(A1);x=temp.dot(UnitX1);y=temp.dot(UnitY1);V[i].set(x,y,temp.Z);
temp=W[i].sub(A1);x=temp.dot(UnitX1);y=temp.dot(UnitY1);W[i].set(x,y,temp.Z);
}



vec3 L1,L2,L3,L4,M1,M2,M3,M4,N1,N2,N3,N4;
L1.add(U[0]);L1.add(U[1]);L1.add(U[2]);L1.add(U[3]);L1.divide(4);
L2.add(U[4]);L2.add(U[5]);L2.add(U[6]);L2.add(U[7]);L2.divide(4);
L3.add(U[8]);L3.add(U[9]);L3.add(U[10]);L3.add(U[11]);L3.divide(4);
L4.add(U[12]);L4.add(U[13]);L4.add(U[14]);L4.add(U[15]);L4.divide(4);
M1.add(V[0]);M1.add(V[1]);M1.add(V[2]);M1.add(V[3]);M1.divide(4);
M2.add(V[4]);M2.add(V[5]);M2.add(V[6]);M2.add(V[7]);M2.divide(4);
M3.add(V[8]);M3.add(V[9]);M3.add(V[10]);M3.add(V[11]);M3.divide(4);
M4.add(V[12]);M4.add(V[13]);M4.add(V[14]);M4.add(V[15]);M4.divide(4);
N1.add(W[0]);N1.add(W[1]);N1.add(W[2]);N1.add(W[3]);N1.divide(4);
N2.add(W[4]);N2.add(W[5]);N2.add(W[6]);N2.add(W[7]);N2.divide(4);
N3.add(W[8]);N3.add(W[9]);N3.add(W[10]);N3.add(W[11]);N3.divide(4);
N4.add(W[12]);N4.add(W[13]);N4.add(W[14]);N4.add(W[15]);N4.divide(4);

/*vec3 L,M,N;
L.add(L1);L.add(L2);L.add(L3);L.add(L4);L.divide(4);
L.print();
M.add(M1);M.add(M2);M.add(M3);M.add(M4);M.divide(4);
M.print();
N.add(N1);N.add(N2);N.add(N3);N.add(N4);N.divide(4);
N.print();*/


/*
//design values after assembly
vec3 L1p,L2p,L3p,L4p,M1p,M2p,M3p,M4p,N1p,N2p,N3p,N4p;
L1p.set(73+20.364,227.313+61.290,0);
L2p.set(73+30.156,227.313-61.290,0);
L3p.set(73-30.156,227.313-61.290,0);
L4p.set(73-20.364,227.313+61.290,0);
M1p.set(73+29.4,103+62.05,0);
M2p.set(73+29.4,103-62.05,0);
M3p.set(73-29.4,103-62.05,0);
M4p.set(73-29.4,103+62.05,0);
N1p.set(73+29.4,-22+62.05,0);
N2p.set(73+29.4,-22-62.05,0);
N3p.set(73-29.4,-22-62.05,0);
N4p.set(73-29.4,-22+62.05,0);
*/





//design values before assembly
vec3 L1p,L2p,L3p,L4p,M1p,M2p,M3p,M4p,N1p,N2p,N3p,N4p;
L1p.set(73+20.364,230.6345+62.637,0);
L2p.set(73+30.156,230.6345-62.637,0);
L3p.set(73-30.156,230.6345-62.637,0);
L4p.set(73-20.364,230.6345+62.637,0);
M1p.set(73+29.4,103+62.05,0);
M2p.set(73+29.4,103-62.05,0);
M3p.set(73-29.4,103-62.05,0);
M4p.set(73-29.4,103+62.05,0);
N1p.set(73+29.4,-22+62.05,0);
N2p.set(73+29.4,-22-62.05,0);
N3p.set(73-29.4,-22-62.05,0);
N4p.set(73-29.4,-22+62.05,0);









cout<<"Before Assembly";
//cout<<"After Assembly";
/*
cout<<endl<<"FW Point-1"<<endl;
L1.print();
cout<<endl<<"FW Point-2"<<endl;
L2.print();
cout<<endl<<"FW Point-3"<<endl;
L3.print();
cout<<endl<<"FW Point-4"<<endl;
L4.print();
cout<<endl<<"CE Point-1"<<endl;
M1.print();
cout<<endl<<"CE Point-2"<<endl;
M2.print();
cout<<endl<<"CE Point-3"<<endl;
M3.print();
cout<<endl<<"CE Point-4"<<endl;
M4.print();
cout<<endl<<"BW Point-1"<<endl;
N1.print();
cout<<endl<<"BW Point-2"<<endl;
N2.print();
cout<<endl<<"BW Point-3"<<endl;
N3.print();
cout<<endl<<"BW Point-4"<<endl;
N4.print();
*/
cout<<"*************************************"<<endl;

vec3 shift;
cout<<"Before Assembly";
//cout<<"After Assembly";

cout<<endl<<"FW Point-1 Shift"<<endl;
shift=L1.sub(L1p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm"<<endl;
cout<<endl<<"FW Point-2 Shift"<<endl;
shift=L2.sub(L2p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm"<<endl;
cout<<endl<<"FW Point-3 Shift"<<endl;
shift=L3.sub(L3p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm"<<endl;
cout<<endl<<"FW Point-4 Shift"<<endl;
shift=L4.sub(L4p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm"<<endl;
cout<<endl<<"CE Point-1 Shift"<<endl;
shift=M1.sub(M1p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm"<<endl;
cout<<endl<<"CE Point-2 Shift"<<endl;
shift=M2.sub(M2p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm"<<endl;
cout<<endl<<"CE Point-3 Shift"<<endl;
shift=M3.sub(M3p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm"<<endl;
cout<<endl<<"CE Point-4 Shift"<<endl;
shift=M4.sub(M4p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm"<<endl;
cout<<endl<<"BW Point-1 Shift"<<endl;
shift=N1.sub(N1p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm"<<endl;
cout<<endl<<"BW Point-2 Shift"<<endl;
shift=N2.sub(N2p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm"<<endl;
cout<<endl<<"BW Point-3 Shift"<<endl;
shift=N3.sub(N3p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm"<<endl;
cout<<endl<<"BW Point-4 Shift"<<endl;
shift=N4.sub(N4p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm"<<endl;




}//void Align()
















