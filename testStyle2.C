/*
 * @Description: 
 * @version: 
 * @Author: Hubery-Lee
 * @E-mail: hrbeulh@126.com
 * @Date: 2022-10-28 15:32:53
 * @LastEditTime: 2022-10-28 15:32:54
 * @LastEditors: Hubery-Lee
 */
#include "useful.h"
void testStyle2()
{
    TH1F *h1 = newTH1F("h1",0.5,-10,10,kTRUE,1);
    SetSgStyle();
    TH1F *h2 = newTH1F("h2",0.5,-10,10,kTRUE,2);
    h1->FillRandom("gaus",1000);
    h2->FillRandom("gaus",1000);
    TCanvas *c1 = new TCanvas("c1","");
    c1->Divide(2,1);
    c1->cd(1);
    h1->Draw("EP");
    c1->cd(2);
    h2->Draw("EP");
    txtN(0.2,0.95,h2);
    LineX1(0.0);
}