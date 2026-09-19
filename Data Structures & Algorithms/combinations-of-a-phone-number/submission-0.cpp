class Solution {
public:
    void combinationHelper(unordered_map<char,string>&mp,vector<string>&ans,int i,string&digits,string currStr){
        if(currStr.size() == digits.size()){
            ans.push_back(currStr);
            return;

        }

        for(char ch:mp[digits[i]]){
            combinationHelper(mp,ans,i+1,digits,currStr+ch);
        }
    
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>map;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        vector<string>ans;
        string currStr="";
         if(digits.size() != 0){
            combinationHelper(map,ans,0,digits,currStr);
         }
        
        return ans;
    }
};

