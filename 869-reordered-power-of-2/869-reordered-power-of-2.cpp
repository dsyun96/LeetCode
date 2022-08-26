class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        do {
            if (s[0] == '0') continue;
            long long val = stoll(s);
            if (val > 0 && (val & val - 1) == 0) return true;
        } while (next_permutation(s.begin(), s.end()));
        
        return false;
    }
};