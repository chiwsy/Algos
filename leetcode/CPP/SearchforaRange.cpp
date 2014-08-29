#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    inline int se(int A[],int n, double target){
        int start=0;
        int end=n-1;
        int mid=(start+end)/2;
        while(start<end){
            if(A[mid]>target){
                end=mid-1;
                mid=(start+end)/2;
            }else{
                start=mid+1;
                mid=(start+end)/2;
            }
        }
        return mid;
    }
    vector<int> searchRange(int A[], int n, int target) {
        if(n<1) return vector<int>(2,-1);
        if(target<A[0]||target>A[n-1]) return vector<int>(2,-1);
        int start=se(A,n,target-0.1);
        int end=se(A,n,target+0.1);
        cout<<start<<endl;
        if(A[start]!=target){
            if(start<n-1&&A[start+1]==target) start++;
            else if(start>0&&A[start-1]==target) start--;
            else start=-1;
        }
        cout<<start<<endl;
        if(A[end]!=target){
            if(end<n-1&&A[end+1]==target) end++;
            else if(end>0&&A[end-1]==target) end--;
            else end=-1;
        }
        vector<int> res;
        res.push_back(start);
        res.push_back(end);
        return res;

    }
};

int main(){
    int A[]={5,7,7,8,8,10};
    int tar=8;
    Solution s2;
    s2.searchRange(A,sizeof(A)/sizeof(int),tar);
    return 0;
}
