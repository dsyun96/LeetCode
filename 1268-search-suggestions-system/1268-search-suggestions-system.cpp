class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        
        unordered_map<string, vector<int>> D;
        for (int i = 0; i < products.size(); ++i) {
            string str;
            for (char ch : products[i]) {
                str += ch;
                D[str].push_back(i);
            }
        }
        
        vector<vector<string>> ret;
        string now;
        for (char ch : searchWord) {
            now += ch;
            
            vector<string> sub;
            for (auto it : D[now]) {
                sub.push_back(products[it]);
                if (sub.size() == 3) break;
            }
            ret.push_back(sub);
        }
        
        return ret;
    }
};