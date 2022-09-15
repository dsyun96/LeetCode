class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() & 1) return {};
        
        int cnt[100001]{};
        for (int i : changed) cnt[i]++;
        
        vector<int> ret;
        for (int i = 0; i <= 100000; ++i) if (cnt[i]) {
            while (cnt[i] > 0 && i * 2 <= 100000 && cnt[i * 2] > 0) {
                --cnt[i];
                --cnt[i * 2];
                ret.push_back(i);
            }
            if (cnt[i]) return {};
        }
        
        return ret;
    }
};