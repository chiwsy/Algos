#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main(){
    int T;
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    fin>>T;
    for(int tt=0;tt<T;tt++){
        double C,F,X;
        fin>>C>>F>>X;
        double cur=0;
        double rat=2.;
        double tim=0.;
        while(cur<X){
            //printf("%d %f %f %f\n",tt,cur,rat,tim);
            if(cur>=C){
                if((X-cur)/rat<(X-cur+C)/(rat+F)){

                    tim+=(X-cur)/rat;
                    cur=X;
                }
                else{
                    cur-=C;
                    rat+=F;
                }
            }
            else{
                tim+=(X-cur)<(C-cur)?(X-cur)/rat:(C-cur)/rat;
                cur+=(X-cur)<(C-cur)?(X-cur):(C-cur);
            }
        }
        //fout.setf(ios::fixed,ios::floatfield);
        //fout.setprecision(7);
        fout<<"Case #"<<tt+1<<": "<<setiosflags(ios::fixed)<<setprecision(8)<<tim<<endl;

    }

return 0;}
