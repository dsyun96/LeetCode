class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for (auto& word : words) reverse(begin(word), end(word));
        sort(begin(words), end(words));
        
        int ret = 0;
        for (int i = 0; i < words.size(); ++i) {
            if (i + 1 == words.size()) ret += words[i].size() + 1;
            else {
                int len = min(words[i].size(), words[i + 1].size());
                if (words[i].substr(0, len) != words[i + 1].substr(0, len)) ret += words[i].size() + 1;
            }
        }
        
        return ret;
    }
};