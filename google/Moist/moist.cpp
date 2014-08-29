#include<iostream>
#include<fstream>
#include<set>
#include<string>
using namespace std;

int main(){
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int Times;
    fin>>Times;
    char buff[100];
    fin.getline(buff,100,'\n');
    for(int tt=1;tt<=Times;tt++){
        int costs=0;
        int names;
        fin>>names;
        fin.getline(buff,100,'\n');
        set<string> st;
        for(int i=0;i<names;i++){
            fin.getline(buff,100,'\n');
            st.insert(buff);
            if(st.find(buff)!=--st.end()) costs++;
        }
        fout<<"Case #"<<tt<<": "<<costs<<endl;
    }
    return 0;
}
