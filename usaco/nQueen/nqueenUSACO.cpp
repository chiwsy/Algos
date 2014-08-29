/*
ID: chiwsyl1
PROG: checker
LANG: C++
*/


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Solution {
public:

    bool *cols;//= new bool[n];
    bool *pdgs;//= new bool[2*n-1];
    bool *ndgs;//= new bool[2*n-1];
    //vector<string> eptbd;
    vector<vector<int> > res;
    vector<int> current;
    int line;
    int scont;
    bool solveNQueens(int n) {
        if(n==1){
            //string tmp="Q";
            current.push_back(0);
            res.push_back(current);
            return 1;
        }

        if(n<4&&n>1)
            return 1;
        //bool *rows= new bool[n];
        scont=0;
        line=n-1;
        cols= new bool[n];
        pdgs= new bool[2*n-1];
        ndgs= new bool[2*n-1];
        //string tmp;
        //tmp.assign(n,'.');
        for(int i=0;i<n;i++){
            cols[i]=0;
            //eptbd.push_back(tmp);
            current.push_back(-1);
        }
        for(int i=0;i<2*n-1;i++)
            pdgs[i]=ndgs[i]=0;
        //current=eptbd;
        nextq();
        return 1;
    }

    void nextq(){
        static int curLine=0;
        if(curLine>line){
            scont++;
            res.push_back(current);
            return;
        }
        for(int i=0;i<=line;i++){
            if(!(cols[i]||pdgs[curLine+i]||ndgs[line-curLine+i])){
                cols[i]=pdgs[curLine+i]=ndgs[line-curLine+i]=1;
                current[curLine]=i;
                curLine++;
                nextq();
                curLine--;
                cols[i]=pdgs[curLine+i]=ndgs[line-curLine+i]=0;
                current[curLine]=-1;
            }
        }
    }

};

int main(){
    Solution s;
    ifstream fin("checker.in");
    ofstream fout("checker.out");
    int tmp;
    fin>>tmp;
    fin.close();
    s.solveNQueens(tmp);
    cout<<s.scont<<endl;
    for(int i=0;i<s.res.size()&&i<3;i++){
        int j=0;
        for(;j<s.res[i].size()-1;j++)
            fout<<s.res[i][j]+1<<' ';
        fout<<s.res[i][j]+1<<endl;
    }
    fout<<s.scont<<endl;
    fout.close();
    return 0;
}
