class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        vector<vector<bool>>seen(n,vector<bool>(n,false));
        pq.push({grid[0][0],0,0});
        seen[0][0] = true;

        int time = 0;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!pq.empty()){
            auto [h,r,c] = pq.top();
            pq.pop();
            time = max(time,h);
            if(r == n-1 && c == n-1) return time;

            for(int k=0; k<4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >=0 && nr < n && nc >=0 && nc < n && !seen[nr][nc]){
                    seen[nr][nc] = true;
                    pq.push({grid[nr][nc],nr,nc});
                }
            }
        }

        return -1;
    }
};
