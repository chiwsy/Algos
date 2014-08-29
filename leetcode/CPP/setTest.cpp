#include<set>
#include<iostream>
using namespace std;

int main(){
    set<double> s;
    s.insert(3);
    s.insert(4);
    s.insert(1);
    s.insert(3);
    s.insert(5);

    s.erase(s.begin());

    for(set<double>::iterator it=s.begin();it!=s.end();++it)
        cout<<(*it)<<endl;
    return 0;
}
