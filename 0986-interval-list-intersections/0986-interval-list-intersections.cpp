class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int n = firstList.size();
        int m = secondList.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];
            int s = max(start1, start2);
            int e = min(end1, end2);
            if (s <= e) {
                res.push_back({s, e});
            }
            if (end1 <= end2) {
                i++;
            }
            else j++;
        }
        return res;
    }
};