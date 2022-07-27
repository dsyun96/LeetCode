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
    void flatten(TreeNode* root) {
        auto go = [&](auto& self, TreeNode* now) -> TreeNode* {
            if (now == nullptr) return nullptr;
            
            TreeNode* ret = now;
            TreeNode* right = now->right;
            if (now->left) {
                ret = self(self, now->left);
                ret->right = now->right;
                now->right = now->left;
                now->left = nullptr;
            }
            if (right) {
                ret = self(self, right);
            }
            
            return ret;
        };
        
        go(go, root);
    }
};