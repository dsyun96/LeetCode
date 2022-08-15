class Solution {
public:
    int romanToInt(string s) {
        int f[128];
        f['I'] = 1, f['V'] = 5, f['X'] = 10, f['L'] = 50, f['C'] = 100, f['D'] = 500, f['M'] = 1000;
        
        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i == s.size() - 1) ret += f[s[i]];
            else {
                if (s[i] == 'I') {
                    if (s[i + 1] == 'V') ret += 4, ++i;
                    else if (s[i + 1] == 'X') ret += 9, ++i;
                    else ret += 1;
                }
                else if (s[i] == 'X') {
                    if (s[i + 1] == 'L') ret += 40, ++i;
                    else if (s[i + 1] == 'C') ret += 90, ++i;
                    else ret += 10;
                }
                else if (s[i] == 'C') {
                    if (s[i + 1] == 'D') ret += 400, ++i;
                    else if (s[i + 1] == 'M') ret += 900, ++i;
                    else ret += 100;
                }
                else ret += f[s[i]];
            }
        }
        
        return ret;
    }
};