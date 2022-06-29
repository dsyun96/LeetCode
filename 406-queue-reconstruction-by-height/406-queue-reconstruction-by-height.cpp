class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end());
        
        vector ret(people.size(), vector<int>(2, -1));
        for (int i = 0; i < people.size(); ++i) {
            int cnt = people[i][1];
            for (int j = 0; j < ret.size(); ++j) {
                if (ret[j][0] == -1 || ret[j][0] == people[i][0]) --cnt;
                if (cnt == -1) {
                    ret[j] = people[i];
                    break;
                }
            }
        }
        
        return ret;
    }
};