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
    unordered_map<TreeNode*, int> D[2];
    
    int minCameraCover(TreeNode* root, bool check = false) {
        if (D[check].find(root) != D[check].end()) return D[check][root];
        if (root == nullptr) return 0;
        
        int ret = 0x3f3f3f3f;
        if (check) ret = min(ret, minCameraCover(root->left, 0) + minCameraCover(root->right, 0));
        
        if (root->left && root->right) {
            ret = min(ret, minCameraCover(root->left, 1) + minCameraCover(root->right, 1) + 1);
            ret = min(ret, minCameraCover(root->left->left, 1) + minCameraCover(root->left->right, 1) + minCameraCover(root->right, 0) + 1);
            ret = min(ret, minCameraCover(root->right->left, 1) + minCameraCover(root->right->right, 1) + minCameraCover(root->left, 0) + 1);
        }
        else if (root->left) {
            ret = min(ret, minCameraCover(root->left, 1) + 1);
            ret = min(ret, minCameraCover(root->left->left, 1) + minCameraCover(root->left->right, 1) + 1);
        }
        else if (root->right) {
            ret = min(ret, minCameraCover(root->right, 1) + 1);
            ret = min(ret, minCameraCover(root->right->left, 1) + minCameraCover(root->right->right, 1) + 1);
        }
        else {
            ret = !check;
        }
        
        return D[check][root] = ret;
    }
};