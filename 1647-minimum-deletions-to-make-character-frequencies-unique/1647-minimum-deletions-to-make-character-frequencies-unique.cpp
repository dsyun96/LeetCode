class Solution {
public:
    int minDeletions(string s) {
        int cnt[26]{};
        for (char ch : s) cnt[ch - 97]++;
        
        sort(cnt, cnt + 26, greater<>());
        
        int ans = 0;
        for (int i = 1; i < 26; ++i) if (cnt[i] && cnt[i - 1] <= cnt[i]) {
            int tmp = cnt[i];
            cnt[i] = max(0, cnt[i - 1] - 1);
            ans += max(0, tmp - cnt[i]);
        }
        
        return ans;
    }
};