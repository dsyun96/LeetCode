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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        vector<vector<int>> ret;
        while (!Q.empty()) {
            int szQ = Q.size();
            vector<int> sub;
            while (szQ--) {
                auto now = Q.front(); Q.pop();
                sub.push_back(now->val);
                
                if (now->left) Q.push(now->left);
                if (now->right) Q.push(now->right);
            }
            ret.push_back(sub);
        }
        
        return ret;
    }
};