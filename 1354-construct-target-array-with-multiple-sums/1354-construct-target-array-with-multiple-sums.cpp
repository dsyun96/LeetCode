class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        if (n == 1) return target[0] == 1;
        
        long long sum = accumulate(target.begin(), target.end(), 0ll);
        
        priority_queue<int> PQ;
        for (int it : target) PQ.emplace(it);
        
        while (sum - PQ.top() != n - 1) {
            int now = PQ.top(); PQ.pop();
            int dif = now / (sum - now) * (sum - now);
            if (dif == 0) return false;
            
            now -= dif;
            if (now < 1) return false;
            
            sum -= dif;
            PQ.emplace(now);
        }
        
        return n == 2 || PQ.top() % (n - 1) == 1;
    }
};