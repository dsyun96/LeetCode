class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> D;
        while (!nums.empty()) {
            int val = nums.front();
            if (D[val - 1] > 0) {
                --D[val - 1], ++D[val];
                nums.erase(nums.begin());
                continue;
            }
            else if (
                find(nums.begin(), nums.end(), val) == nums.end() || 
                find(nums.begin(), nums.end(), val + 1) == nums.end() ||
                find(nums.begin(), nums.end(), val + 2) == nums.end()
            ) {
                return false;
            }
            else {
                nums.erase(find(nums.begin(), nums.end(), val));
                nums.erase(find(nums.begin(), nums.end(), val + 1));
                nums.erase(find(nums.begin(), nums.end(), val + 2));
                D[val + 2]++;
            }
        }
        return true;
    }
};