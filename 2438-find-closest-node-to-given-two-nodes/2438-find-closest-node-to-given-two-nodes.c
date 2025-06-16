// dfs
void dfs(int* edges, int edgesSize, int node, int* visited, int* distance, int dist) {
	if (node == -1 || visited[node]) return;
	visited[node] = 1;
	distance[node] = dist;
	dfs(edges, edgesSize, edges[node], visited, distance, dist + 1);
}

int closestMeetingNode(int* edges, int edgesSize, int node1, int node2) {
	int visited1[edgesSize];
	int visited2[edgesSize];
	int distance1[edgesSize];
	int distance2[edgesSize];

	// Initialize visited and distance arrays
	for (int i = 0; i < edgesSize; i++) {
		visited1[i] = 0;
		visited2[i] = 0;
		distance1[i] = -1;
		distance2[i] = -1;
	}

	// Perform DFS for both nodes
	dfs(edges, edgesSize, node1, visited1, distance1, 0);
	dfs(edges, edgesSize, node2, visited2, distance2, 0);

	int minDistance = -1;
	int closestNode = -1;

	for (int i = 0; i < edgesSize; i++) {
		if (visited1[i] && visited2[i]) {
			int maxDistance = distance1[i] > distance2[i] ? distance1[i] : distance2[i];
			if (minDistance == -1 || maxDistance < minDistance) {
				minDistance = maxDistance;
				closestNode = i;
			}
		}
	}

	return closestNode;
}


