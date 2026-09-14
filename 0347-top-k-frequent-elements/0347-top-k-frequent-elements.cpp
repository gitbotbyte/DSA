struct cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second > b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        unordered_map<int, int> mp;
        for (int i = 0; i < a.size(); i++)
            mp[a[i]]++;
        for (auto i : mp) {
            int element = i.first;
            int freq = i.second;
            pair<int, int> curr = {freq, element};
            if (pq.size() < k) {
                pq.push(curr);
                continue;
            }
            if (curr.first < pq.top().first)
                continue;
            pq.pop();
            pq.push(curr);
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};