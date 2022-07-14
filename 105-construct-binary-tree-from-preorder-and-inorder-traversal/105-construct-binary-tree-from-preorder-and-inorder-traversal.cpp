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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx_[6001], *idx = idx_ + 3000;
        for (int i = 0; i < n; ++i) idx[inorder[i]] = i;
        
        TreeNode* root = new TreeNode();
        auto go = [&](auto& self, TreeNode* now, int L1, int R1, int L2, int R2) -> void {
            if (L1 > R1) return;
            
            now->val = preorder[L1];
            
            int cnt = idx[now->val] - L2;
            if (cnt > 0) {
                TreeNode* left = new TreeNode();
                now->left = left;
                self(self, left, L1 + 1, L1 + cnt, L2, idx[now->val] - 1);
            }
            if (cnt < R2 - L2) {
                TreeNode* right = new TreeNode();
                now->right = right;
                self(self, right, L1 + cnt + 1, R1, idx[now->val] + 1, R2);
            }
        };
        
        go(go, root, 0, n - 1, 0, n - 1);
        
        return root;
    }
};