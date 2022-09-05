/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        
        vector<vector<int>> ret;
        
        queue<Node*> Q;
        Q.emplace(root);
        
        while (!Q.empty()) {
            int szQ = Q.size();
            vector<int> sub;
            while (szQ--) {
                auto now = Q.front(); Q.pop();
                if (now == nullptr) continue;
                
                sub.emplace_back(now->val);
                for (auto nxt : now->children) Q.emplace(nxt);
            }
            ret.emplace_back(sub);
        }
        
        return ret;
    }
};