/**
 */// Definition for undirected graph.
 #include<vector>
 #include<iostream>
 #include<unordered_set>
 #include<unordered_map>
 using namespace std;

 struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
 };
 /**/
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        //original node pointer as key, cloned node pointer as value;
        unordered_map<UndirectedGraphNode *,UndirectedGraphNode *> mirror;
        mirror.clear();
        unordered_set<UndirectedGraphNode *> flag;
        flag.clear();

        if(node==NULL)
            return node;
        if(node->neighbors.size()==0)
            return new UndirectedGraphNode(node->label);


        UndirectedGraphNode* iter=node;
        UndirectedGraphNode* res=new UndirectedGraphNode(node->label);
        mirror[node]=res;
        traverse(iter,mirror,flag);
        flag.clear();
        iter=node;
        connect(iter,mirror,flag);
        return res;
    }

    void traverse(UndirectedGraphNode* iter, unordered_map<UndirectedGraphNode *,UndirectedGraphNode *> &mirror,unordered_set<UndirectedGraphNode *> &flag){
        if(flag.find(iter)!=flag.end()) return;
        flag.insert(iter);
        if(iter->neighbors.size()>0){
            for(int i=0;i<iter->neighbors.size();i++){
                cout<<i<<'\t'<<iter->neighbors[i]->label<<endl;
                if(mirror.find(iter->neighbors[i])!=mirror.end()) continue;
                mirror[iter->neighbors[i]]=new UndirectedGraphNode(iter->neighbors[i]->label);
                traverse(iter->neighbors[i],mirror,flag);
            }
        }
    }

    void connect(UndirectedGraphNode* iter, unordered_map<UndirectedGraphNode *,UndirectedGraphNode *> &mirror,unordered_set<UndirectedGraphNode *> &flag){
        if(flag.find(iter)!=flag.end()) return;
        flag.insert(iter);
        if(iter->neighbors.size()>0){
            for(int i=0;i<iter->neighbors.size();i++){
                //if(mirror.find(iter->neighbours[i])!=flag.end()) continue;
                cout<<i<<'\t'<<mirror[iter->neighbors[i]]->label<<endl;
                mirror[iter]->neighbors.push_back(mirror[iter->neighbors[i]]);
                connect(iter->neighbors[i],mirror,flag);
            }
        }
    }
};

int main(){
    UndirectedGraphNode* g0=new UndirectedGraphNode(-1);
    UndirectedGraphNode* g1=new UndirectedGraphNode(1);
    g0->neighbors.push_back(g1);
    g1->neighbors.push_back(g1);
    Solution s;
    UndirectedGraphNode* p=s.cloneGraph(g0);
    cout<<p->label<<endl;
    cout<<p->neighbors[0]->label<<endl;
    cout<<p->neighbors[0]->neighbors[0]->label<<endl;
}
