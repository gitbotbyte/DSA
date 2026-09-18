struct cmp {
    bool operator()(pair<int, string>& a, pair<int, string>& b) {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& a, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        unordered_map<string, int> mp;
        for (int i = 0; i < a.size(); i++)
            mp[a[i]]++;
        for (auto i : mp) {
            int freq = i.second;
            string word = i.first;
            pair<int, string> curr = {freq, word};
            if (pq.size() < k) {
                pq.push(curr);
                continue;
            }

            pq.push(curr);
            if (pq.size() > k)
                pq.pop();
        }
        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};