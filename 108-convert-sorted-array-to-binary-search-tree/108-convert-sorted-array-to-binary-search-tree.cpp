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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
        
        auto go = [&](auto& self, TreeNode*& root, int s, int e) -> void {
            if (s > e) return;
            
            root = new TreeNode;
            
            int m = s + e >> 1;
            root->val = nums[m];
            
            self(self, root->left, s, m - 1);
            self(self, root->right, m + 1, e);
        };
        
        go(go, root, 0, nums.size() - 1);
        
        return root;
    }
};