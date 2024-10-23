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


void fshifts_Kok()
{

double x,y,z; int i=-1;

vec3 U[20],V[20],W[20],A1,B1;
vec2 U1[20],V1[20],W1[20],A,B,C,UnitX,UnitY;
//Reading Data
ifstream fin;

fin.open("FW1.txt");
//fin.open("FW2.txt");
//fin.open("FW3.txt");
while(!fin.eof())
{i++;
fin>>x>>y>>z;
U[i].set(x,y,z);
U1[i].set(x,y);
//V[i].print();
}
fin.close();


i=-1;
fin.open("CE1.txt");
//fin.open("CE2.txt");
//fin.open("CE3.txt");
while(!fin.eof())
{i++;
fin>>x>>y>>z;
V[i].set(x,y,z);
V1[i].set(x,y);
//V[i].print();
}
fin.close();

i=-1;
fin.open("BW1.txt");
//fin.open("BW2.txt");
//fin.open("BW3.txt");
while(!fin.eof())
{i++;
fin>>x>>y>>z;
W[i].set(x,y,z);
W1[i].set(x,y);
//V[i].print();
}
fin.close();





//Aligning w.r.t.  reference after assembly
vec2 A,B,C,UnitX,UnitY;//,D(1,-0.1);
vec3 UnitX1,UnitY1;
vec3 UnitX1,UnitY1;
B.set(456.385,558.764);
A.set(450.684,102.850);
C=B.sub(A);
//C.XYAngles();
UnitX=C.GetUnit();
//UnitY.print();
UnitY=UnitX.Rotate(pi/2);
UnitX1.set(UnitX.X,UnitX.Y,0);
UnitY1.set(UnitY.X,UnitY.Y,0);


//vec3 K(482.242,83.368,88.0316590055);// Origin Point, taken as BW Kokeshi Pin center
vec3 K(450.684,102.850,106.297);// Origin Point, taken as BW Kokeshi Pin center
//vec3 p1(-73.15,137.76,0),p2(72.85,137.76,0),diffP1(0,0,0),diffP2(0,0,0);

/*vec3 temp;
temp=A1.sub(K);x=temp.dot(UnitX1);y=temp.dot(UnitY1);z=temp.Z;temp.set(x,y,z);
cout<<"****** P1 *******"<<endl;
temp.print();P1=temp.sub(p1);P1.divide(0.001);P1.print();
cout<<"****** P2 *******"<<endl;
temp=B1.sub(K);x=temp.dot(UnitX1);y=temp.dot(UnitY1);z=temp.Z;temp.set(x,y,z);
temp.print();P2=temp.sub(p2);P2.divide(0.001);P2.print();
*/

for(i=0;i<=15;i++){
temp=U[i].sub(K);x=temp.dot(UnitX1);y=temp.dot(UnitY1);U[i].set(x,y,temp.Z);
temp=V[i].sub(K);x=temp.dot(UnitX1);y=temp.dot(UnitY1);V[i].set(x,y,temp.Z);
temp=W[i].sub(K);x=temp.dot(UnitX1);y=temp.dot(UnitY1);W[i].set(x,y,temp.Z);
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



//design values after assembly
vec3 L1p,L2p,L3p,L4p,M1p,M2p,M3p,M4p,N1p,N2p,N3p,N4p;

/*
L1p.set(20.219,426.365,-13.021);
L2p.set(30.007,303.781,12.812);
L3p.set(-30.307,303.781,12.812);
L4p.set(-20.519,426.365,-13.021);


M1p.set(29.250,302.810,13.020);
M2p.set(29.250,178.710,13.020);
M3p.set(-29.550,178.710,13.020);
M4p.set(-29.550,302.810,13.020);

N1p.set(29.250,177.810,13.020);
N2p.set(29.250,53.710,13.020);
N3p.set(-29.550,53.710,13.020);
N4p.set(-29.550,177.810,13.020);
*/
L1p.set(426.365,-20.219,-13.021);
L2p.set(303.781,-30.007,12.812);
L3p.set(303.781,30.307,12.812);
L4p.set(426.365,20.519,-13.021);


M1p.set(302.810,-29.250,13.020);
M2p.set(178.710,-29.250,13.020);
M3p.set(178.710,29.550,13.020);
M4p.set(302.810,29.550,13.020);

N1p.set(177.810,-29.250,13.020);
N2p.set(53.710,-29.250,13.020);
N3p.set(53.710,29.550,13.020);
N4p.set(177.810,29.550,13.020);



vec3 shift;




cout<<endl<<"FW Point-1 Shift"<<endl;
shift=L1.sub(L1p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm\t zshift ="<<shift.Z*1000<<" μm"<<endl;
//cout<<"xshift= "<<L1.X<<" μm\t yshift ="<<L1.Y<<" μm\t zshift ="<<L1.Z<<" μm"<<endl;

cout<<endl<<"FW Point-2 Shift"<<endl;
shift=L2.sub(L2p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm\t zshift ="<<shift.Z*1000<<" μm"<<endl;
//cout<<"xshift= "<<L2.X<<" μm\t yshift ="<<L2.Y<<" μm\t zshift ="<<L2.Z<<" μm"<<endl;

cout<<endl<<"FW Point-3 Shift"<<endl;
cout<<"no data"<<endl;
//shift=L3.sub(L3p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm\t zshift ="<<shift.Z*1000<<" μm"<<endl;
//cout<<"xshift= "<<L3.X<<" μm\t yshift ="<<L3.Y<<" μm\t zshift ="<<L3.Z<<" μm"<<endl;

cout<<endl<<"FW Point-4 Shift"<<endl;
shift=L4.sub(L4p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm\t zshift ="<<shift.Z*1000<<" μm"<<endl;
//cout<<"xshift= "<<L4.X<<" μm\t yshift ="<<L4.Y<<" μm\t zshift ="<<L4.Z<<" μm"<<endl;


cout<<endl<<"CE Point-1 Shift"<<endl;
shift=M1.sub(M1p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm\t zshift ="<<shift.Z*1000<<" μm"<<endl;
//cout<<"xshift= "<<M1.X<<" μm\t yshift ="<<M1.Y<<" μm\t zshift ="<<M1.Z<<" μm"<<endl;

cout<<endl<<"CE Point-2 Shift"<<endl;
shift=M2.sub(M2p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm\t zshift ="<<shift.Z*1000<<" μm"<<endl;
//cout<<"xshift= "<<M2.X<<" μm\t yshift ="<<M2.Y<<" μm\t zshift ="<<M2.Z<<" μm"<<endl;

cout<<endl<<"CE Point-3 Shift"<<endl;
shift=M3.sub(M3p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm\t zshift ="<<shift.Z*1000<<" μm"<<endl;
//cout<<"xshift= "<<M3.X<<" μm\t yshift ="<<M3.Y<<" μm\t zshift ="<<M3.Z<<" μm"<<endl;

cout<<endl<<"CE Point-4 Shift"<<endl;
shift=M4.sub(M4p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm\t zshift ="<<shift.Z*1000<<" μm"<<endl;
//cout<<"xshift= "<<M4.X<<" μm\t yshift ="<<M4.Y<<" μm\t zshift ="<<M4.Z<<" μm"<<endl;


cout<<endl<<"BW Point-1 Shift"<<endl;
shift=N1.sub(N1p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm\t zshift ="<<shift.Z*1000<<" μm"<<endl;
//cout<<"xshift= "<<N1.X<<" μm\t yshift ="<<N1.Y<<" μm\t zshift ="<<N1.Z<<" μm"<<endl;

cout<<endl<<"BW Point-2 Shift"<<endl;
shift=N2.sub(N2p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm\t zshift ="<<shift.Z*1000<<" μm"<<endl;
//cout<<"xshift= "<<N2.X<<" μm\t yshift ="<<N2.Y<<" μm\t zshift ="<<N2.Z<<" μm"<<endl;

cout<<endl<<"BW Point-3 Shift"<<endl;
shift=N3.sub(N3p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm\t zshift ="<<shift.Z*1000<<" μm"<<endl;
//cout<<"xshift= "<<N3.X<<" μm\t yshift ="<<N3.Y<<" μm\t zshift ="<<N3.Z<<" μm"<<endl;

cout<<endl<<"BW Point-4 Shift"<<endl;
shift=N4.sub(N4p);cout<<"xshift= "<<shift.X*1000<<" μm\t yshift ="<<shift.Y*1000<<" μm\t zshift ="<<shift.Z*1000<<" μm"<<endl;
//cout<<"xshift= "<<N4.X<<" μm\t yshift ="<<N4.Y<<" μm\t zshift ="<<N4.Z<<" μm"<<endl;



}//void Align()
















