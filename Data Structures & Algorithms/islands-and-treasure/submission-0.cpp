class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        
        vector<vector<bool>>vis(rows,vector<bool>(cols,false));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
        }
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto [row,col] = q.front();
                q.pop();
                grid[row][col] = dist;

                int dr[] = {-1,1,0,0};
                int dc[] = {0,0,-1,1};
                for(int k=0; k<4; k++){
                    int nextRow = row + dr[k];
                    int nextCol = col + dc[k];

                    if(nextRow >=0 && nextRow < rows && nextCol >=0 && nextCol < cols && !vis[nextRow][nextCol] && grid[nextRow][nextCol] != -1){
                        q.push({nextRow,nextCol});
                        vis[nextRow][nextCol] = true;
                    }
                }

            }
            dist+=1;
        }



    }
};
