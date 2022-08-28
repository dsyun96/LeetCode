class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for (int i = m - 1; i >= 1 - n; --i) {
            vector<int> tmp;
            for (int j = max(i, 0); j < m && j - i < n; ++j) tmp.push_back(mat[j - i][j]);
            
            sort(tmp.begin(), tmp.end());
            for (int j = max(i, 0), k = 0; j < m && j - i < n; ++j) mat[j - i][j] = tmp[k++];
        }
        
        return mat;
    }
};