static int z = [] {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for (auto& word : words) reverse(begin(word), end(word));
        sort(begin(words), end(words));
        
        int ret = words.back().size() + 1;
        for (int i = 1; i < words.size(); ++i) {
            int len = min(words[i - 1].size(), words[i].size());
            if (words[i - 1].substr(0, len) != words[i].substr(0, len)) ret += words[i - 1].size() + 1;
        }
        
        return ret;
    }
};