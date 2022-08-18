class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int cnt[100001]{};
        for (int it : arr) cnt[it]++;
        
        vector<int> vec;
        for (int i : cnt) if (i) vec.push_back(i);
        
        sort(vec.begin(), vec.end(), greater());
        
        int ans = 0, t = arr.size();
        for (int i : vec) {
            t -= i;
            ++ans;
            if (t * 2 <= arr.size()) break;
        }
        
        return ans;
    }
};