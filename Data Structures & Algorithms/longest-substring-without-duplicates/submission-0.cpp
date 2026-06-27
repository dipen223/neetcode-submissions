class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>set;
        int ans = 0;
        int left =0;
        for(int i=0; i<s.size();i++){
            while(set.count(s[i])){
                set.erase(s[left]);
                left++;
            }
            set.insert(s[i]);
            ans = max(ans,i-left+1);
        }


        return ans;
   

    }
};

