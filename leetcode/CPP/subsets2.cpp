#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        if(S.size()<1) return vector<vector<int> >(1,vector<int>());
        sort(S.begin(),S.end());
        vector<vector<int> > res(1,vector<int>());

        for(int i=0;i<S.size();i++){
            int size=res.size();
            if(i==0){
                cout<<"ok1!"<<endl;
                for(int j=0;j<size;j++){
                    vector<int> cur=res[j];
                    cur.push_back(S[i]);
                    res.push_back(cur);
                }
            }
            else if(i>0&&S[i]!=S[i-1]){
                for(int j=0;j<size;j++){
                    vector<int> cur=res[j];
                    cur.push_back(S[i]);
                    res.push_back(cur);
                }
            }else if(i>0&&S[i]==S[i-1]){

                for(int j=0;j<size;j++){
                    cout<<"ok2!"<<endl;
                    if(res[j].size()<1||res[j].back()!=S[i]) continue;

                    vector<int> cur=res[j];
                    cur.push_back(S[i]);
                    res.push_back(cur);
                }
            }
        }

        return res;
    }
};


int main(){
    Solution sss;
    vector<int> t(2,1);
    sss.subsetsWithDup(t);
    return 0;

}
