auto fastIO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<vector<pair<int,int>>> a(n);
        for(int i=0;i<times.size();i++){
            int s=times[i][0];
            int d=times[i][1];
            int w=times[i][2];
            a[s-1].push_back({d-1,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        dist[src-1]=0;
        pq.push({0,src-1});
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            int d=p.first;
            int node=p.second;
            if(d>dist[node])continue;
            for(int i=0;i<a[node].size();i++){
                int ne=a[node][i].first;
                int wt=a[node][i].second;
                if(d+wt<dist[ne]){
                    dist[ne]=d+wt;
                    pq.push({d+wt,ne});
                }
            }
        }
        int maxTime = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};