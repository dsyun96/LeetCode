class WordFilter {
public:
    unordered_map<string, int> D;
    
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            auto& word = words[i];
            for (int j = 0; j < word.size(); ++j) {
                string tmp = word.substr(j) + "#" + word;
                while (tmp.back() != '#') {
                    D[tmp] = max(D[tmp], i);
                    tmp.pop_back();
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string tmp = suffix + '#' + prefix;
        if (D.find(tmp) == D.end()) return -1;
        return D[tmp];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */