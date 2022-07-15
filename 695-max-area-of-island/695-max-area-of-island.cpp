class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        
        const int dx[] = { -1, 0, 1, 0 };
        const int dy[] = { 0, 1, 0, -1 };
        
        auto dfs = [&](auto& self, int x, int y) -> int {
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) return 0;
            grid[x][y] = 0;
            
            int ret = 1;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                ret += self(self, nx, ny);
            }
            
            return ret;
        };
        
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) ans = max(ans, dfs(dfs, i, j));
        
        return ans;
    }
};