class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> idx[26];
        for (int i = 0; i < s.size(); ++i) idx[s[i] - 97].push_back(i);
        
        int ret = 0;
        for (string& word : words) {
            int p = -1, f = 1;
            for (char ch : word) {
                p = upper_bound(idx[ch - 97].begin(), idx[ch - 97].end(), p) - idx[ch - 97].begin();
                if (p == idx[ch - 97].size()) {
                    f = 0;
                    break;
                }
                p = idx[ch - 97][p];
            }
            ret += f;
        }
        
        return ret;
    }
};