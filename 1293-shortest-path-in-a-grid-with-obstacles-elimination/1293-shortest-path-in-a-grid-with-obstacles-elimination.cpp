class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (m == 1 && n == 1) return 0; // already at target
        
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        
        queue<tuple<int,int,int,int>> q; // x, y, steps, remaining k
        q.push({0, 0, 0, k});
        visited[0][0][k] = true;
        
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        
        while(!q.empty()) {
            auto [x, y, steps, rem] = q.front(); q.pop();
            
            for(int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                
                int nk = rem - grid[nx][ny]; // if obstacle, reduce k
                
                if(nk < 0) continue; // cannot pass
                
                if(nx == m-1 && ny == n-1) return steps + 1; // reached target
                
                if(!visited[nx][ny][nk]) {
                    visited[nx][ny][nk] = true;
                    q.push({nx, ny, steps + 1, nk});
                }
            }
        }
        
        return -1; // not reachable
    }
};