/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
        TreeNode*prev=NULL;
        TreeNode*a=NULL;
        TreeNode*b=NULL;
        TreeNode*c=NULL;
        TreeNode*d=NULL;
        int count=0;
        void fun(TreeNode*root){
            if(root==NULL)return;
            fun(root->left);
            if(prev==NULL){
                prev=root;
            }
            else{
                if(root->val < prev->val){
                    if(count==0){
                        a=prev;
                        b=root;
                        count++;
                    }
                    else{
                        c=prev;
                        d=root;
                        count++;
                    }
                }
                prev=root;
            }
            fun(root->right);
        }
    void recoverTree(TreeNode* root) {
        fun(root);
        if(count==1){
            swap(a->val,b->val);
        }
        else{
            swap(a->val,d->val);
        }
    }
};