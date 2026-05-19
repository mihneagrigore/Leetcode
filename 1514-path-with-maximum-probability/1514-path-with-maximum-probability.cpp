class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }

        priority_queue<pair<double,int>> pq;
        vector<double> prob(n,0.0);

        prob[start] = 1.0;
        pq.push({1.0,start});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            double currProb = it.first;
            int node = it.second;

            if(node == end) return currProb;
            for(auto &edge : adj[node]){

                int adjNode = edge.first;
                double edgeProb = edge.second;
                double newProb = currProb * edgeProb;

                if(newProb > prob[adjNode]){
                    prob[adjNode] = newProb;
                    pq.push({newProb, adjNode});
                }
            }
        }
        return 0.0;
    }
};