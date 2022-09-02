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
    vector<double> averageOfLevels(TreeNode* root) {
        int cnt[10001]{};
        long long sum[10001]{};
        
        auto go = [&](auto& self, TreeNode* now, int depth) -> void {
            if (now == nullptr) return;
            cnt[depth]++;
            sum[depth] += now->val;
            
            self(self, now->left, depth + 1);
            self(self, now->right, depth + 1);
        };
        
        go(go, root, 0);
        
        vector<double> ret;
        for (int i = 0; cnt[i]; ++i) ret.push_back(1.0 * sum[i] / cnt[i]);
        
        return ret;
    }
};