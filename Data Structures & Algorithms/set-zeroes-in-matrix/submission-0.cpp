class Solution {
public:
   void setZero(int row,int col,vector<vector<int>>&matrix){
    for(int i=0; i<matrix.size();i++){
        matrix[i][col] = 0;
    }

    for(int i=0; i<matrix[0].size(); i++){
        matrix[row][i]  = 0;
    }

  


    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>vec;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++ ){
                if(matrix[i][j] == 0){
                    vec.push_back({i,j});

                }
            }
        }

        for(auto it:vec){
            setZero(it.first,it.second,matrix);
        }
    }
};
