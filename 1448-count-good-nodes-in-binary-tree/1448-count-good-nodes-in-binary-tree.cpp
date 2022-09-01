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
    int goodNodes(TreeNode* root) {
        int ret = 0;
        auto go = [&](auto& self, TreeNode* now, int val = -0x3f3f3f3f) -> void {
            if (now == nullptr) return;
            
            ret += now->val >= val;
            self(self, now->left, max(now->val, val));
            self(self, now->right, max(now->val, val));
        };
        
        go(go, root);
        
        return ret;
    }
};