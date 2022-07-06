class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1, c = 1;
        while (n--) a = b, b = c, c = a + b;
        return a;
    }
};