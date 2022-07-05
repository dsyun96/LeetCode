class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> S;
        for (int i : nums) S.insert(i);
        
        int ans = 0;
        for (int i : nums) if (S.find(i) != S.end()) {
            int len = 1;
            S.erase(i);
            
            for (int j = i - 1; S.find(j) != S.end(); --j) {
                ++len;
                S.erase(j);
            }
            for (int j = i + 1; S.find(j) != S.end(); ++j) {
                ++len;
                S.erase(j);
            }
            
            ans = max(ans, len);
        }
        
        return ans;
    }
};