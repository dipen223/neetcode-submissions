class Solution {
public:
    int minDistanceHelper(string word1,string word2,int i,int j,vector<vector<int>>&memo){
        if(i == word1.size()) return word2.size()-j;
        if(j==word2.size()) return word1.size()-i;

        if (memo[i][j] != -1) return memo[i][j];
     
      
      if(word1[i] == word2[j]){
        return memo[i][j] = minDistanceHelper(word1,word2,i+1,j+1,memo);
      }

      int deleteOp =  1 +  minDistanceHelper(word1,word2,i+1,j,memo);
      int replaceOp =  1 + minDistanceHelper(word1,word2,i+1,j+1,memo);
      int insertOp = 1 + minDistanceHelper(word1,word2,i,j+1,memo);
      return memo[i][j] = min({deleteOp,replaceOp,insertOp});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>memo(word1.size(),vector<int>(word2.size(),-1));
        return minDistanceHelper(word1,word2,0,0,memo);
    }
};
