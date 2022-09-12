class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> D;
        for (int i = 0; i < list1.size(); ++i) D[list1[i]] = i;
        
        vector<string> ret;
        int val = 0x3f3f3f3f;
        for (int i = 0; i < list2.size(); ++i) if (D.find(list2[i]) != D.end()) {
            if (D[list2[i]] + i <= val) {
                if (D[list2[i]] + i < val) ret.clear();
                val = D[list2[i]] + i;
                ret.push_back(list2[i]);
            }
        }
        
        return ret;
    }
};