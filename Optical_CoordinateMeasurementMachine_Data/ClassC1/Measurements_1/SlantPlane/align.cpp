#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
class vec2{
public:
float x,y;
vec2();
vec2(float a,float b);
~vec2();
void set(float a,float b);
void print();
float distance(vec2 A);
void translate(vec2 A);
void rotate(float theta);
};

vec2::vec2()
{
x=0;y=0;
}

vec2::vec2(float a,float b)
{
x=a;y=b;
}

void vec2::set(float a,float b)
{
x=a;y=b;
}

vec2::~vec2(float a,float b){}

void vec2::print()
{
cout<<x<<"\t"<<y<<endl;
}

float vec2::distance(vec2 A){
float dist,xdif,ydif;
xdif=x-A.x;
ydif=y-A.y;
dist=sqrt((xdif*xdif)+(ydif*ydif));
return dist;
}

void vec2::translate(vec2 A){
x=x+A.x;
y=y+A.y;
}

void vec2::rotate(float theta){
float X,Y;
X=x;Y=y;
x=(cos(theta)*X)-(sin(theta)*Y);
y=(sin(theta)*X)+(cos(theta)*Y);
}

void align()
{
vec2 A[2];
A[0].set(1,2);
A[0].print();
A[1].set(3,4);
A[1].translate(A[0]);
A[1].print();

float length;
length=A[0].distance(A[1]);
//cout<<"Distance between them is "<<length<<endl;//A[0].distance(A[1])<<
cout<<"Distance between them is "<<A[0].distance(A[1])<<endl;

vec2 B(1,1);
B.rotate(3.1415);
cout<<"rotated B is"<<B.print();


}










