class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<matrix.size();i++){
            for(int j=i+1;j<matrix.size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0; i<matrix.size();i++){
            int st = 0;
            int end = matrix.size()-1;
            while(st < end){
                swap(matrix[i][st],matrix[i][end]);
                st++;
                end--;
            }
        }
    }
};


