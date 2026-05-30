class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char,int> cntS;
        unordered_map<char,int> cntT;
        for(int i=0; i< s.size(); i++){
            cntS[s[i]]++;
            cntT[t[i]]++;
        }

        return cntS == cntT;


    }
};
