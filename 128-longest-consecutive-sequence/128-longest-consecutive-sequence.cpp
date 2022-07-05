class Solution {
public:
    unordered_map<int, bool> pa;
    
    int longestConsecutive(vector<int>& nums) {
        for (int i : nums) pa[i] = 1;
        
        int ret = 0;
        for (auto &it : pa) if (it.second) {
            int sub = 1;
            for (int i = it.first + 1; pa.find(i) != pa.end(); ++i) {
                ++sub;
                pa[i] = 0;
            }
            for (int i = it.first - 1; pa.find(i) != pa.end(); --i) {
                ++sub;
                pa[i] = 0;
            }
            ret = max(ret, sub);
        }
        
        return ret;
    }
};