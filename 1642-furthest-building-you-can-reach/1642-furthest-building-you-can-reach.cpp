class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int s = 0, e = heights.size() - 1;
        while (s <= e) {
            int m = s + e >> 1;
            vector<int> dif;
            for (int i = 1; i <= m; ++i) dif.push_back(max(0, heights[i] - heights[i - 1]));
            
            sort(dif.begin(), dif.end());
            
            if (ladders >= m || accumulate(dif.begin(), dif.end() - ladders, 0ll) <= bricks) s = m + 1;
            else e = m - 1;
        }
        
        return e;
    }
};