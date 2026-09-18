struct cmp {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& a, int k) {
        unordered_map<string, int> mp;
        for (int i = 0; i < a.size(); i++) {
            mp[a[i]]++;
        }
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;      
        
        for (auto i : mp) {
            string word = i.first;
            int freq = i.second;
            pair<string, int> curr = {word, freq};
            
            pq.push(curr);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};