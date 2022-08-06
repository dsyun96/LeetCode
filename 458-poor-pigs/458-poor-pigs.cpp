class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int n = minutesToTest / minutesToDie + 1;
        int ret = 0, tmp = 1;
        
        while (buckets > tmp) {
            tmp *= n;
            ++ret;
        }
        
        return ret;
    }
};