/*
 * @Description:
 * @version:
 * @Author: Hubery-Lee
 * @E-mail: hrbeulh@126.com
 * @Date: 2022-10-13 20:48:56
 * @LastEditTime: 2022-10-15 22:18:56
 * @LastEditors: Hubery-Lee
 */
{
    TH1F *hist = new TH1F("hist", "Random Numbers", 200, -5, 10);
    hist->FillRandom("gaus");

    hist->SetFillColor(kGreen - 9);

    hist->GetXaxis()->SetTitle("Distribution");
    hist->GetYaxis()->SetTitle("Entries");

    hist->GetXaxis()->SetTitleSize(0.05);
    hist->GetYaxis()->SetTitleSize(0.05);
    hist->GetXaxis()->SetLabelSize(0.05);
    hist->GetYaxis()->SetLabelSize(0.05);

    TF1 *fit = new TF1("fit", "gaus", -5, 5);
    fit->SetLineWidth(3);
    // fit->SetLineColor (kBlue) ;
    fit->SetLineStyle(2);

    fit->SetParameter(0, 40);
    fit->SetParameter(1, 5);
    fit->SetParameter(2, 1);

    TCanvas *c1 = new TCanvas();
    c1->SetTickx();
    c1->SetTicky();
    c1->SetGridx();
    c1->SetGridy();

    //hist
    hist->SetStats(0);
    hist->Draw();
    //fit
    hist->Fit("fit", "R");

    // 图例
    TLegend *leg = new TLegend(0.5, 0.6, 0.8, 0.8);
    leg->SetBorderSize(1);

    leg->AddEntry(hist, "Measured Data", "f");
    leg->AddEntry(fit, "Fit Function", "L");
    leg->Draw();

    double mean = fit->GetParameter(1);
    double sigma = fit->GetParameter(2);
    cout << mean / sigma << endl;

    //添加线条
    TLine *l1 = new TLine(-5,40,10,40);
    l1->SetLineWidth(2);
    l1->SetLineColor(kOrange);
    l1->Draw();
    
    //添加箭头及文字
    double x0 =1.5;
    int bin = hist->FindBin(x0);
    double y0 = hist->GetBinContent(bin);

    TArrow *arr = new TArrow(4,80,x0,y0);
    arr->SetLineWidth(2);
    arr->SetArrowSize(0.02);
    arr->Draw();

    TLatex *t = new TLatex(4,80,"y=a\\cdot exp(x-\\mu/\\sigma)");
    t->Draw();
}