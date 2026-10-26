class Solution {
	public:
	bool cycle = false;
	
	void dfs(vector<vector<int>> & a, int node, int n, vector<bool> &path, vector<bool>&vis) {
		vis[node] = 1;
		path[node] = 1;
		for (int i = 0; i<a[node].size(); i++) {
			int ne = a[node][i];
			if (vis[ne] == 1 && path[ne] == 1) {
				cycle = true;
			}
			if (vis[ne] == false) {
				dfs(a, ne, n, path, vis);
			}
		}
		path[node] = 0;
		return;
	}
	bool isCyclic(int n, vector<vector<int>> &edges) {
		// code here
		vector<vector<int>> a(n);
		for (int i = 0; i<edges.size(); i++) {
			int src = edges[i][0];
			int dst = edges[i][1];
			a[src].push_back(dst);
			
		}
		vector<bool>vis(n, 0);
		vector<bool>path(n, 0);
		for (int i = 0; i<n; i++) {
			if (!vis[i]) {
				dfs(a, i, n, path, vis);
				
			}
		}
		return cycle;
	}
};
