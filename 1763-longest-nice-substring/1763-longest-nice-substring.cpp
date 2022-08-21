class Solution {
public:
    string longestNiceSubstring(string s) {
        string ret;
        
        auto check = [](const string& str) -> bool {
            bool vis[128]{};
            for (char ch : str) vis[ch] = 1;
            for (char ch : str) if (vis[ch] ^ vis[ch ^ 32]) return false;
            return true;
        };
        
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 1; i + j <= s.size(); ++j) {
                string tmp = s.substr(i, j);
                if (!check(tmp)) continue;
                if (ret.size() < tmp.size()) ret = tmp;
            }
        }
        
        return ret;
    }
};