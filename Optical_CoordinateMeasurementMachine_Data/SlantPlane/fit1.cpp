#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
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
};

vec2::vec2()
{
X=0;Y=0;
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

void fit1()
{
int count=0;
float X,Y,Z;
vec2 A[16],B[16],C,D,E[16]; //A[] and B[] are the actual data points and the ideal points that we compare. C is the major translation vector, D is little translation vector

B[0].set(20.336+0.1,62.6125+0.1);
B[1].set(20.336+0.1,62.6125-0.1);
B[2].set(20.336-0.1,62.6125-0.1);
B[3].set(20.336-0.1,62.6125+0.1);
B[4].set(30.1315+0.1,-62.6125+0.1);
B[5].set(30.1315+0.1,-62.6125-0.1);
B[6].set(30.1315-0.1,-62.6125-0.1);
B[7].set(30.1315-0.1,-62.6125+0.1);
B[8].set(-30.1315+0.1,-62.6125+0.1);
B[9].set(-30.1315+0.1,-62.6125-0.1);
B[10].set(-30.1315-0.1,-62.6125-0.1);
B[11].set(-30.1315-0.1,-62.6125+0.1);
B[12].set(-20.336+0.1,62.6125+0.1);
B[13].set(-20.336+0.1,62.6125-0.1);
B[14].set(-20.336-0.1,62.6125-0.1);
B[15].set(-20.336-0.1,62.6125+0.1);


ifstream fin1;
fin1.open("slantref2");
//fin1.open("slantref2_2");
while(!fin1.eof())
{
fin1>>X>>Y>>Z;
A[count].set(X,Y);
//A[count].print();
count++;
if(count==16){break;}
}
fin1.close();

X=0;Y=0;

//centre point
for(count=0;count<=15;count++){
X=X+A[count].X; Y=Y+A[count].Y;
}
X=X/16;Y=Y/16;
C.set(X,Y);

//cout<<"C is "<<C.print(); 

float pi=acos(-1.0),SumSqErr,Err,BestErr=1000,BestTheta,BestX,BestY;
//cout<<"pi is "<<pi<<endl;



for(float theta=0;theta <= pi;theta=theta+0.001)
{
//for(float shiftX=-0.5; shiftX <= 0.5; shiftX=shiftX+0.1){
//for(float shiftY=-0.5; shiftY <= 0.5; shiftY=shiftY+0.1){
SumSqErr=0;
//D.set(shiftX,shiftY);
for(count=0;count<=15;count++)
{
E[count].copY(B[count]);
E[count].rotate(theta);
E[count].translate(C);
//E[count].translate(D);
Err=A[count].distance(E[count]);
SumSqErr=SumSqErr+(Err*Err);

//A[count].print(); B[count].print();
//cout<<endl;


}
//cout<<"final SumSqErr = "<<SumSqErr<<endl;
if(BestErr >= SumSqErr)
{
BestErr = SumSqErr;
BestTheta = theta;
//BestX= shiftX;
//BestY= shiftY;
}


//}//shiftY loop
//}//shiftX loop
}// theta loop

cout<<"BestTheta = "<<(BestTheta*180)/pi<<endl;
//cout<<"BestX = "<<BestX<<endl;
//cout<<"BestY = "<<BestY<<endl;





 gStyle->SetOptStat(0);
   gStyle->SetOptFit();
double x[100],y[100],z[100];
int c=-1;
ifstream fin;
//fin.open("slantref");
//fin.open("slantref2");
fin.open("slantpoints");
//fin.open("slantpoints_2");

while(!fin.eof())
{c++;
fin>>x[c]>>y[c]>>z[c];
}
fin.close();


float tempmaxz=-1000000,tempminz=1000000;
for(int i=0;i<=c-1;i++){
if(z[i]>=tempmaxz){tempmaxz=z[i];}
if(z[i]<=tempminz){tempminz=z[i];}
//cout<<x[i]<<"\t"<<y[i]<<"\t"<<z[i]<<endl;
}


TGraph2D *g = new TGraph2D();
for(int i=0;i<=c-1;i++){g->SetPoint(i,x[i],y[i],z[i]);}

TF2 *f = new TF2("f", "[0] + [1] * x + [2] * y");


  g->Fit(f);


  g->Draw("TRI1");
  g->Draw("SAME P0");
  g->GetZaxis()->SetRangeUser(tempminz,tempmaxz);


float t1,t2,T1,T2,phi=-BestTheta;
cout<<"phi is =====  "<<phi<<endl;
T1=atan(f->GetParameter(2));
T2=atan(f->GetParameter(1));


t1=(cos(phi)*tan(T1))+(sin(phi)*tan(T2));
t1=atan(t1);
t2=(-sin(phi)*tan(T1))+(cos(phi)*tan(T2));
t2=atan(t2);


cout<<endl<<"Fit parameters:"<<endl;
cout<<"Tilt angle(degrees) ="<<atan(f->GetParameter(2))*180/pi<<endl;
cout<<"Normal angle(degrees) ="<<atan(f->GetParameter(1))*180/pi<<endl;
cout<<"Error in Tilt angle(degrees) ="<<atan(f->GetParError(2))*180/pi<<endl;
cout<<"Error in Normal angle(degrees) ="<<atan(f->GetParError(1))*180/pi<<endl;



cout<<endl<<"CORRECTED VALUES"<<endl;
cout<<endl<<"Fit parameters:"<<endl;
cout<<"Tilt angle(degrees) ="<<t1*180/pi<<endl;
cout<<"Normal angle(degrees) ="<<t2*180/pi<<endl;



}







