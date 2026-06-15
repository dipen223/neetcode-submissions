class Solution {
public:
   bool canPlaceSudoku(vector<vector<char>>& board,
                    char num,
                    int row,
                    int col) {

    for(int i = 0; i < 9; i++) {
        if(i != col && board[row][i] == num)
            return false;
    }

    for(int i = 0; i < 9; i++) {
        if(i != row && board[i][col] == num)
            return false;
    }

    int sRow = (row / 3) * 3;
    int sCol = (col / 3) * 3;

    for(int i = sRow; i < sRow + 3; i++) {
        for(int j = sCol; j < sCol + 3; j++) {
            if((i != row || j != col) &&
               board[i][j] == num)
                return false;
        }
    }

    return true;
}
 

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++) {
        for(int col = 0; col < 9; col++) {

            if(board[row][col] == '.')
                continue;

            if(!canPlaceSudoku(board, board[row][col], row, col))
                return false;
        }
    }
    return true;
        
    }
};
