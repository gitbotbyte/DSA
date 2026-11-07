class Solution {
  public:
    vector<int> dijkstra(vector<vector<vector<int>>> &adj, int src) {
        // Code here
        int n=adj.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            pq.pop();
            int d=p.first;
            int node=p.second;
            if(d>dist[node])continue;
            for(int i=0;i<adj[node].size();i++){
                int ne=adj[node][i][0];
                int wt=adj[node][i][1];
                if(d+wt<dist[ne]){
                    dist[ne]=wt+d;
                    pq.push({d+wt,ne});
                }
            }
        }
        return dist;
    }
};