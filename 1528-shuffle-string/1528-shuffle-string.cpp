class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ret(s.size(), ' ');
        for (int i = 0; i < s.size(); ++i) ret[indices[i]] = s[i];
        return ret;
    }
};