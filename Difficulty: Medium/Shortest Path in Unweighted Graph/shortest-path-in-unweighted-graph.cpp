class Solution {
  public:
    int shortestPath(int n, vector<vector<int>> &edges, int src, int dst) {
        // code here
        if (src == dst) return 0;
        vector<vector<int>> a(n);
        for(int i=0;i<edges.size();i++){
            int s=edges[i][0];
            int d=edges[i][1];
            a[s].push_back(d);
            a[d].push_back(s);
        }
        vector<int> res(n,-1);
        vector<bool> vis(n,0);
        queue<pair<int,int>> q;
        q.push({src,0});
        vis[src]=1;
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int node=p.first;
            int dist=p.second;
            res[node]=dist;
            if (node == dst) return dist;
            for(int i=0;i<a[node].size();i++){
                int ne=a[node][i];
                if(vis[ne]==0){
                    q.push({ne,dist+1});
                    vis[ne]=1;
                }
            }
        }
        return res[dst];
    }
};
