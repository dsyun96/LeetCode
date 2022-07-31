class NumArray {
public:
    static const int SZ = 1 << 15;
    int tree[SZ << 1];
    
    NumArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) tree[SZ + i] = nums[i];
        for (int i = SZ; --i; ) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    
    void update(int index, int val) {
        for (tree[index += SZ] = val; index >>= 1; )
            tree[index] = tree[index << 1] + tree[index << 1 | 1];
    }
    
    int sumRange(int left, int right) {
        int ret = 0;
        for (left += SZ, right += SZ; left <= right; left >>= 1, right >>= 1) {
            if (left & 1) ret += tree[left++];
            if (~right & 1) ret += tree[right--];
        }
        return ret;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */