class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int mx1 = 0, mx2 = 0;
        for (int i = 1; i < horizontalCuts.size(); ++i) mx1 = max(mx1, horizontalCuts[i] - horizontalCuts[i - 1]);
        for (int i = 1; i < verticalCuts.size(); ++i) mx2 = max(mx2, verticalCuts[i] - verticalCuts[i - 1]);
        
        return 1ll * mx1 * mx2 % 1000000007;
    }
};