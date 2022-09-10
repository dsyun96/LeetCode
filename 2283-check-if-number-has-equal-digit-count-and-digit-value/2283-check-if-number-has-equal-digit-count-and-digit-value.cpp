class Solution {
public:
    bool digitCount(string num) {
        for (int i = 0; i < num.size(); ++i) {
            if (count(num.begin(), num.end(), i + 48) != num[i] - 48) return false;
        }
        return true;
    }
};