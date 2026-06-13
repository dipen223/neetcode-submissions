class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;

        for(string str:strs){
            string str1 = str;
            sort(str.begin(),str.end());

            m[str].push_back(str1);
        }

        for(auto it:m){
            ans.push_back(it.second);
        }

        return ans;
    }
};
