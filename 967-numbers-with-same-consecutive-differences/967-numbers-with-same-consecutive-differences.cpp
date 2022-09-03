class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        set<int> ret;
        auto go = [&](auto& self, int depth, long long val) -> void {
            if (depth == n) {
                ret.insert(val);
                return;
            }
            
            if (val % 10 >= k) self(self, depth + 1, val * 10 + val % 10 - k);
            if (val % 10 + k < 10) self(self, depth + 1, val * 10 + val % 10 + k);
        };
        
        for (int i = 1; i <= 9; ++i) go(go, 1, i);
        
        return vector<int>(ret.begin(), ret.end());
    }
};