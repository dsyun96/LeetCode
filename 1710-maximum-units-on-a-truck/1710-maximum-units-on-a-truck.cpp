class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto& a, auto& b) { return a[1] > b[1]; });
        int ans = 0;
        for (int i = 0; i < boxTypes.size() && truckSize; ++i) {
            int cnt = min(boxTypes[i][0], truckSize);
            truckSize -= cnt;
            ans += boxTypes[i][1] * cnt;
        }
        
        return ans;
    }
};