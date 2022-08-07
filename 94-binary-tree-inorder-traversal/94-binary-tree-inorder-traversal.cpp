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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        auto go = [&](auto& self, TreeNode* root) -> void {
            if (root == nullptr) return;
            
            self(self, root->left);
            ret.push_back(root->val);
            self(self, root->right);
        };
        
        go(go, root);
        
        return ret;
    }
};