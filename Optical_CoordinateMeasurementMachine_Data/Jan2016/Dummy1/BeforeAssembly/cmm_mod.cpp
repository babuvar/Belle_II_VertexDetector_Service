#include "TVector3.h"
#include <vector>
#include "TVector3.h"
#include "TMath.h"
#include <cstring>
using namespace std;
using namespace ROOT;


int cmm_mod()
{

Double_t x,y,z; Int_t i=-1;
Double_t tempmaxz=-1000000,tempminz=1000000;
ifstream fin;
fin.open("FWRand"); 
TGraph2D *g = new TGraph2D();
while(!fin.eof())
{i++;
fin>>x>>y>>z; 
g->SetPoint(i,x,y,z);
if(z>=tempmaxz){tempmaxz=z;}
if(z<=tempminz){tempminz=z;}
}

fin.close();


TCanvas * c1 =new TCanvas();
TF2 *f = new TF2("f", "[0] + [1] * x + [2] * y"); // Equation of Plane
  g->Fit(f);
  g->Draw("P0 TRI1");
  g->GetZaxis()->SetRangeUser(tempminz,tempmaxz);


/*
TGraph2D *g = new TGraph2D();
fin.open("RandPF"); i=-1;
while(!fin.eof())
{i++;
fin>>x>>y>>z; 
g->SetPoint(i,x,y,z);
}
TF2 *f = new TF2("f", "[0] + [1] * x + [2] * y"); // Equation of Plane
  g->Fit(f);
  g->Draw("P0 TRI1");
  g->GetZaxis()->SetRangeUser(tempminz,tempmaxz);




TGraph2D *g2 = new TGraph2D();
fin.open("RandSen"); i=-1;
while(!fin.eof())
{i++;
fin>>x>>y>>z; 
g2->SetPoint(i,x,y,z);
}
TF2 *f2 = new TF2("f", "[0] + [1] * x + [2] * y"); // Equation of Plane
  g2->Fit(f2);
  g2->Draw("P0 TRI1 SAME");
  g2->GetZaxis()->SetRangeUser(tempminz,tempmaxz);

*/



}








