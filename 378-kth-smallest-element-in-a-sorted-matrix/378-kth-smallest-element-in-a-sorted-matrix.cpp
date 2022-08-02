class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> vec;
        for (auto& i : matrix) for (auto j : i) vec.push_back(j);
        
        nth_element(vec.begin(), vec.begin() + k - 1, vec.end());
        
        return vec[k - 1];
    }
};