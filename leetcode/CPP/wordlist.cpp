#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;


class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        if(S.length()<1)
            return vector<int>();
        if(L[0].length()<1)
            return vector<int>();
        unordered_map<string,int> mp;
        mp.clear();
        int len=L[0].length();
        vector<int> res;

        vector<int> occ;
        int k=0;
        for(int i=0;i<L.size();i++){
            if(mp.find(L[i])==mp.end()){
                mp[L[i]]=k;
                occ.push_back(0);
                k++;
            }
            occ[mp[L[i]]]++;
        }

        for(int i=0;i<=(int)(S.length()-len*L.size());i++){
            vector<int> flag(occ.size(),0);
            int j=i;
            cout<<i<<'\t';
            for(;(j<=S.length()-len)&&(j-i<=len*L.size());j+=len){
                string tmpstr=S.substr(j,len);
                if(mp.find(tmpstr)!=mp.end()){
                    if(flag[mp[tmpstr]]<occ[mp[tmpstr]]){
                        flag[mp[tmpstr]]++;
                    //i+=len;
                    }else {
                            //j=-1;
                            break;
                        }
                }else{
                    cout<<j<<'\t';
                    //j=-1;
                    break;
                }

            }
//            for(int k=0;k<flag.size()&&j>0;k++){
//                if(flag[k]!=0){
//                    j=-1;
//                    break;
//                }
//            }
            cout<<j<<endl;
            if((j-i)==len*L.size())
                res.push_back(i);
        }
        return res;
    }

};

int main(){
    Solution s;
    string str="a";
    string se[]={"ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba"};
    vector<string> l;
//    for(int i=0;i<200;i++)
//        l.push_back(se[i]);
    l.push_back("a");

    vector<int> t=s.findSubstring(str,l);
    for(int i=0;i<t.size();i++){
        cout<<t[i]<<endl;
    }
    return 0;
}
