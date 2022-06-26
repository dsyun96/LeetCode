class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int rest = n - k;
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int hold = accumulate(cardPoints.begin(), cardPoints.begin() + rest, 0);
        int ans = hold;
        
        for (int i = rest; i < n; ++i) {
            hold += cardPoints[i] - cardPoints[i - rest];
            ans = min(ans, hold);
        }
        
        return sum - ans;
    }
};