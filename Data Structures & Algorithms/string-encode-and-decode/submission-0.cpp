class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;

        for (string str : strs) {
            ans += to_string(str.size()) + "#" + str;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            // Find the delimiter '#'
            while (s[j] != '#') {
                j++;
            }

            // Extract length
            int length = stoi(s.substr(i, j - i));

            // Extract the actual string
            string word = s.substr(j + 1, length);
            ans.push_back(word);

            // Move i to the start of the next encoded string
            i = j + 1 + length;
        }

        return ans;
    }
};