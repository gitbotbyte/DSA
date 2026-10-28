class Solution {
public:
    bool res=1;
    void dfs(vector<vector<int>>&graph, int node, int c, vector<int >&colors){
        colors[node]=c;
        for(int i=0;i<graph[node].size();i++){
            int ne=graph[node][i];
            if(colors[ne]!=-1 && colors[ne]== c){
                res=false;
            }
            if(colors[ne]==-1){
                dfs(graph,ne, 1-c, colors);
            }
        }
        return;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colors(n,-1);
        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                dfs(graph,i,0,colors);
            }
        }
        return res;
    }
};