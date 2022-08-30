class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> tmp;
        int n = matrix.size();
        
        for (int i = 0; i < n / 2; ++i) {
            int len = n - 2 * i;
            for (int j = 0; j < len - 1; ++j) {
                swap(matrix[i][i + j], matrix[i + j][i + len - 1]);
                swap(matrix[i][i + j], matrix[i + len - 1][i + len - 1 - j]);
                swap(matrix[i][i + j], matrix[i + len - 1 - j][i]);
            }
        }
    }
};