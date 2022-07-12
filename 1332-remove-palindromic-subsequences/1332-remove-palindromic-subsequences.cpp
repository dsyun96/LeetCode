class Solution {
public:
    int removePalindromeSub(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return (s != t) + 1;
    }
};