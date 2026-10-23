class Solution {
  public:
    bool cycle=false;
    void dfs(vector<vector<int>>& a,int n, int node, int parent, vector<bool> &vis){
        vis[node]=1;
        for(int i=0;i<a[node].size();i++){
            int neighbour=a[node][i];
            if(vis[neighbour]==1 && neighbour!=parent) cycle =true;
            if(vis[neighbour]==0 ) dfs(a,n,neighbour, node, vis);
        }
        return;
    }
    
    bool isCycle(int n, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>a(n);
        for(int i=0;i<edges.size();i++){
            int src=edges[i][0];
            int dst=edges[i][1];
            a[src].push_back(dst);
            a[dst].push_back(src);
        }
        vector<bool>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(a,n,i,-1,vis);
                
            }
        }
        return cycle;
    }
};