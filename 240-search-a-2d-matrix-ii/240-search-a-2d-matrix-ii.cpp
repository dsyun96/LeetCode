class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        
        while (x < m) {
            while (y > 0 && matrix[x][y] > target) --y;
            if (matrix[x][y] == target) return true;
            ++x;
        }
        
        return false;
    }
};