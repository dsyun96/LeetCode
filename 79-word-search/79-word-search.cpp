class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        bool vis[6][6]{};
        auto go = [&](auto& self, int x, int y, int idx) -> bool {
            if (idx + 1 == word.size()) return true;
            
            vis[x][y] = 1;
            for (int i = 0; i < 4; ++i) {
                int nx = x + "0121"[i] - 49;
                int ny = y + "1210"[i] - 49;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (board[nx][ny] != word[idx + 1] || vis[nx][ny]) continue;
                if (self(self, nx, ny, idx + 1)) return true;
            }
            
            vis[x][y] = 0;
            
            return false;
        };
        
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) if (board[i][j] == word[0] && go(go, i, j, 0)) return true;
        return false;
    }
};