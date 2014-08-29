#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int Times;
    fin>>Times;
    for(int tt=1;tt<=Times;tt++){
        int blocks;
        fin>>blocks;
        vector<double> naomi(blocks,0);
        vector<double> ken(blocks,0);

        for(int i=0;i<blocks;i++)
            fin>>naomi[i];
        for(int i=0;i<blocks;i++)
            fin>>ken[i];

        sort(naomi.begin(),naomi.end());
        sort(ken.begin(),ken.end());

        int nsd=0;
        int nfront=0,nend=blocks-1;
        int kfront=0,kend=blocks-1;
        while(nfront<=nend){
            if(naomi[nfront]<ken[kfront]){
                kend--;
                nfront++;
            }
            else{
                nsd++;
                nfront++;
                kfront++;
            }
        }

        int ns=0;
        nend=blocks-1;
        kfront=0;
        kend=blocks-1;
        while(kfront<=kend){
            if(naomi[nend]>ken[kend]){
                ns++;
                kfront++;
                nend--;
            }else{
                kend--;
                nend--;
            }
        }

        fout<<"Case #"<<tt<<": "<<nsd<<" "<<ns<<endl;
    }
return 0;}
