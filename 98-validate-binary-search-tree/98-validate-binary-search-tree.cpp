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
    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        auto go = [&](auto& self, TreeNode* root) -> void {
            if (root == nullptr) return;
            self(self, root->left);
            vec.push_back(root->val);
            self(self, root->right);
        };
        
        go(go, root);
        
        for (int i = 1; i < vec.size(); ++i) if (vec[i] <= vec[i - 1]) return false;
        return true;
    }
};