class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dp[50][50][51]; memset(dp, -1, sizeof dp);
        
        const int dx[] = { -1, 0, 1, 0 };
        const int dy[] = { 0, 1, 0, -1 };
        
        auto go = [&](auto& self, int x, int y, int rest) -> int {
            if (x < 0 || x >= m || y < 0 || y >= n) return 1;
            if (rest == 0) return 0;
            
            int& ret = dp[x][y][rest];
            if (~ret) return ret;
            
            ret = 0;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                ret = (ret + self(self, nx, ny, rest - 1)) % 1000000007;
            }
            
            return ret;
        };
        
        return go(go, startRow, startColumn, maxMove);
    }
};