class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto go = [&](auto& self, int x, int y) -> void {
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0') return;
            grid[x][y] = '0';
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + "0121"[i] - 49;
                int ny = y + "1210"[i] - 49;
                self(self, nx, ny);
            }
        };
        
        int ans = 0;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) if (grid[i][j] == '1') {
            ++ans;
            go(go, i, j);
        }
        
        return ans;
    }
};