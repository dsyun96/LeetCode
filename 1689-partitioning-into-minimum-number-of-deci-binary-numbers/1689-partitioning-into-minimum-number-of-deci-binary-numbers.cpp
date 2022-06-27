class Solution {
public:
    int minPartitions(string n) {
        return max(1, *max_element(n.begin(), n.end()) - 48);
    }
};