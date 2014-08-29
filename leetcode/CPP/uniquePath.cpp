#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0||n==0) return 0;
        int total=m+n-1;
        //int row=m-1,col=n-1;
        long long frup=1;
        int frdw=1;
        if(n<m){
            int tmp=m;
            m=n;
            n=tmp;
        }
        //for(int i=2;i<m;i++){
        //    frdw*=i;
        //}

        int i=n;
        int j=1;
        for(;i<total;i++){
            frup*=i;
            while(j<m&&frup%j==0){
                frup/=j;
                j++;
            }
            cout<<i<<"\t"<<frup<<endl;
        }

        //cout<<i<<"\t"<<frup<<endl;
        return (int)frup;
    }
};

int main(){
    Solution s;
    s.uniquePaths(51,9);
    return 0;
}
