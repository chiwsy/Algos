#include<iostream>
#include<vector>
using namespace std;
  //Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    inline void preorder(TreeNode* root){
        if(!root) return;
        cout<<root->val<<'\t';
        preorder(root->left);

        preorder(root->right);
    }
    inline TreeNode* dpcp(TreeNode* root,const int& start){
        if(!root) return NULL;
        TreeNode* nr=new TreeNode(root->val+start-1);
        cout<<nr->val<<'\t';
        if(root->left) nr->left=dpcp(root->left,start);
        else cout<<"llll\t";
        if(root->right) nr->right=dpcp(root->right,start);
        else cout<<"rrrr\t";
        return nr;
    }

    inline void build(int& root, vector<vector<TreeNode*> >& cache,const int& n){
        int left=root-1;
        int right=root+1;
        vector<TreeNode*> lt;
        for(int i=0;i<cache[left].size();i++){
            TreeNode* lti=new TreeNode(root);
            lti->left=dpcp(cache[left][i],1);
            cout<<endl;
            lt.push_back(lti);
        }

        if(right>n) {
            for(int i=0;i<lt.size();i++)
            cache[n].push_back(lt[i]);
            return;
        }

        for(int i=0;i<lt.size();i++){
            for(int j=0;j<cache[n-root].size();j++){
                TreeNode* lti=dpcp(lt[i],1);
                cout<<endl;
                lti->right=dpcp(cache[n-root][j],right);
                cout<<endl;
                cache[n].push_back(lti);
            }
        }
    }
    vector<TreeNode *> generateTrees(int n) {
        if(n<1) return vector<TreeNode*>(1,NULL);
        vector<vector<TreeNode*> > cache;
        cache.push_back(vector<TreeNode*>());
        cache.push_back(vector<TreeNode*>());

        cache[1].push_back(new TreeNode(1));
        cache[0].push_back(NULL);
        for(int i=2;i<=n;i++){
            cache.push_back(vector<TreeNode*>());
            for(int j=1;j<=i;j++){
                //vector<TreeNode*> cur;

                build(j,cache,i);
            }
        }
        //vector<bool> num(n+1,false);
        for(int i=0;i<cache[n].size();i++){
            cout<<i<<":\t";
            preorder(cache[n][i]);
            cout<<endl;
        }
        return cache[n];
    }
};

int main(){
    Solution s;
    s.generateTrees(3);
    return 0;
}
