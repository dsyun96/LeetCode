class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& a, auto& b) { return a[1] < b[1]; });
        
        priority_queue<int> PQ;
        int sum = 0;
        for (auto& course : courses) {
            if (sum + course[0] <= course[1]) {
                sum += course[0];
                PQ.emplace(course[0]);
            }
            else if (!PQ.empty() && PQ.top() > course[0]) {
                sum -= PQ.top(); PQ.pop();
                sum += course[0];
                PQ.emplace(course[0]);
            }
        }
        
        return PQ.size();
    }
};