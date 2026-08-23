class Solution {
public:
    bool searchRow(int row,int m,vector<vector<int>>& matrix,int target){
        int st = 0;
        int end = m;
        while(st <= end){
            int mid = st + (end - st) /2 ;

            if(target == matrix[row][mid]){
                return true;
            }else if(target > matrix[row][mid]){
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return false;

    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int stRow = 0;
        int endRow = matrix.size()-1;
        int n = matrix.size()-1;
        int m = matrix[0].size()-1;

        while(stRow <= endRow){
            int mid = stRow + (endRow - stRow ) / 2;
            if(searchRow(mid,m,matrix,target)){
                return true;
            }else if(target > matrix[mid][0] && target > matrix[mid][m]){
                stRow = mid+1;
            }else{
                endRow = mid-1;
            }

        }

        return false;


    }
};
