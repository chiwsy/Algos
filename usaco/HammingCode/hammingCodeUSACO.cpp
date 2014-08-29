/*
ID: chiwsyl1
PROG: hamming
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;
bool diffone(int a, int b,const int& D){
    int cont=0;
    int c=a^b;
    while(c>0){
        if(c%2==1) cont++;
        c/=2;
        if(cont>=D) return true;
    }
    return false;
}
bool diff(vector<int>& res,int b, const int&D){
    for(int i=0;i<res.size();i++){
        if(!diffone(res[i],b,D)) return false;
    }
    return true;
}
int main(){
    int N,B,D;
    ifstream fin("hamming.in");
    fin>>N>>B>>D;
    fin.close();
    ofstream fout("hamming.out");
    vector<int> res(1,0);
    int max=1;
    for(int i=0;i<B;i++){
        max*=2;
    }
    int prev=0;
    for(int i=1;i<max&&res.size()<N;i++){
        if(diff(res,i,D)) {
            res.push_back(i);
        }
    }

    for(int i=0;i<res.size();){
        fout<<res[i++];
        if(i>0&&i%10==0) fout<<endl;
        else if(i<res.size()) fout<<' ';
        else fout<<endl;
    }

    return 0;
}
