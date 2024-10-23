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
vec2 GetUnit();
};

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
theta2=asin(Y/r);
cout<<"theta1 = "<<(theta1*180/pi)<<"    theta2 = "<<(theta2*180/pi)<<endl;
//cout<<"theta1 = "<<theta1-(pi/2)<<"    theta2 = "<<theta2<<endl;
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

void Gap()
{
int ndata1=-1,ndata2=-1,i;
float x,y,z,X1[100],Y1[100],Z1[100],X2[100],Y2[100],Z2[100],m1,m2,c1,c2,a,b;

// 1. Read Data
ifstream fin;
fin.open("BWCEGapBWEdge");
//fin.open("FWCEGapCEEdge");
while(!fin.eof())
{
ndata1++;
fin>>x>>y>>z;
X1[ndata1]=x; Y1[ndata1]=y;Z1[ndata1]=z;
//cout<<x<<"\t"<<y<<"\t"<<z<<endl;
}
fin.close();
//cout<<"*********"<<endl;
ndata1--;//the last entry repeats itself. index runs from 0 to ndata1

//for(i=0;i<=ndata1;i++){cout<<X1[i]<<"\t"<<Y1[i]<<"\t"<<Z1[i]<<endl;}



fin.open("BWCEGapCEEdge");
//fin.open("FWCEGapFWEdge");
while(!fin.eof())
{
ndata2++;
fin>>x>>y>>z;
X2[ndata2]=x; Y2[ndata2]=y;Z2[ndata2]=z;
//cout<<x<<"\t"<<y<<"\t"<<z<<endl;

}
fin.close();
//cout<<"*********"<<endl;
ndata2--;//the last entry repeats itself. index runs from 0 to ndata2

//for(i=0;i<=ndata2;i++){cout<<X2[i]<<"\t"<<Y2[i]<<"\t"<<Z2[i]<<endl;}


// 2. Fit Lines
TGraph *g1 = new TGraph();
for(int i=0;i<=ndata1;i++){g1->SetPoint(i,X1[i],Y1[i]);}

TF1 *f1 = new TF1("f1", "[0] + [1] * x");

 g1->Fit(f1);

m1=f1->GetParameter(1);
c1=f1->GetParameter(0);

/*
cout<<"m = "<<f1->GetParameter(1)<<endl;
cout<<"c = "<<f1->GetParameter(0)<<endl;
cout<<"Em = "<<f1->GetParError(1)<<endl;
cout<<"Ec = "<<f1->GetParError(0)<<endl;*/

TGraph *g2 = new TGraph();
for(int i=0;i<=ndata2;i++){g2->SetPoint(i,X2[i],Y2[i]);}

TF1 *f2 = new TF1("f2", "[0] + [1] * x");

 g2->Fit(f2);

/*
cout<<"m = "<<f2->GetParameter(1)<<endl;
cout<<"c = "<<f2->GetParameter(0)<<endl;
cout<<"Em = "<<f2->GetParError(1)<<endl;
cout<<"Ec = "<<f2->GetParError(0)<<endl;*/

m2=f2->GetParameter(1);
c2=f2->GetParameter(0);

// 3. Get extreme points X1 & X2
float xlow=10000,xhigh=-10000;
for(i=0;i<=ndata1;i++){
if(X1[i] <= xlow){xlow=X1[i];}
if(X1[i] >= xhigh){xhigh=X1[i];}
}
//cout<<xlow<<endl;
//cout<<xhigh<<endl;

// 4. Get a & b from kokeshi pins
vec2 A,B,C,Unit;
A.set(506.55523,63.52049);
B.set(504.19663,519.45358);
C=B.sub(A);


Unit=C.GetUnit();
a=Unit.X;
b=Unit.Y;

//cout<<a<<endl;
//cout<<b<<endl;
//cout<<a*a+b*b<<endl;

// 5. Get D1 & D2 corresponding to X1 & X2
float D1,D2;
D1=((c2-c1)+(xlow*(m2-m1)))/((m2*a)-b);
D2=((c2-c1)+(xhigh*(m2-m1)))/((m2*a)-b);

//cout<<D1<<endl;
//cout<<D2<<endl;

// 6. Answer

cout<<"Gap at one end = "<<fabs(D1)*1000<<" microns"<<endl;
cout<<"Gap at other end = "<<fabs(D2)*1000<<" microns"<<endl;
cout<<"Average gap = "<<fabs(D1+D2)*500<<" microns"<<endl;


}









