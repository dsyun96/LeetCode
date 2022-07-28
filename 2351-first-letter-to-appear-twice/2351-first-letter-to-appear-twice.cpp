class Solution {
public:
    char repeatedCharacter(string s) {
        int bit = 0;
        for (char ch : s) {
            if (bit & 1 << ch - 97) return ch;
            bit |= 1 << ch - 97;
        }
        return '?';
    }
};