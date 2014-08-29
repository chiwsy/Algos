/*
ID: chiwsyl1
PROG: castle
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<set>

using namespace std;
void bfs(const int&V, int[] vr, const int& G, int[][] gr,int& sel, set<int>& cursel){
    set<int> nextsel;
    for(set<int>::iterator::sit=cursel.begin();sit!=cursel.end();++sit){
        int curvr[26]={0};
        sel=*sit;
        for(int i=0;i<G;i++){
            if(sel>>i&1)
                for(int j=0;j<V;j++){
                    curvr[j]+=gr[i][j];
                }
        }
        int fufill=0;
        for(int i=0;i<V;i++){
            if(curvr[i]>=vr[i]) fufill++;
        }
        if(fufill>=V) return;
        else for(int i=0;i<G;i++){
            if()
        }
    }
}
int main(){
    int V;
    int vr[26]={0};
    int G;
    int gr[16][26]={0};
    ifstream fin("holstein.in");
    fin>>V;
    for(int i=0;i<V;i++)
        fin>>vr[i];
    fin>>G;
    for(int i=0;i<G;i++)
        for(int j=0;j<V;j++)
        fin>>gr[i][j];

    int type=0;
    int sel=0;
    set<int> cursel;
    cursel.insert(sel);

    bfs(V,vr,G,gr,sel,cursel);
    int type=0;
    for(int i=0;i<G;i++)
        if(sel>>i&1){
            type++;
        }
    fout<<type;
    for(int i=0;i<G;i++)
        if(sel>>i&1) fout<<' '<<i;
    fout<<endl;

    return 0;
}
