class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<bool>vis(n+1,false);
        vector<int>lvl(n+1,0);

        vector<vector<pair<int,int>>>adjList(n+1);

        int e = times.size();
        for(int i=0;i<e;i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adjList[u].push_back({v,wt});
        }

        vector<int>dist(n+1,1e8);
        dist[k]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,k});

        while(!pq.empty())
        {
            auto pr = pq.top();
            pq.pop();

            int currNode = pr.second;
            int currTime = pr.first;

            // if(currTime>dist[currNode]) continue;

            for(auto &neigh:adjList[currNode])
            {
                int neighNode = neigh.first;
                int t = neigh.second;

                if(currTime+t<dist[neighNode])
                {
                    dist[neighNode] = currTime + t;
                    pq.push({dist[neighNode],neighNode});
                }
            }
        }

        int ans = INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e8) return -1;
            ans = max(ans,dist[i]);
        }

        return ans;
    }
};