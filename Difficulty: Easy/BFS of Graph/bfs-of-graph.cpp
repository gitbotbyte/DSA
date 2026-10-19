class Solution {
	public:
	vector<int> bfs(vector<vector<int>> &adj) {
		// code here
		int n = adj.size();
		vector<int> res;
		vector<bool>vis(n, 0);
		queue<int>q;
		q.push(0);
		vis[0] = true;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			res.push_back(node);
			for (int i = 0; i<adj[node].size(); i++) {
				int n = adj[node][i];
				if (vis[n] == false) {
					q.push(n);
					vis[n] = true;
				}
			}
		}
		return res; 
	}
};
