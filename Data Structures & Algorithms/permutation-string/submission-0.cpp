class Solution {
public:
    bool isFreqSame(int freq[26],int windowFreq[26]){
        for(int i=0; i<26;i++){
            if(freq[i] != windowFreq[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(int i=0; i<s1.size(); i++){
            freq[s1[i]-'a']++;
        }
        int windowSize = s1.size();
        for(int i=0; i<s2.size(); i++){
            int windowIdx = 0; int idx = i;
            int windowFreq[26] = {0};
            while(windowIdx < windowSize && idx < s2.size()){
                windowFreq[s2[idx]-'a']++;
                windowIdx++; idx++;
            }


            if(isFreqSame(freq,windowFreq)) return true;

        }

        return false;
        
    }
};

