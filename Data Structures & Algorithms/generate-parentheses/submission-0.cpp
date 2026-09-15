class Solution {
public:
   void generateParenthesisHelper(int n,int open,int close,string&curr,vector<string>&ans){
        if(open == n &&  close == n){
            ans.push_back(curr);

        }

        if(open < n){
            curr+="(";
            generateParenthesisHelper(n,open+1,close,curr,ans);
            curr.pop_back();
        }
        

        if(close < open){
            curr+=")";
            generateParenthesisHelper(n,open,close+1,curr,ans);
            curr.pop_back();
        }


    }
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        string curr = "";
        vector<string>ans;
        generateParenthesisHelper(n,open,close,curr,ans);
        return ans;
    }
};

