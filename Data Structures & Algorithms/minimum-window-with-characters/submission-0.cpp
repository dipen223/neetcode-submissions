class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()){
            return "";
        }
        unordered_map<char,int>needMap;
        unordered_map<char,int>haveMap;
        for(char ch:t){
            needMap[ch]++;
        }

        int have = 0;
        int need = needMap.size();

        int left = 0;
        int minLength = INT_MAX;
        int startIndex = 0;
        for(int right=0; right<s.size(); right++){
            char ch = s[right];
            if(needMap.count(ch)){
                haveMap[ch]++;

                if(haveMap[ch] == needMap[ch]){
                    have++;
                }
            }

            while(have == need){
                int currentLength = right - left + 1;

                if(currentLength < minLength){
                    minLength = currentLength;
                    startIndex = left;
                }

                char leftChar = s[left];
                if(needMap.count(leftChar)){
                    if(haveMap[leftChar] == needMap[leftChar]){
                        have--;
                    }

                    haveMap[leftChar]--;

                }
                left++;
            }
        }

        if(minLength == INT_MAX) return "";

        return s.substr(startIndex,minLength);
    }
       
};
