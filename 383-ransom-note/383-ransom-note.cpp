class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26]{};
        for (char ch : magazine) cnt[ch - 97]++;
        for (char ch : ransomNote) if (--cnt[ch - 97] < 0) return false;
        return true;
    }
};