//参考 root tutorial/graphs/zdemo.C  /fit/FittingDemo.C

#include "iostream"
#include "fstream"
#include "vector"
#include "cstring"
#include "string.h"

using namespace std;

const int NMAX=20;
double xx[NMAX],yy[NMAX];

class ReadData
{
public:
 
  ReadData(string fname)
  {
    filename=fname;
  };
  ~ReadData(){};

  void GetData();
private:
  string filename;
};

void ReadData::GetData()
{
  ifstream input(filename);
  double a,b;
  vector<double> x,y;
  int i=0;
  while(!input.eof())
    {
      i++;
      a=i*5;
      input>>b;
      x.push_back(a);
      y.push_back(1.0-(b/1.e6));
    }
  input.close();
  i=i-1;

  for(int j=0;j<i&&j<NMAX;j++)
    {
      xx[j]=x[j],yy[j]=y[j];
    }
}



void plot()
{

  ReadData a1("./EJ200-100/data.txt");
  a1.GetData();

  TGraph *g1 =new TGraph(NMAX,xx,yy);
  g1->SetLineColor(38);
  g1->SetMarkerColor(kBlue);
  g1->SetMarkerStyle(21);
  g1->SetMarkerSize(1.1);
  g1->Draw("AP");
  
  ReadData a2("./EJ200-140/data.txt");
  a2.GetData();

  TGraph *gr2 = new TGraph(NMAX,xx,yy);
  gr2->SetLineColor(38);
  gr2->SetMarkerColor(kRed);
  gr2->SetMarkerStyle(29);
  gr2->SetMarkerSize(1.5);
  gr2->Draw("P");

  ReadData a3("./EJ200-180/data.txt");
  a3.GetData();

  TGraph *gr3 = new TGraph(NMAX,xx,yy);

  gr3->SetLineColor(38);
  gr3->SetMarkerColor(6);
  gr3->SetMarkerStyle(8);
  gr3->SetMarkerSize(1.1);
  gr3->Draw("P");

  //////////////////
  ////
  //      elta = 1-exp(a*x) //拟合函数形式

  TF1 *fun =new TF1("#elta = 1-exp(A*x)","1.-exp([0]*x)",0,100);
  fun->SetLineColor(kBlue);fun->SetLineStyle(2);
  g1->Fit(fun);

  fun->SetLineColor(kRed);fun->SetLineStyle(2);
  gr2->Fit(fun);

  fun->SetLineColor(6);fun->SetLineStyle(2);
  gr3->Fit(fun);

  //////////////////
  //
  //  legend
  TLegend *lg=new TLegend(0.6,0.65,0.88,0.85);
  lg->SetTextFont(62);
  lg->SetTextAlign(12);
  lg->SetTextSize(0.04);
  lg->AddEntry(g1,"100keV","p");
  lg->AddEntry(gr2,"140keV","p");
  lg->AddEntry(gr3,"180keV","p");
  lg->AddEntry(fun," #eta = 1-exp(#mu *x)","l");
  lg->Draw();
}


