class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ret;
        
        int cnt2[26]{};
        for (int i = 0; i < words2.size(); ++i) {
            int sub[26]{};
            for (auto ch : words2[i]) sub[ch - 97]++;
            for (int i = 0; i < 26; ++i) cnt2[i] = max(cnt2[i], sub[i]);
        }
        
        for (auto& word : words1) {
            int cnt[26]{};
            for (auto ch : word) cnt[ch - 97]++;
            
            bool f = 1;
            for (int i = 0; i < 26; ++i) if (cnt[i] < cnt2[i]) f = 0;
            if (f) ret.push_back(word);
        }
        
        return ret;
    }
};