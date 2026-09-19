class Solution {
public:
    bool isValid(int r,int c,vector<string>&board,int n){
        // row validity
        for(int i=0; i<n; i++){
            if(board[r][i] == 'Q'){
                return false;
            }
        }

        //column check
        for(int i=0; i<n; i++){
            if(board[i][c] == 'Q'){
                return false;
            }
        }

        //diagonal check
        //top-left
      
        for(int i=r,j=c; i>=0 && j >=0; i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }

        }

        //top-right
        for(int i=r,j=c; i>=0 && j < n; i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

     

        return true;

    }

    void nQueens(vector<string>&board,int row,int n,vector<vector<string>>&ans){
        if(row == n){
            ans.push_back({board});
            return;
        }

        for(int i=0; i<n;i++){
            if(isValid(row,i,board,n)){
                board[row][i] = 'Q';
                nQueens(board,row+1,n,ans);
                board[row][i] = '.';
            }


        }
        

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        nQueens(board,0,n,ans);
        return ans;
        
    }
};
