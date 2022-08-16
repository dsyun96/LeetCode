class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[26]{};
        for (char ch : s) cnt[ch - 97]++;
        
        for (int i = 0; i < s.size(); ++i) if (cnt[s[i] - 97] == 1) return i;
        return -1;
    }
};