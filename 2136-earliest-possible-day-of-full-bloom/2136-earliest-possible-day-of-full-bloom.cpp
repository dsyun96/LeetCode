class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < plantTime.size(); ++i) vec.emplace_back(plantTime[i], growTime[i]);
        
        sort(vec.begin(), vec.end(), [](auto& a, auto& b) { return a.second > b.second; });
        
        int ret = 0;
        for (int hold = 0, i = 0; i < plantTime.size(); ++i) {
            auto [a, b] = vec[i];
            ret = max(ret, hold + a + b);
            hold += a;
        }
        
        return ret;
    }
};