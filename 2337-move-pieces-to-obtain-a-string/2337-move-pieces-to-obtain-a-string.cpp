class Solution {
public:
    bool canChange(string start, string target) {
        if (count(start.begin(), start.end(), 'L') != count(target.begin(), target.end(), 'L')) return false;
        if (count(start.begin(), start.end(), 'R') != count(target.begin(), target.end(), 'R')) return false;
        
        vector<int> L, R;
        for (int i = 0; i < start.size(); ++i) {
            if (start[i] == 'L') L.push_back(i);
            else if (start[i] == 'R') R.push_back(i);
        }
        
        for (int l = 0, r = 0, i = 0; i < target.size(); ++i) {
            if (target[i] == '_') continue;
            
            if (target[i] == 'L') {
                if (L[l] < i || r < R.size() && R[r] < L[l]) return false;
                ++l;
            }
            if (target[i] == 'R') {
                if (R[r] > i || l < L.size() && L[l] < R[r]) return false;
                ++r;
            }
        }
        
        return true;
    }
};