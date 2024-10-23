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
void orient(vec2 A);
float dot(vec2 A);
void makeunit();
};

float vec2::dot(vec2 A)
{float dt;
dt=(X*A.X)+(Y*A.Y);
return dt;
}

void makeunit()
{vec2 A(X,Y); float m;
m=A.mag();
X=A.X/m;
Y=A.Y/m;
}

void vec2::orient(vec2 A)
{
float d;
vec2 Acopy(A.X,A.Y),Copy(X,Y),B,C;
Acopy.makeunit();
d=Copy.dot(Acopy);
X=d;
B.set(d*Acopy.X,d*Acopy.Y);
C=Acopy.sub(B);
Y=C.mag();
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

void shift()
{
int count=0,count1=0,i;
float x,y,z;
vec2 FW[16],CE[16],BW[16],REF[2];
ifstream fin;
fin.open("FW");
while(!fin.eof())
{
fin>>x>>y>>z;
FW[count].set(x,y);
FW[count].print();
count++;
if(count==16){break;}
}
fin.close();
cout<<"********************"<<endl;

fin.open("CEBW"); count=0;
while(!fin.eof())
{
fin>>x>>y>>z;

if(count <16){
CE[count].set(x,y);
CE[count].print();}
count++;
if(count>=16){
BW[count1].set(x,y);
BW[count1].print();
count1++;
}
if(count ==32){break;}
}//while
fin.close();
cout<<"*********************"<<endl;
fin.open("REF"); count=0;
while(!fin.eof())
{fin>>x>>y>>z;
REF[0].set(x,y);
REF[0].print();
fin>>x>>y>>z;
REF[1].set(x,y);
REF[1].print();
break;
}
fin.close();

//Shift
vec2 A,B,C,REFV;
for(i=0;i<=15;i++){
A.add(FW[i]);
B.add(CE[i]);
C.add(BW[i]);
}
A.divide(16);
B.divide(16);
C.divide(16);

A=A.sub(REF[0]);
B=B.sub(REF[0]);
C=C.sub(REF[0]);
REFV=REF[0]-REF[1];

A.orient(REFV);
B.orient(REFV);
C.orient(REFV);



}//end of shift()





