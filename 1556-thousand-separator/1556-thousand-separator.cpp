class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0) return "0";
        
        string ret;
        for (int i = 0; n; n /= 10, ++i) {
            if (i && i % 3 == 0) ret += '.';
            ret += n % 10 + 48;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};