#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
using namespace std;
#define PI  3.14159265358979323846
int main(){
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    int Times;
    fin>>Times;
    for(int tt=1;tt<=Times;tt++){
        double v;
        double d;
        fin>>v>>d;

        //fout.setf(ios::fixed)
        fout<<"Case #"<<tt<<": "<<fixed<<setprecision(8)<<asin((9.8*d/v/v)<1.?(9.8*d/v/v):1)*90/PI<<endl;
    }
return 0;}
