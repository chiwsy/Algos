#include<iostream>
//#include<stdlib>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    string val2str(vector<int>& res,unordered_map<int, int>& mp){
        char buff[80];
        int cur=res[0];
        int times=1;
        for(int i=1;i<4;i++){
                cout<<cur<<mp[cur]<<endl;
            if(cur==res[i]) {
                times++;
            }else{
                if(times>mp[cur]) return "";
                times=1;
                cur=res[i];
            }
        }
        if(times>mp[cur]) return "";
        sprintf(buff,"%d %d %d %d",res[0],res[1],res[2],res[3]);
        return buff;
    }
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        if(num.size()<4) return vector<vector<int> >();
        sort(num.begin(),num.end());

        vector<vector<int> > res;

        map<int,vector<vector<int> > > mp;
        unordered_set<string> exist;
        exist.insert("");
        unordered_map<int,int> times;
        for(int i=0;i<num.size();i++){
            if(times.find(num[i])==times.end())
                times[num[i]]=1;
            else times[num[i]]++;
        }
        for(int i=0;i<num.size()-1;i++){
            //if(i>1&&num[i]==num[i-1]&&num[i]==num[i-2]) continue;
            vector<int> cur(2,0);
            cur[0]=num[i];

            for(int j=i+1;j<num.size();j++){
                //if(j>i+1&&num[j]==num[j-1]) continue;
                cur[1]=num[j];
                if(mp.find(num[i]+num[j])==mp.end()){
                    mp[num[i]+num[j]]=vector<vector<int> >();
                    mp[num[i]+num[j]].push_back(cur);
                }
                else mp[num[i]+num[j]].push_back(cur);
            }

        }
        map<int, vector<vector<int> > >::iterator mit=mp.begin(),mjt=mp.end();
        --mjt;
        while(mit!=mjt){
            if(mit->first+mjt->first>target) --mjt;
            else if(mit->first+mjt->first<target) ++mit;
            else{
                vector<int> cur(4,0);
                for(vector<vector<int> >::iterator vit=mit->second.begin();vit!=mit->second.end();++vit){
                    for(vector<vector<int> >::iterator vjt=mjt->second.begin();vjt!=mjt->second.end();++vjt){

                        cur[0]=(*vit)[0];
                        cur[1]=(*vit)[1];
                        cur[2]=(*vjt)[0];
                        cur[3]=(*vjt)[1];

                        for(int i=0;i<4;i++)
                            cout<<cur[i]<<'\t';
                        cout<<endl;
                        sort(cur.begin(),cur.end());
                        cout<<"ok";
                        string hash=val2str(cur,times);
                        cout<<"ok";
                        if(exist.find(hash)==exist.end()){
                            res.push_back(cur);
                            exist.insert(hash);
                        }
                    }
                }
                ++mit;
            }
        }
        if(mit==mjt){
            if(mit->first+mit->first==target&&mit->second.size()>1){
                for(int i=0;i<mit->second.size()-1;i++){
                    for(int j=i+1;j<mit->second.size();j++){
                        vector<int> cur(4,0);
                        cur[0]=mit->second[i][0];
                        cur[1]=mit->second[i][1];
                        cur[2]=mit->second[j][0];
                        cur[3]=mit->second[j][1];
                        sort(cur.begin(),cur.end());
                        string hash=val2str(cur,times);
                        cout<<hash<<endl;
                        if(exist.find(hash)==exist.end()){
                            res.push_back(cur);
                            exist.insert(hash);
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    int n[]={0,0,0,0};
    vector<int> num(n,n+sizeof(n)/sizeof(int));
    Solution sss;
    sss.fourSum(num,0);
    return 0;
}
