#include<iostream>
#include<fstream>
#include<string>
#include<queue>
using namespace std;

string mp(const char& c){
    switch(c){
        case 'c':
            return "222";
        case 'b':
            return "22";
        case 'a':
            return "2";

        case 'f':
            return "333";
        case 'e':
            return "33";
        case 'd':
            return "3";

        case 'i':
            return "444";
        case 'h':
            return "44";
        case 'g':
            return "4";

        case 'l':
            return "555";
        case 'k':
            return "55";
        case 'j':
            return "5";

        case 'o':
            return "666";
        case 'n':
            return "66";
        case 'm':
            return "6";

        case 's':
            return "7777";
        case 'r':
            return "777";
        case 'q':
            return "77";
        case 'p':
            return "7";

        case 'v':
            return "888";
        case 'u':
            return "88";
        case 't':
            return "8";

        case 'z':
            return "9999";
        case 'y':
            return "999";
        case 'x':
            return "99";
        case 'w':
            return "9";

        case ' ':
            return "0";

        defult:
            return "";
    }
}
int main(){
    int N;
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    fin>>N;
    char buff[1000];
    fin.getline(buff,1000,'\n');

    for(int strs=0;strs<N;strs++){
        fout<<"Case #"<<strs+1<<": ";
        fin.getline(buff,1000,'\n');
        queue<string> qu;
        for(int i=0;buff[i]!='\0';i++)
            qu.push(mp(buff[i]));
        while(qu.size()>1){
            string tmp=qu.front();
            fout<<tmp;
            qu.pop();
            if(tmp.back()==qu.front()[0]) fout<<' ';
        }
        fout<<qu.front()<<endl;
        qu.pop();

    }
    return 0;
}
