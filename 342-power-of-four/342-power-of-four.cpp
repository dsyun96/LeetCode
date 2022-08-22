class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 1) return false;
        return n == 1 || n % 4 == 0 && abs(log(n) / log(4) - int(log(n) / log(4) + 1e-9)) < 1e-9;
    }
};