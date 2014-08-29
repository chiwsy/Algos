/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<iostream>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if (root==NULL)
            return 0;
        int res,tmp;
        mypath(root,res,tmp);
        return res;
    }

    void mypath(TreeNode* p, int &curMax, int& branMax){
        int lm=INT_MIN,lbm=INT_MIN;
        int rm=INT_MIN,rbm=INT_MIN;
        curMax=branMax=p->val;
        if(!p->left&&!p->right){
            curMax=branMax=p->val;
            return;
        }
        if(p->left){
            mypath(p->left,lm,lbm);
        }
        if(p->right){
            mypath(p->right,rm,rbm);

        }

        if(lbm>0) {
            curMax+=lbm;
            branMax+=lbm>rbm?lbm:rbm;
        }
        if(rbm>0) {
            //cout<<curMax<<'\t'<<rbm<<'\t'<<branMax<<endl;
            curMax+=rbm;
            branMax=lbm>rbm?lbm:rbm;
            branMax+=p->val;
            //cout<<curMax<<'\t'<<rbm<<'\t'<<branMax<<endl;
        }
        curMax=curMax>lm?curMax:lm;
        curMax=curMax>rm?curMax:rm;
        cout<<curMax<<endl;
    }

};

int main(){
    TreeNode* rt=new TreeNode(1);
    TreeNode* it=rt;
    for(int i=2;i<6;i++){
        it->right=new TreeNode(i);
        it=it->right;
    }

    Solution s;
    cout<<s.maxPathSum(rt)<<endl;

    return 0;
}
