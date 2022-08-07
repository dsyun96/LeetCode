class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        vector cnt(61, vector<int>{ 0x3f3f3f3f, 0, 0x3f3f3f3f, 0 });
        for (int i = 0; i < targetGrid.size(); ++i) {
            for (int j = 0; j < targetGrid[i].size(); ++j) {
                int cell = targetGrid[i][j];
                if (cell == 0) continue;
                cnt[cell][0] = min(cnt[cell][0], i);
                cnt[cell][1] = max(cnt[cell][1], i);
                cnt[cell][2] = min(cnt[cell][2], j);
                cnt[cell][3] = max(cnt[cell][3], j);
            }
        }
        
        while (true) {
            bool f = 1;
            for (int i = 1; i <= 60; ++i) {
                int x1 = cnt[i][0], x2 = cnt[i][1];
                int y1 = cnt[i][2], y2 = cnt[i][3];
                if (x1 == 0x3f3f3f3f) continue;
                
                bool g = 1;
                for (int j = x1; j <= x2; ++j) {
                    for (int k = y1; k <= y2; ++k) {
                        if (targetGrid[j][k] == i || targetGrid[j][k] == 0) continue;
                        g = 0;
                        goto EXIT;
                    }
                }
                
                EXIT:;
                if (!g) continue;
                
                f = 0;
                for (int j = x1; j <= x2; ++j) {
                    for (int k = y1; k <= y2; ++k) {
                        targetGrid[j][k] = 0;
                    }
                }
                cnt[i][0] = 0x3f3f3f3f;
                
                break;
            }
            
            if (f) break;
        }
        
        int tmp = 0;
        for (auto& i : targetGrid) for (auto& j : i) tmp += j != 0;
        
        return tmp == 0;
    }
};