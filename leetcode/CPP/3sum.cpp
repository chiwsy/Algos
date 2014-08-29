#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        if(num.size()<3) return vector<vector<int> >();
        vector<vector<int> > res;

        sort(num.begin(),num.end());

        unordered_map<int, int> mp;
        for(int i=0;i<num.size();i++){
            if(mp.find(num[i])!=mp.end())
                mp[num[i]]++;
            else mp[num[i]]=1;
        }
        vector<int> cur(3,0);
        //int old=num[0];
        for(int i=0;i<num.size()&&num[i]<=0;i++){
            mp[num[i]]--;
            cur[0]=num[i];
            for(int j=i+1;j<num.size();j++){

                mp[num[j]]--;
                cur[1]=num[j];

                int tmp=-(num[i]+num[j]);

                if(tmp>=0&&tmp>=num[j]&&mp.find(tmp)!=mp.end()){
                    if(mp[tmp]>0){
                        cur[2]=tmp;
                        //old=tmp;
                        if(res.size()<1){
                            for(int ittt=0;ittt<3;ittt++)
                                cout<<cur[ittt]<<'\t';
                            cout<<endl;
                            res.push_back(cur);
                        }
                        else if(cur[0]!=res.back()[0]||cur[1]!=res.back()[1]||cur[2]!=res.back()[2]){
                            for(int ittt=0;ittt<3;ittt++)
                                cout<<cur[ittt]<<'\t';
                            cout<<endl;
                            res.push_back(cur);
                        }
                    }
                }
                mp[num[j]]++;
            }
        }

        return res;

    }
};

/*
class Solution {
public:
vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > result;
    int n = (int)num.size();
    if (n > 2) {
        sort(num.begin(), num.end());

        for (int i = 1; i < n - 1; ++i) {
            if (i > 2 && num[i] == num[i - 2]) continue;
            int l = 0, r = n - 1;
            while (l < i && r > i) {
                if (l > 1 && num[l] == num[l - 1]) {
                    ++l; continue;
                }
                if (r < n - 1 && num[r] == num[r + 1]) {
                    --r; continue;
                }
                int sum = num[l] + num[i] + num[r];
                if (sum == 0) {
                    vector<int> item;
                    item.push_back(num[l]);
                    item.push_back(num[i]);
                    item.push_back(num[r]);
                    bool flag = false;
                    for (int j = 0; j < result.size(); ++j) {
                        if (result[j][0] == num[l] && result[j][1] == num[i]) {
                            flag = true; break;
                        }
                    }
                    if (!flag) {
                            for(int it=0;it<3;it++)
                                cout<<item[it]<<'\t';
                            cout<<endl;
                            result.push_back(item);
                    }
                    ++l; --r;
                } else if (sum < 0) ++l; else --r;
            }
        }
    }
    return result;
}
};
*/
int main(){
    vector<int> num(9,0);
    num[0]=-1;
    num[1]=-1;
    num[2]=-1;
    num[3]=-1;
    num[4]=1;
    num[5]=1;
    num[6]=-2;
    num[7]=3;
    num[8]=4;
    Solution s;
    s.threeSum(num);
    return 0;
}
