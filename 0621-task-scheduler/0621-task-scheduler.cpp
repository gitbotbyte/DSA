class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> mp;
        for (char t : tasks) {
            mp[t]++;
        }


        priority_queue<pair<int, char>> pq;
        for (auto entry : mp) {
            pq.push({entry.second, entry.first});
        }

        int total_time = 0;


        while (!pq.empty()) {
            vector<pair<int, char>> remaining_tasks;
            int cycle = n + 1;


            while (cycle > 0 && !pq.empty()) {
                auto current = pq.top();
                pq.pop();

                current.first--;
                
                if (current.first > 0) {
                    remaining_tasks.push_back(current);
                }

                total_time++;
                cycle--;
            }


            for (auto item : remaining_tasks) {
                pq.push(item);
            }


            if (!pq.empty()) {
                total_time += cycle; 
            }
        }

        return total_time;
    }
};