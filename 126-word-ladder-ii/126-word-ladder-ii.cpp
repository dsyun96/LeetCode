class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return {};
        
        unordered_map<string, int> num;
        wordList.insert(wordList.begin(), beginWord);
        
        /* numbering */ {
            int t = 0;
            for (auto& word : wordList) num[word] = t++;
        }
        
        auto difCount = [](const string& a, const string& b) -> int {
            int ret = 0;
            for (int i = 0; i < a.size(); ++i) ret += a[i] != b[i];
            return ret;
        };
        
        vector<int> adj[501];
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                if (difCount(wordList[i], wordList[j]) != 1) continue;
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        
        queue<int> Q;
        Q.push(0);
        
        int dist[501]; memset(dist, 0x3f, sizeof dist);
        dist[0] = 0;
        
        int from[501]; memset(from, -1, sizeof from);
        for (int d = 1; !Q.empty(); ++d) {
            int szQ = Q.size();
            while (szQ--) {
                int now = Q.front(); Q.pop();
                for (int nxt : adj[now]) if (dist[nxt] == 0x3f3f3f3f) {
                    dist[nxt] = d;
                    Q.push(nxt);
                    from[nxt] = now;
                }
            }
        }
        
        vector<vector<string>> ret;
        vector<string> hold;
        auto go = [&](auto& self, int now) -> void {
            if (now == 0) {
                reverse(hold.begin(), hold.end());
                ret.push_back(hold);
                reverse(hold.begin(), hold.end());
                return;
            }
            
            for (int nxt : adj[now]) if (dist[now] - 1 == dist[nxt] ) {
                hold.push_back(wordList[nxt]);
                self(self, nxt);
                hold.pop_back();
            }
        };
        
        hold.push_back(endWord);
        go(go, num[endWord]);
        
        return ret;
    }
};