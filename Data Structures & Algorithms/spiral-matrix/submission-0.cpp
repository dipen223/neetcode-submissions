class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int startRow = 0;
        int endRow = matrix.size()-1;
        int startCol = 0;
        int endCol = matrix[0].size()-1;
        while(startRow <=endRow && startCol <=endCol){

        for(int i=startCol; i<=endCol; i++){
            ans.push_back(matrix[startRow][i]);
        }
        startRow++;

        for(int i=startRow; i<=endRow;i++){
            ans.push_back(matrix[i][endCol]);
        }
        endCol--;
         
        if(startRow > endRow) break; 
        for(int i=endCol; i>=startCol; i--){
            ans.push_back(matrix[endRow][i]);
        }
        endRow--;

        if(startCol > endCol)break;
        for(int i=endRow; i>=startRow; i--){
            ans.push_back(matrix[i][startCol]);
        }
        startCol++;

        }
        return ans;
    }
};
