#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    inline void rec(string& s, int layer, int begin, string& prev, vector<string>& res){
        if(s.length()-begin<layer||s.length()-begin>3*layer) return;
        if(layer==1){
            //cout<<prev<<endl;
            int val=s[begin]-'0';
            for(int i=begin+1;i<s.length();i++){
                val*=10;
                val+=s[i]-'0';
            }
            if(val>255) {
                prev.pop_back();
                return;
            }
            else if(s[begin]=='0'&&val>0) {
                prev.pop_back();
                return;
            }
            else {
                //prev+='.';
                prev+=s.substr(begin,s.length()-begin);
                res.push_back(prev);
                for(int i=s.length();i>=begin;i--)
                    prev.pop_back();
            }
        }else{
            for(int i=0;i<3;i++){
                if(begin+i>=s.length()) break;
                if(i>0&&s[begin]=='0') break;
                if(i==2){
                    int val=(s[begin]-'0')*100+(s[begin+1]-'0')*10+s[begin+2]-'0';
                    if(val>255) break;
                }

                prev+=s.substr(begin,i+1);
                prev+='.';
                //cout<<prev<<endl;
                rec(s,layer-1,begin+i+1,prev,res);
                while(prev.back()!='.'&&prev.length()>0) prev.pop_back();
                //if(prev.back()=='.') prev.pop_back();
            }
            if(prev.back()=='.') prev.pop_back();
            return;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.length()<4||s.length()>12) return vector<string>();
        vector<string> res;
        string tmp;
        rec(s,4,0,tmp,res);
        return res;

    }
};

int main(){
    Solution sss;
    sss.restoreIpAddresses("010010");
    return 0;
}
