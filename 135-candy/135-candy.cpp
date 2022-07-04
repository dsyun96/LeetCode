class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        vector<pair<int, int>> pos;
        for (int i = 0; i < n; ++i) pos.emplace_back(ratings[i], i);
        
        sort(pos.begin(), pos.end());
        
        vector<pair<int, int>> vec(n, pair<int, int>(-1, -1));
        for (auto [a, b] : pos) {
            int val = 1;
            if (b > 0 && vec[b - 1].first < a) val = max(val, vec[b - 1].second + 1);
            if (b + 1 < n && vec[b + 1].first < a) val = max(val, vec[b + 1].second + 1);
            vec[b] = { a, val };
        }
        
        int ans = 0;
        for (auto [a, b] : vec) ans += b;
        
        return ans;
    }
};