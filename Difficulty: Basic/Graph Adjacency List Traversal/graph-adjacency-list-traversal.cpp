class Solution {
	public:
	vector<vector<int>> printGraph(int V, vector<pair<int, int>> & edges) {
		// code here
		vector<vector<int>> adj(V);
		for (int i = 0; i<edges.size(); i++) {
			int src = edges[i].first;
			int dst = edges[i].second;
			adj[src].push_back(dst);
			adj[dst].push_back(src);
		}
		return adj;
	}
};
