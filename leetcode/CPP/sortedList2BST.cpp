#include<iostream>
//#include<cmath>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


 // Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return new TreeNode(head->val);

        //ListNode* fast=head;
        ListNode* it=head;
        TreeNode* root=new TreeNode(0);
        unsigned int scale=0;
        while(it!=NULL){
            it=it->next;
            scale++;
        }

        int height=(double)log10((double)scale)/(double)log10(2.);
        int rem=scale-pow(2.0,height)+1;
        it=head;
        pre(it,root,rem,height);
        return root;
    }

    void pre(ListNode* &p, TreeNode* par,int& rem, const int& layer){
        static int curl=0;
        if(curl<layer-1){
            par->left=new TreeNode(0);
            curl++;
            pre(p,par->left,rem,layer);
            curl--;
        }else if(curl==layer-1&&rem>0){
            par->left=new TreeNode(0);
            rem--;
            curl++;
            pre(p,par->left,rem,layer);
            curl--;
        }else{
            par->val=p->val;
            p=p->next;
            cout<<curl<<'\t'<<par->val<<endl;
            return;
        }
        par->val=p->val;
        p=p->next;
        cout<<curl<<'\t'<<par->val<<endl;
        if(!p) return;
        if(curl<layer-1){
            par->right=new TreeNode(0);
            curl++;
            pre(p,par->right,rem,layer);
            curl--;
        }else if(curl==layer-1&&rem>0){
            par->right=new TreeNode(0);
            rem--;
            curl++;
            pre(p,par->right,rem,layer);
            curl--;
        }
    }
};

int main(){
    ListNode* head=new ListNode(0);
    ListNode* it=head;
    for(int i=1;i<50;i++,it=it->next)
        it->next=new ListNode(i);
    Solution s;
    s.sortedListToBST(head);
    return 0;
}
