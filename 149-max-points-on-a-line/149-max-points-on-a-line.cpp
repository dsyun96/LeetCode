class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size(); ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            
            map<pair<int, int>, int> cnt;
            int mx = 0;
            for (int j = 0; j < points.size(); ++j) if (i != j) {
                int x2 = points[j][0], y2 = points[j][1];
                
                int dx = x1 - x2;
                int dy = y1 - y2;
                if (dx < 0 && dy < 0 || dx > 0 && dy < 0) dx = -dx, dy = -dy;
                
                int g = gcd(dx, dy);
                dx /= g, dy /= g;
                
                mx = max(mx, ++cnt[make_pair(dx, dy)]);
            }
            
            ans = max(ans, mx);
        }
        
        return ans + 1;
    }
};