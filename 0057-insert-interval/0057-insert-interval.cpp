class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> res;
        vector<vector<int>> res2;
        int n = intervals.size();
        if (intervals.empty()) {
            return {newInterval};
        }
        bool insert = false;
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            if (insert == false && start >= newInterval[0]) {
                res.push_back(newInterval);
                insert = true;
            }
            res.push_back(intervals[i]);
        }
        if (insert == false) {
            res.push_back(newInterval);
        }
        int n2 = res.size();
        int start1 = res[0][0];
        int end1 = res[0][1];
        for (int i = 1; i < n2; i++) {
            int start2 = res[i][0];
            int end2 = res[i][1];
            if (end1 >= start2) {
                start1 = start1;
                end1 = max(end1, end2);
                continue;
            } else {
                res2.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            }
        }
        res2.push_back({start1, end1});
        return res2;
    }
};