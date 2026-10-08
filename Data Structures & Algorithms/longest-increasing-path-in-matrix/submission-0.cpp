class Solution {
public:
   int longestPath(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>&memo){   
    if (memo[row][col] != 0) return memo[row][col];    
    int best = 1;

             

    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};

    for(int k=0; k<4;k++){
        int nextRow = row + dr[k];
        int nextCol = col + dc[k];

        if(nextRow >= 0 && nextCol >=0 && nextRow < matrix.size() && nextCol < matrix[0].size() && matrix[nextRow][nextCol] > matrix[row][col]){
           
            best = max(best,1+ longestPath(nextRow,nextCol,matrix,memo));
             
        }
        
    }
    return memo[row][col] = best;



   }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>memo(n,vector<int>(m,0));
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                ans = max(ans,longestPath(i,j,matrix,memo));
            }
        }
        return ans;
    }
};

