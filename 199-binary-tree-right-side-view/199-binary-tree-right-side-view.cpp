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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        vector<int> ret;
        while (!Q.empty()) {
            ret.push_back(Q.back()->val);
            int szQ = Q.size();
            while (szQ--) {
                auto now = Q.front(); Q.pop();
                if (now->left) Q.push(now->left);
                if (now->right) Q.push(now->right);
            }
        }
        
        return ret;
    }
};