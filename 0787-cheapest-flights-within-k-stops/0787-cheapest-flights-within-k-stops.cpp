class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        
        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<int> dist(n+1, INT_MAX);
        pq.push({0, {src, 0} });
        dist[src] = 0;

        while(!pq.empty()) {
            int stops = pq.top().first, node = pq.top().second.first, cost = pq.top().    second.second;
            pq.pop();

            if(stops > k) continue;

            for(auto neigh : adj[node]) {
                int nw = neigh.second, nnode = neigh.first;
                int newcost = nw + cost;

                if(newcost < dist[nnode] && stops <= k) {
                    dist[nnode] = newcost;
                    pq.push({stops + 1, {nnode, dist[nnode]}});
                }
            }
        }

        if(dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};