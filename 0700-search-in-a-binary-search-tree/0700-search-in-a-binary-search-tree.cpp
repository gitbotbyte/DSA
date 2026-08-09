/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* res = NULL;
    void fun(TreeNode* root, int val) {
        if (root == NULL)
            return;
        else if (root->val == val) {
            res = root;
        }
        if (root->val > val) {
            fun(root->left, val);
        } else {
            fun(root->right, val);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        fun(root, val);
        return res;
    }
};