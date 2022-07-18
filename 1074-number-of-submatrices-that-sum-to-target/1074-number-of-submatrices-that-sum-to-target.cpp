class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int psum[101][101]{};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                psum[i + 1][j + 1] = matrix[i][j] + psum[i + 1][j];
            }
        }
        
        map<int, int> dic[100][100];
        long long ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < m; ++j) {
                dic[i][j][0] = 1;
                int sum = 0;
                for (int k = 0; k < n; ++k) {
                    sum += psum[k + 1][j + 1] - psum[k + 1][i];
                    if (dic[i][j].find(sum - target) != dic[i][j].end()) ans += dic[i][j][sum - target];
                    dic[i][j][sum]++;
                }
            }
        }
        
        return ans;
    }
};