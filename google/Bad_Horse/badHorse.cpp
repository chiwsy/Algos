
#include<iostream>
#include<unordered_set>
#include<fstream>
#include<vector>
#include<utility>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;
void rec(const string& next, bool label, unordered_map<string,unordered_set<string> >& mp, unordered_map<string, bool>& loop, bool& flag,unordered_set<string>& tested){
    //cout<<next<<endl;
    if(loop.find(next)!=loop.end()){
        if(loop[next]!=label) {
                flag=false;
                //return;
        }
        return;
    }
    else{
        loop[next]=label;
        for(unordered_set<string>::iterator it=mp[next].begin();it!=mp[next].end()&&flag;++it)
            if(tested.find(*it)!=tested.end()) continue;
            else rec(*it,!label,mp,loop,flag,tested);
        loop.erase(next);
        tested.insert(next);
    }
}
int main(){
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int Times;
    fin>>Times;
    for(int tt=1;tt<=Times;tt++){
        unordered_map<string,unordered_set<string> > mp;
        int pairs;
        fin>>pairs;
        for(int i=0;i<pairs;i++){
            string first;
            string second;
            fin>>first;
            fin>>second;
            if(mp.find(first)==mp.end()) {
                mp[first]=unordered_set<string>();
                mp[first].insert(second);
            }
            else mp[first].insert(second);
            if(mp.find(second)==mp.end()) {
                mp[second]=unordered_set<string>();
                mp[second].insert(first);
            }
            else mp[second].insert(first);
        }
        unordered_map<string,bool> loop;
        bool flag=true;
        string first=mp.begin()->first;
        unordered_set<string> tested;
        rec(first,false, mp,loop,flag,tested);
        fout<<"Case #"<<tt<<": ";
        if(flag) fout<<"Yes"<<endl;
        else fout<<"No"<<endl;
        //flag=true;
    }
return 0;}
