/*
ID: chiwsyl1
PROG: frac1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<cmath>

using namespace std;

bool gcd(const int& a, const int& b){
    if(a==1) return false;
    for(int i=2;i<=a;i++){
        if(a%i==0&&b%i==0) return true;
    }
    return false;
}

int main(){
    map<double, string> mp;
    ifstream fin("frac1.in");
    int N;
    fin>>N;
    fin.close();

    ofstream fout("frac1.out");

    mp[0.0]="0/1";
    mp[1.0]="1/1";

    for(int i=1;i<=N;i++){
        for(int j=1;j<i;j++){
            //cout<<j<<' '<<i<<endl;
            if(!gcd(j,i)) {
                char buff[80];
                sprintf(buff,"%d/%d",j,i);
                //if(mp.find(j/(double)i)==mp.end())
                mp[j/(double)i]=buff;
            }
        }
    }

    for(map<double,string>::iterator mit=mp.begin();mit!=mp.end();++mit){
        fout<<mit->second.c_str()<<endl;
    }

    return 0;
}
