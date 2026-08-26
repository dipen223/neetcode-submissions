class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid){

        grid[row][col] = '0';
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        for(int k=0; k<4; k++){
            int nextRow = row + dr[k];
            int nextCol = col + dc[k];

            if(nextRow >=0 && nextRow < grid.size() && nextCol >=0 && nextCol < grid[0].size() && grid[nextRow][nextCol] != '0'){
                dfs(nextRow,nextCol,grid);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] != '0'){
                    dfs(i,j,grid);
                    count++;
                }
            }
        }

        return count;
        
    }
};
