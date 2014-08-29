#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int ndiff(const string& s1, const string& s2){
        int diff=0;
        for(int i=0;i<s1.length()&&diff<2;i++)
            if(s1[i]!=s2[i]) diff++;
        return diff;
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        if(start.length()!=end.length()) return vector<vector<string> >();
        if(!strcmp(start.c_str(),end.c_str())) return vector<vector<string> >(1, vector<string>(1,start));
        if(ndiff(start,end)==1) {
            vector<string> tmp;
            tmp.push_back(start);
            tmp.push_back(end);
            return vector<vector<string> >(1,tmp);
        };
        if(dict.size()<1) return vector<vector<string> >();

        int dis=INT_MAX;

        if(dict.find(start)!=dict.end())
            dict.erase(start);
        if(dict.find(end)==dict.end())
            dict.insert(end);

        queue<string> word;
        queue<int> dist;
        queue<vector<string> > ladd;
        unordered_map<string, int> layer;

        word.push(start);
        dist.push(1);
        ladd.push(vector<string>(1,start));

        vector<vector<string> > res;
        while(word.size()>0&&dist.front()<=dis){
            string curw=word.front();
            int curd=dist.front();
            //cout<<curd<<endl;
            vector<string> curl=ladd.front();
            word.pop();
            dist.pop();
            ladd.pop();

            if(!strcmp(curw.c_str(),end.c_str())) {
                //for(int i=0;i<curl.size();i++)
                //    cout<<curl[i]<<' ';
                //cout<<endl;
                res.push_back(curl);
                dis=curd;
                continue;
            }

            for(int i=0;i<curw.length();i++){
                string tmpw=curw;
                for(char c='a';c<='z';c++){
                    tmpw[i]=c;
                    if(dict.find(tmpw)!=dict.end()){
                            //cout<<tmpw<<endl;
                        if(layer.find(tmpw)==layer.end())
                            layer[tmpw]=curd+1;
                        if(curd<layer[tmpw]){
                            word.push(tmpw);
                            dist.push(curd+1);
                            curl.push_back(tmpw);
                            ladd.push(curl);
                            curl.pop_back();
                        }else dict.erase(tmpw);
                    }

                }
            }
        }

        return res;

    }
};

int main(){
    string start="nape";
    string en="mild";
    unordered_set<string> st;
    string str[]={"dose","ends","dine","jars","prow","soap","guns","hops","cray","hove","ella","hour","lens","jive","wiry","earl","mara","part","flue","putt","rory","bull","york","ruts","lily","vamp","bask","peer","boat","dens","lyre","jets","wide","rile","boos","down","path","onyx","mows","toke","soto","dork","nape","mans","loin","jots","male","sits","minn","sale","pets","hugo","woke","suds","rugs","vole","warp","mite","pews","lips","pals","nigh","sulk","vice","clod","iowa","gibe","shad","carl","huns","coot","sera","mils","rose","orly","ford","void","time","eloy","risk","veep","reps","dolt","hens","tray","melt","rung","rich","saga","lust","yews","rode","many","cods","rape","last","tile","nosy","take","nope","toni","bank","jock","jody","diss","nips","bake","lima","wore","kins","cult","hart","wuss","tale","sing","lake","bogy","wigs","kari","magi","bass","pent","tost","fops","bags","duns","will","tart","drug","gale","mold","disk","spay","hows","naps","puss","gina","kara","zorn","boll","cams","boas","rave","sets","lego","hays","judy","chap","live","bahs","ohio","nibs","cuts","pups","data","kate","rump","hews","mary","stow","fang","bolt","rues","mesh","mice","rise","rant","dune","jell","laws","jove","bode","sung","nils","vila","mode","hued","cell","fies","swat","wags","nate","wist","honk","goth","told","oise","wail","tels","sore","hunk","mate","luke","tore","bond","bast","vows","ripe","fond","benz","firs","zeds","wary","baas","wins","pair","tags","cost","woes","buns","lend","bops","code","eddy","siva","oops","toed","bale","hutu","jolt","rife","darn","tape","bold","cope","cake","wisp","vats","wave","hems","bill","cord","pert","type","kroc","ucla","albs","yoko","silt","pock","drub","puny","fads","mull","pray","mole","talc","east","slay","jamb","mill","dung","jack","lynx","nome","leos","lade","sana","tike","cali","toge","pled","mile","mass","leon","sloe","lube","kans","cory","burs","race","toss","mild","tops","maze","city","sadr","bays","poet","volt","laze","gold","zuni","shea","gags","fist","ping","pope","cora","yaks","cosy","foci","plan","colo","hume","yowl","craw","pied","toga","lobs","love","lode","duds","bled","juts","gabs","fink","rock","pant","wipe","pele","suez","nina","ring","okra","warm","lyle","gape","bead","lead","jane","oink","ware","zibo","inns","mope","hang","made","fobs","gamy","fort","peak","gill","dino","dina","tier"};
    for(int i=0;i<sizeof(str)/sizeof(string);i++)
        st.insert(str[i]);
    Solution s;
    s.findLadders(start,en,st);
    return 0;}
