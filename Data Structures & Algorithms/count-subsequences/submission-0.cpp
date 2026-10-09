class Solution {
public:
    int distinctHelper(string s,string t,int i,int j,vector<vector<int>>&memo){
        if(j < 0) return 1;
        if( i < 0) return 0; 

        if(memo[i][j] != -1) {
            return memo[i][j];
        }


        if(s[i] == t[j]){
           memo[i][j] =  distinctHelper(s,t,i-1,j-1,memo) + distinctHelper(s,t,i-1,j,memo);
        }else{
            memo[i][j] = distinctHelper(s,t,i-1,j,memo);
        }

        return memo[i][j];


    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>memo(s.size(),vector<int>(t.size(),-1));
        return distinctHelper(s,t,n-1,m-1,memo);
        
    }
};



