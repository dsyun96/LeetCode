class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        for (auto& word : words) {
            bool f = 1;
            for (int i = 0; i < pattern.size(); ++i) {
                for (int j = i + 1; j < pattern.size(); ++j) {
                    if (pattern[i] == pattern[j] && word[i] != word[j] ||
                       pattern[i] != pattern[j] && word[i] == word[j]) {
                        f = 0;
                        break;
                    }
                }
            }
            if (f) ret.push_back(word);
        }
        return ret;
    }
};