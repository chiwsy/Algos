
#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<stack>
using namespace std;

int main(){
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int N;
    fin>>N;
    char buff[1000];
    fin.getline(buff,1000,'\n');
    for(int strs=0;strs<N;strs++){
        stack<string> stk;

        fin.getline(buff,1000,'\n');

        istringstream is(buff);
        string tmp;
        while(is>>tmp) stk.push(tmp);
        fout<<"Case #"<<strs+1<<":";
        while(stk.size()>0) {
            fout<<' '<<stk.top();
            stk.pop();
        }
        fout<<endl;
    }

    return 0;
}
