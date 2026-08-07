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
    bool fun(TreeNode* node,TreeNode*subRoot){
        if(node==NULL && subRoot==NULL){
            return true;
        }
        else if(node==NULL || subRoot==NULL) return false;
        if(node->val != subRoot->val) return false;
        bool l1=fun(node->left,subRoot->left);
        bool r1=fun(node->right,subRoot->right);
        
        return l1 && r1;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)return false;
        return fun(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);      
    }
};