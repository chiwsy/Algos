#include<iostream>
#include<fstream>

#include<sstream>
#include<cmath>
#include<queue>
#include<stack>
#include<utility>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<vector>

using namespace std;
string cont(const int & a){
    switch(a){
        case 2: return " double";
        case 3: return " triple";
        case 4: return " quadruple";
        case 5: return " quintuple";
        case 6: return " sextuple";
        case 7: return " septuple";
        case 8: return " octuple";
        case 9: return " nonuple";
        case 10: return " decuple";
    }
}

string number(const int& a){
    switch(a){
        case 0: return " zero";
        case 1: return " one";
        case 2: return " two";
        case 3: return " three";
        case 4: return " four";
        case 5: return " five";
        case 6: return " six";
        case 7: return " seven";
        case 8: return " eight";
        case 9: return " nine";
    }
}

int main(){
    ifsream fin("in.txt");
    ofstream fout("out.txt");
    int times;
    fin>>times;
    for(int tt=0;tt<times;tt++){
        string num;
        fin>>num;
        string form;
        fin>>form;
        istringstream is(form);
        fout<<"Case #"<<tt<<":";
        char buff[80];
        int i=0;
        while(is.getline(buff,80,'-')){
            int j=0;
            for(;j<atoi(buff);j++){
                int conter=0;
                while(j<atoi(buff)&&num)
            }
            i+=j;
        }

    }

    return 0;
    }
