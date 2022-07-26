/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<int, char> vis;
        TreeNode* ans = nullptr;
        
        auto go = [&](auto& self, TreeNode* root, TreeNode* target) -> bool {
            if (root == nullptr) return false;
            if (root == target) {
                vis[root->val]++;
                if (ans == nullptr && vis[root->val] == 2) ans = root;
                return true;
            }
            
            if (self(self, root->left, target) || self(self, root->right, target)) {
                vis[root->val]++;
                if (ans == nullptr && vis[root->val] == 2) ans = root;
                return true;
            }
            
            return false;
        };
        
        go(go, root, p);
        go(go, root, q);
        
        return ans;
    }
};