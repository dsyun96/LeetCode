class Solution {
public:
    bool f(int n) {
        if (n == 0) return true;
        if (n % 10 == 0) return false;
        return f(n / 10);
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i <= n - i; ++i) if (f(i) && f(n - i)) return { i, n - i };
        return {};
    }
};