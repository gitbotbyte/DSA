class Solution {
public:
    int leastInterval(vector<char>& a, int n) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;
        for (int i = 0; i < a.size(); i++)
            mp[a[i]]++;
        for (auto i : mp) {
            pq.push({i.second, i.first});
        }
        int total_time = 0;
        while (!pq.empty()) {
            pair<int, char> p = pq.top();
            vector<int> temp;
            int cycle = n + 1;
            while (cycle > 0 && !pq.empty()) {
                int freq = pq.top().first;
                pq.pop();
                freq--;
                if (freq > 0) {
                    temp.push_back(freq);
                }
                total_time++;
                cycle--;
            }
            for (int count : temp) {
                pq.push({count, ' '});
            }
            if (!pq.empty()) {
                total_time += cycle;
            }
        }
        return total_time;
    }
};