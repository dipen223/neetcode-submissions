class Solution {
public:
    int jumpHelper(int i, vector<int>& nums,vector<int>&memo) {
        if (i >= nums.size() - 1) return 0;     
        if(memo[i] != -1) return memo[i];     
        int best = nums.size();
        for (int k = 1; k <= nums[i]; k++) {       
            best = min(best, 1 + jumpHelper(i + k, nums,memo));
        }
        return memo[i] = best;
    }
    int jump(vector<int>& nums) {
        vector<int>memo(nums.size(),-1);
        return jumpHelper(0, nums,memo);
    }
};
