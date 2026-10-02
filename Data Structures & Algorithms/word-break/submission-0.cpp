class Node{
    public:
    unordered_map<char,Node*>children;
    bool endOfWord;

    Node(){
        endOfWord = false;
    }
};

class Trie{
    
    public:
    Node* root;
        Trie(){
            root = new Node();
        }

        void insert(string key){
            Node* temp = root;
            for(int i=0; i<key.size(); i++){
                if(temp->children.count(key[i]) == 0){
                    temp->children[key[i]] = new Node();
                }

                temp = temp->children[key[i]];
            }

            temp->endOfWord = true;
        }   
};

class Solution {
    Trie trie;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string word:wordDict){
            trie.insert(word);

        }
        int n = s.size();
        vector<bool>dp(n+1,false);
        dp[0] = true;

        for(int i=0; i<n; i++){
            if (!dp[i]) continue; 
            Node* curr = trie.root;

            for(int j=i; j<n; j++){
                if(curr->children.count(s[j]) == 0) break;
                curr = curr->children[s[j]];
                if(curr->endOfWord) dp[j+1] = true;
            } 

        }


        return dp[n];


    }
};
