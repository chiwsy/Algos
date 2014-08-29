#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        if(num.size()<3) return vector<vector<int> >();
        vector<vector<int> > res;

        sort(num.begin(),num.end());

        vector<int> cur(3,0);
        for(int i=0;i<num.size()-2;i++){
            if(i>0&&num[i]==num[i-1]) continue;
            for(int j=i+1,k=num.size()-1;j<k;){
                if(num[i]+num[j]+num[k]==0){
                    if(cur[0]!=num[i]||cur[1]!=num[j]||cur[2]!=num[k]||res.size()<1){
                        cur[0]=num[i];
                        cur[1]=num[j];
                        cur[2]=num[k];
                        res.push_back(cur);
                    }
                    j++;
                    k--;
                }
                else if(num[i]+num[j]+num[k]>0) k--;
                else j++;
            }
        }
        for(int i=0;i<res.size();i++)
            printf("%d\t[%d %d %d]\n",i,res[i][0],res[i][1],res[i][2]);
        return res;
        // unordered_map<int, int> mp;
        // for(int i=0;i<num.size();i++){
        //     if(mp.find(num[i])!=mp.end())
        //         mp[num[i]]++;
        //     else mp[num[i]]=1;
        // }
        // vector<int> cur(3,0);
        // //int old=num[0];
        // for(int i=0;i<num.size()&&num[i]<=0;i++){
        //     mp[num[i]]--;
        //     cur[0]=num[i];
        //     for(int j=i+1;j<num.size();j++){

        //         mp[num[j]]--;
        //         cur[1]=num[j];

        //         int tmp=-(num[i]+num[j]);

        //         if(tmp>=0&&tmp>=num[j]&&mp.find(tmp)!=mp.end()){
        //             if(mp[tmp]>0){
        //                 cur[2]=tmp;
        //                 //old=tmp;
        //                 if(res.size()<1){
        //                     //for(int ittt=0;ittt<3;ittt++)
        //                     //    cout<<cur[ittt]<<'\t';
        //                     //cout<<endl;
        //                     res.push_back(cur);
        //                 }
        //                 else if(cur[0]!=res.back()[0]||cur[1]!=res.back()[1]||cur[2]!=res.back()[2]){
        //                     //for(int ittt=0;ittt<3;ittt++)
        //                     //    cout<<cur[ittt]<<'\t';
        //                     //cout<<endl;
        //                     res.push_back(cur);
        //                 }
        //             }
        //         }
        //         mp[num[j]]++;
        //     }
        // }

        //return res;

    }
};

int main(){
    vector<int> num;
    num.push_back(-1);
    num.push_back(-2);
    num.push_back(-1);
    num.push_back(-1);
    num.push_back(0);
    num.push_back(0);
    num.push_back(-1);
    num.push_back(2);
    num.push_back(1);
    num.push_back(3);

    Solution sss;
    sss.threeSum(num);
    return 0;
}
