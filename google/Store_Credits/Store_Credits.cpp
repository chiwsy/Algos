#include<iostream>
#include<fstream>
//#include<map>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
bool mycompare(const pair<int,int>& a, const pair<int,int>& b){
    return a.first<b.first;
}

int main(){
    int N;
    ifstream fin("A-small-practice.in");
    ofstream fout("A-small-practice.out");
    fin>>N;
    for(int st=0;st<N;st++){
        int target;
        fin>>target;
        int items;
        fin>>items;
        vector<pair<int, int> > store;

        for(int i=0;i<items;i++){
            int tmp;
            fin>>tmp;
            //cout<<tmp<<endl;
            store.push_back(pair<int,int>(tmp,i));
            //mp[tmp]=i;
        }
        //cout<<"ok";
        sort(store.begin(),store.end(),mycompare);

        for(int i=0,j=store.size()-1;i<j;){
            if(store[i].first+store[j].first==target){
                if(store[i].second<store[j].second)
                    fout<<"Case #"<<st+1<<": "<<store[i].second+1<<' '<<store[j].second+1<<endl;
                else
                    fout<<"Case #"<<st+1<<": "<<store[j].second+1<<' '<<store[i].second+1<<endl;
                break;
            }else if(store[i].first+store[j].first<target)
                i++;
            else j--;
        }

    }
    return 0;
}
