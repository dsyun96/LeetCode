class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int SZ = 1 << 15;
        int tree[SZ << 1]{};
        
        auto update = [&](int idx) -> void {
            for (tree[idx += SZ]++; idx >>= 1; )
                tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
        };
        auto query = [&](int L, int R) -> int {
            int ret = 0;
            for (L += SZ, R += SZ; L <= R; L >>= 1, R >>= 1) {
                if (L & 1) ret += tree[L++];
                if (~R & 1) ret += tree[R--];
            }
            return ret;
        };
        
        vector<int> ret;
        for (int i = nums.size(); i--; ) {
            ret.push_back(query(0, 9999 + nums[i]));
            update(10000 + nums[i]);
        }
        
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};