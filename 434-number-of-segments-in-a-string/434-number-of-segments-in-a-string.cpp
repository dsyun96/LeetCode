class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        stringstream ss(s);
        while (ss >> s) ++ans;
        
        return ans;
    }
};