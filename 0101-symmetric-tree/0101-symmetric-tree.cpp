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
    bool fun(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL) return true;
        else if(p==NULL || q==NULL) return false;
        
        if(p->val!=q->val) return false;
        bool l1=fun(p->left,q->right);
        bool r1=fun(p->right,q->left);
        return r1 && l1;
    }
    bool isSymmetric(TreeNode* root) {
        return fun(root->left,root->right);
    }
};