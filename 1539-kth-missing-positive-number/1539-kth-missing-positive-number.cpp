class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i, p;
        for (i = 1, p = 0; k; ++i) {
            if (p < arr.size() && arr[p] == i) {
                ++p;
                continue;
            }
            --k;
        }
        return --i;
    }
};