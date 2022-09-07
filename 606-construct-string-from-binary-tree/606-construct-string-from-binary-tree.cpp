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
    string tree2str(TreeNode* root) {
        auto go = [&](auto& self, TreeNode* now) -> string {
            if (now == nullptr) return "";
            
            string ret = to_string(now->val);
            if (now->left) ret += "(" + self(self, now->left) + ")";
            if (now->right) {
                if (!now->left) ret += "()";
                ret += "(" + self(self, now->right) + ")";
            }
            
            return ret;
        };
        
        return go(go, root);
    }
};