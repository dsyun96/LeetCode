class NumArray {
public:
    int fw[30001];
    
    NumArray(vector<int>& nums) {
        memset(fw, 0, sizeof fw);
        for (int i = 0; i < nums.size(); ++i) update(i, nums[i]);
    }
    
    void update(int index, int val) {
        int now = query(index) - query(index - 1);
        ++index;
        
        val -= now;
        while (index <= 30000) {
            fw[index] += val;
            index += index & -index;
        }
    }
    
    int query(int index) {
        ++index;
        
        int ret = 0;
        while (index) {
            ret += fw[index];
            index -= index & -index;
        }
        return ret;
    }
    
    int sumRange(int left, int right) {
        return query(right) - query(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */