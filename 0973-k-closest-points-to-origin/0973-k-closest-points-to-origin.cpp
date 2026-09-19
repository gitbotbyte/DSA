class Solution {
public:
    int fun(vector<int>& i) {
        int x = i[0];
        int y = i[1];
        int dist = (x * x) + (y * y);
        return dist;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < a.size(); i++) {
            int dist = fun(a[i]);
            int idx = i;
            pair<int, int> curr = {dist, idx};
            pq.push(curr);
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            int index = pq.top().second;
            res.push_back(a[index]);
            pq.pop();
        }
        return res;
    }
};