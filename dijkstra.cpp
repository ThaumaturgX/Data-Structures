// Returns a vector of distances from node v to each node
// where v[i] is the length of the shortest path from node v
// to node i or -1 if there is no path between these nodes.
// Indexing starts from 0.
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int v) {
	int n = adj.size();
	assert(v < n);
	
	vector<bool> vis(n, 0);
	vector<int> dist(n, INT_MAX);
	dist[v] = 0;
	
	priority_queue<pair<int,int>> q;
	q.push({0, v});
	
	while(!q.empty()) {
		int vertex = q.top().second;
		q.pop();
		if(vis[vertex]) continue;
		vis[vertex] = 1;
		
		for(auto &p : adj[vertex]) {
			int &neighbor = p.first, &weight = p.second;
			if(dist[vertex] + weight < dist[neighbor]) {
				dist[neighbor] = dist[vertex] + weight;
				q.push({-dist[neighbor], neighbor});
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(!vis[i]) dist[i] = -1;
	}
	return dist;
}
