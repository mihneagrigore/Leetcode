class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        vector<int> dist(n+1, INT_MAX);

        for(auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()) {
            int node = pq.top().second, cost = pq.top().first;
            pq.pop();

            if(cost > dist[node]) continue;

            for(auto neigh : adj[node]) {
                int nnode = neigh.first, ncost = neigh.second;

                if(ncost + cost < dist[nnode]) {
                    dist[nnode] = ncost + cost;
                    pq.push({dist[nnode], nnode});
                }
            }
        }

        int maxim = -1;
        for(int i = 1; i <= n; ++i) {
            if(dist[i] == INT_MAX)
                return -1;
            if(maxim < dist[i])
                maxim = dist[i];
        }

        return maxim;
    }
};