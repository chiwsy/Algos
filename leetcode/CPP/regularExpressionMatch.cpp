#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(!s||!p) return false;
        if(!*s&&!*p) return true;
        if(!*p||*p=='*') return false;
        const char* ss=s;
        const char* pp=p;
        stack<pair<const char*, const char*> > stk;
        stack<pair<const char*, const char*> > emptystk;
        while(*s||*p){
            cout<<*s<<s-ss<<*p<<p-pp<<endl;
            if(*p==*s){
                p++;
                s++;
            }
            else if(*s&&*p=='.'){
                p++;
                s++;
            }
            else if(*p&&*(p+1)=='*'){
                p++;
                while(*p=='*') p++;
            }
            else if(*p=='*'){
                if(*(p-1)=='.')
                    stk=emptystk;
                stk.push(pair<const char*, const char*>(s,p-1));
                while(*p=='*')p++;
                s--;
            }
            else{
                if(stk.size()<1) return false;
                s=stk.top().first;
                p=stk.top().second;
                stk.pop();
            }
        }


        return true;

    }
};

int main(){
    const char* s="aaa";
    const char* p=".*c";
    Solution ss;
    cout<<ss.isMatch(s,p);
    return 0;
}
