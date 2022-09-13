class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int cnt[1001]{};
        for (auto it : arr1) cnt[it]++;
        
        vector<int> ret;
        bool vis[1001]{};
        for (auto it : arr2) {
            vis[it] = 1;
            for (int tmp = cnt[it]; tmp--; ) ret.push_back(it);
        }
        
        for (int i = 0; i <= 1000; ++i) if (!vis[i])
            for (int tmp = cnt[i]; tmp--; ) ret.push_back(i);
        
        return ret;
    }
};