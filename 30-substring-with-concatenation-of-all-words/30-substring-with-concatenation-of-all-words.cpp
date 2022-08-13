class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> D, ans;
        for (auto& word : words) D[word] = 0, ans[word]++;
        
        int offset = 0;
        auto go = [&](string& s, int idx) -> bool {
            int len = words[0].size();
            for (int cnt = 0, hold = 0, i = idx; i < s.size(); i += len) {
                string tmp = s.substr(i, len);
                if (D.find(tmp) == D.end()) return false;
                
                if (D[tmp] < offset) D[tmp] = offset;
                if (++D[tmp] == ans[tmp] + offset) ++hold;
                if (hold == D.size()) return true;
                if (++cnt == words.size()) return false;
            }
            return false;
        };
        
        vector<int> ret;
        for (int i = 0; i + words.size() * words[0].size() <= s.size(); ++i) {
            if (go(s, i)) ret.push_back(i);
            offset += 10000;
        }
        
        return ret;
    }
};