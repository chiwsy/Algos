#include<iostream>
#include<vector>
#include<utility>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        if(ratings.size()==0)
            return 0;
        if(ratings.size()==1)
            return 1;

        vector<pair<int,int> > candy;//first is rating, second is candy;
        for(int i=0;i<ratings.size();i++)
            candy.push_back(pair<int,int>(ratings[i],1));

        for(int i=1;i<candy.size();i++){
            if(!isMin(i,candy)) continue;
            int k=i-1;
            while(k>-1&&k<i){
                if(isMax(k,candy)){
                    if(candy[k].second>candy[k+1].second||candy[k].first==candy[k+1].first)
                        break;
                    else{
                        candy[k].second=candy[k+1].second+1;
                        break;
                    }
                }

                candy[k].second=candy[k+1].second+1;
                k--;
            }

            i++;

            while(i<ratings.size()){
                if(isMax(i,candy)){
                    if(candy[i].first>candy[i-1].first)
                        candy[i].second=candy[i-1].second+1;
                    break;
                }
                if(candy[i].first>candy[i-1].first)
                    candy[i].second=candy[i-1].second+1;
                i++;
            }
        }

        int res=0;
        for(int i=0;i<candy.size();i++){
            cout<<i<<"\t"<<candy[i].first<<"\t"<<candy[i].second<<endl;
            res+=candy[i].second;
        }
        return res;

    }


    bool isMin(const int& i, vector<pair<int,int> >& ratings){
        if(i==0)
            return ratings[0].first<=ratings[1].first;
        else if(i==ratings.size()-1)
            return ratings[i].first<=ratings[i-1].first;
        else
            return ratings[i].first<=ratings[i-1].first&&ratings[i].first<=ratings[i+1].first;
    }

    bool isMax(const int& i, vector<pair<int,int> >& ratings){
        if(i==0)
            return ratings[0].first>=ratings[1].first;
        else if(i==ratings.size()-1)
            return ratings[i].first>=ratings[i-1].first;
        else
            return ratings[i].first>=ratings[i-1].first&&ratings[i].first>=ratings[i+1].first;
    }

};

int main(){
    Solution s;
    int t[]={10,1,1,1,1,1,1,1,1,10};
    vector<int> ss;
    for(int i=0;i<10;i++)
        ss.push_back(t[i]);

    s.candy(ss);
    return 0;
}
