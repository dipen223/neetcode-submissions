class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> merged = {0, 0, 0};
        for (auto& t : triplets) {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2])
                continue; 
            for (int j = 0; j < 3; j++)
                merged[j] = max(merged[j], t[j]);
        }
        return merged == target;
    }
};

