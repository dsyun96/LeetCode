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
    void f(TreeNode** root) {
        if ((*root)->left) f(&(*root)->left);
        if ((*root)->right) f(&(*root)->right);
        
        if (!(*root)->left && !(*root)->right) {
            if ((*root)->val == 0) *root = nullptr;
            return;
        }
    }
    TreeNode* pruneTree(TreeNode* root) {
        f(&root);
        return root;
    }
};