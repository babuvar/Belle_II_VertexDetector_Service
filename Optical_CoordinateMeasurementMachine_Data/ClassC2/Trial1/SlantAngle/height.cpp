//To plot the z vs y

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
vec2 vec2::GetUnit();
vec2 vec2::Rotate(float theta);
float vec2::dot(vec2 A);
};

float vec2::dot(vec2 A)
{float dt;
dt=(X*A.X)+(Y*A.Y);
return dt;
}

vec2 vec2::Rotate(float theta){
float X1,Y1; vec2 A;
X1=X;Y1=Y;
A.X=(cos(theta)*X1)-(sin(theta)*Y1);
A.Y=(sin(theta)*X1)+(cos(theta)*Y1);
return A;
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
//cout<<"theta1 = "<<theta1<<"    theta2 = "<<theta2<<endl;
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














void height()
{

//Ref pts angle w.r.t. CMM coordinates
vec2 A,B,C,UnitX,UnitY;//,D(1,-0.1);
B.set(554.906,221.184);
A.set(408.899,221.008);
C=B.sub(A);
//C.XYAngles();
UnitX=C.GetUnit();
UnitX.print();
UnitY=UnitX.Rotate(pi/2);
UnitY.print();

UnitX.XYAngles();


/*
//Kok sys angle w.r.t. CMM coordinates
vec2 A,B,C;//,D(1,-0.1);
A.set(506.55523,63.52049); //X & Y coordinates of 1st Kokeshi Pin are set to 2-D vector A
B.set(504.19663,519.45358); //X & Y coordinates of 2nd Kokeshi Pin are set to 2-D vector B
C=B.sub(A);
C.XYAngles();
//D.XYAngles();
*/



 gStyle->SetOptStat(0);
   gStyle->SetOptFit();
double x[1000],y[1000],z[1000];
double x1[1000],y1[1000],z1[1000];
double x2[1000],y2[1000],z2[1000];
int c=-1;int c1=-1;
int c2=-1;

//Reading Data
ifstream fin;
fin.open("fw.txt");
while(!fin.eof())
{c++;
fin>>x[c]>>y[c]>>z[c];
}
fin.close();

fin.open("bw.txt");
while(!fin.eof())
{c1++;
fin>>x1[c1]>>y1[c1]>>z1[c1];
}
fin.close();

fin.open("ce.txt");
while(!fin.eof())
{c2++;
fin>>x2[c2]>>y2[c2]>>z2[c2];
}
fin.close();

/*
float tempmaxz=-1000000,tempminz=1000000;
for(int i=0;i<=c-1;i++){
if(z[i]>=tempmaxz){tempmaxz=z[i];}
if(z[i]<=tempminz){tempminz=z[i];}
//cout<<x[i]<<"\t"<<y[i]<<"\t"<<z[i]<<endl;
}*/

//Fitting
TGraph *g = new TGraph();
TGraph *g1 = new TGraph();
TGraph *g2 = new TGraph();
for(int i=0;i<=c-1;i++){g->SetPoint(i,y[i],z[i]);}
for(int i=0;i<=c1-1;i++){g1->SetPoint(i,y1[i],z1[i]);}
for(int i=0;i<=c2-1;i++){g2->SetPoint(i,y2[i],z2[i]);}

TMultiGraph *mg = new TMultiGraph();

//TF2 *f = new TF2("f", "[0] + [1] * x + [2] * y"); // Equation of Plane
//  g->Fit(f);
//  g->Draw("TRI1");
  g->SetMarkerColor(kGreen);
  mg->Add(g);
  g1->SetMarkerColor(kBlue);
  mg->Add(g1);
  g2->SetMarkerColor(kRed);
  mg->Add(g2);

  mg->Draw("A*");

//  g1->Draw("A*");
//  g->GetYaxis()->SetRangeUser(tempminz,tempmaxz);

  mg->GetXaxis()->SetRangeUser(130,520);
  mg->GetYaxis()->SetRangeUser(85,130);



}









