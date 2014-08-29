#include<iostream>
using namespace std;

class Solution {
public:
    double median(int A[],int m){
        if(m%2!=0) return A[m/2];
        else return (A[m/2]+A[m/2-1])/2.0;
    }

    int pos(int A[],int start,int end,int target){
        if(target<=A[start]) return start;
        if(target>A[end]) return end+1;

        int mid=(start+end)/2;
        while(start<=end){
            if(A[mid]==target){
                return mid;
            }
            else if(A[mid]<target){
                start=mid+1;
                mid=(start+end)/2;
            }
            else{
                end=mid-1;
                mid=(start+end)/2;
            }
        }
        if(A[start]<target) return start+1;
        return start;
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if(m<1&&n<1) return 0;
        if(m<1) return median(B,n);
        if(n<1) return median(A,m);

        int medianpos=(m+n)/2;
        int ast=0,aed=m-1;
        int bst=0,bed=n-1;
        int bpos=(bst+bed)/2;
        int apos=0;
        double res=0.0;
        while(bst<=bed){
            apos=pos(A,ast,aed,B[bpos]);
            cout<<apos<<endl;
            if(apos+bpos==medianpos) res+=B[bpos];
            else if(apos+bpos<medianpos){
                bst=bpos+1;
                ast=apos+1;
                bpos=(bst+bed)/2;
            }
            else{
                bed=bpos-1;
                aed=apos-1;
                bpos=(bst+bed)/2;
            }
            if(bst==bed) break;
        }
        if(apos+bpos!=medianpos){
            res+=A[medianpos-bpos];
        }
        if((m+n)%2!=0) return res;
        medianpos=(m+n)/2-1;
        ast=0,aed=m-1;
        bst=0,bed=n-1;
        bpos=(bst+bed)/2;

        while(bst<=bed){
            apos=pos(A,ast,aed,B[bpos]);
            if(apos+bpos==medianpos) res+=B[bpos];
            else if(apos+bpos<medianpos){
                bst=bpos+1;
                ast=apos+1;
                bpos=(bst+bed)/2;
            }
            else{
                bed=bpos-1;
                aed=apos-1;
                bpos=(bst+bed)/2;
            }
            if(bst==bed) break;
        }
        if(apos+bpos!=medianpos){
            res+=A[medianpos-bpos];
        }
        return res/2.0;
    }
};

int main(){
    int a[]={1};
    int b[]={1};
    Solution ss;
    cout<<ss.findMedianSortedArrays(a,sizeof(a)/sizeof(int),b,sizeof(b)/sizeof(int));
    return 0;}
