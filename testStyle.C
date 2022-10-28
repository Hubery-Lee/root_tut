/*
 * @Description: 
 * @version: 
 * @Author: Hubery-Lee
 * @E-mail: hrbeulh@126.com
 * @Date: 2022-10-28 15:24:56
 * @LastEditTime: 2022-10-28 15:26:47
 * @LastEditors: Hubery-Lee
 */
#include "useful.h"
void testStyle()
{
    TH1F *h1 = new TH1F("h1","",100,-10,10);
    SetSgStyle();
    TH1F *h2 = new TH1F("h2","",100,-10,10);
    h1->FillRandom("gaus",1000);
    h2->FillRandom("gaus",1000);
    TCanvas *c1 = new TCanvas("c1","");
    c1->Divide(2,1);
    c1->cd(1);
    h1->Draw();
    c1->cd(2);
    h2->Draw();
    txtN(0.2,0.95,h2);// 自定义格式
}