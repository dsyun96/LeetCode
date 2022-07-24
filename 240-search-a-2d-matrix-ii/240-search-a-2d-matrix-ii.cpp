class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int e = n;
        
        for (int i = 0; i < m; ++i) {
            auto p = lower_bound(matrix[i].begin(), matrix[i].begin() + e, target) - matrix[i].begin();
            if (p != e && matrix[i][p] == target) return true;
            e = p;
        }
        
        return false;
    }
};