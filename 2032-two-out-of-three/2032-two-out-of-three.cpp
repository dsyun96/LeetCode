class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        int cnt[101]{};
        for (auto it : set<int>(nums1.begin(), nums1.end())) cnt[it]++;
        for (auto it : set<int>(nums2.begin(), nums2.end())) cnt[it]++;
        for (auto it : set<int>(nums3.begin(), nums3.end())) cnt[it]++;
        
        vector<int> ret;
        for (int i = 1; i <= 100; ++i) if (cnt[i] >= 2) ret.push_back(i);
        
        return ret;
    }
};