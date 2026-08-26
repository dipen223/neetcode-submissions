class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;

        queue<pair<pair<int,int>,int>>q;
        int fresh = 0;
        for(int i=0; i<rows;i++){
            for(int j=0; j<cols;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        if(fresh ==0){
            return 0;
        }

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};
        while(!q.empty()){
                int row = q.front().first.first;
                int col = q.front().first.second;
                int t = q.front().second;
                q.pop();

                ans = max(ans,t);

                for(int k=0; k<4; k++){
                    int i = row + dr[k];
                    int j = col + dc[k];
                    if(i >=0 && i< rows && j>= 0 && j<cols && grid[i][j] == 1){
                        grid[i][j] = 2;
                        q.push({{i,j},t+1});
                    }
                }

            }
             for(int i=0; i<rows;i++){
            for(int j=0; j<cols;j++){
                if(grid[i][j] == 1){
                   return -1;
                }
            }
        }

        return ans;

        }

};