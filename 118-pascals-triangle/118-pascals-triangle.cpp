class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for (int i = 1; i <= numRows; ++i) {
            vector<int> sub(i);
            for (int j = 1; j <= i; ++j) {
                if (j == 1 || j == i) sub[j - 1] = 1;
                else sub[j - 1] = ret.back()[j - 1] + ret.back()[j - 2];
            }
            ret.push_back(sub);
        }
        return ret;
    }
};