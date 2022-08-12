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
        unordered_set<TreeNode*> S;
        TreeNode* ret = nullptr;
        auto go = [&](auto& self, TreeNode* now, TreeNode* target) -> bool {
            if (now == nullptr) return false;
            if (now == target) {
                if (S.find(now) != S.end() && ret == nullptr) ret = now; 
                S.insert(now);
                return true;
            }
            
            if (self(self, now->left, target)) {
                if (S.find(now) != S.end() && ret == nullptr) ret = now; 
                S.insert(now);
                return true;
            }
            if (self(self, now->right, target)) {
                if (S.find(now) != S.end() && ret == nullptr) ret = now; 
                S.insert(now);
                return true;
            }
            return false;
        };
        
        go(go, root, p);
        go(go, root, q);
        
        return ret;
    }
};