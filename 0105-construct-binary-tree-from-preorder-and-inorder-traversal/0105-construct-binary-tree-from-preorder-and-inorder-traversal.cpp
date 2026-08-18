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
    int idx = 0;
    unordered_map<int, int> mp;

    TreeNode* fun(vector<int>& inorder, vector<int>& preorder, int low,int high) {
        if (low > high)
            return NULL;
        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;
        int id = mp[node->val];
        node->left = fun(inorder, preorder, low, id - 1);
        node->right = fun(inorder, preorder, id + 1, high);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return fun(inorder, preorder, 0, n - 1);
    }
};