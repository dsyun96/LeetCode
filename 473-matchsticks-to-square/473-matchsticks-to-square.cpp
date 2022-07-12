class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4) return false;
        sum /= 2;
        
        auto go = [&](int bit, int sum) -> bool {
            for (int i = bit - 1 & bit; i; i = i - 1 & bit) {
                int s = 0;
                for (int j = 0; j < n; ++j) if (i & 1 << j) s += matchsticks[j];
                if (s == sum) return true;
            }
            return false;
        };
        
        for (int i = (1 << n) - 1; i; i = i - 1 & (1 << n) - 1) {
            int s = 0;
            for (int j = 0; j < n; ++j) if (i & 1 << j) s += matchsticks[j];
            if (s != sum) continue;
            
            int A = i, B = (1 << n) - 1 - i;
            if (go(A, sum / 2) && go(B, sum / 2)) return true;
        }
        
        return false;
    }
};