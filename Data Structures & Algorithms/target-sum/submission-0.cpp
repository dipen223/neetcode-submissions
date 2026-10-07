class Solution {
public:
    int targetSumWays(vector<int>&nums,int target,int i,int sum,vector<vector<int>>&dp){
        if(i == nums.size() && target == 0) {
            return 1;
        }

        if(i == nums.size()) {
            return 0;
        }
         if(abs(target) > sum) return 0;
        if(dp[i][target+sum] != -1) return dp[i][target+sum];

        return dp[i][target+sum] = targetSumWays(nums,target-nums[i],i+1, sum,dp) +
        targetSumWays(nums,target+nums[i],i+1,sum,dp);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
           if (abs(target) > sum) return 0;
        vector<vector<int>>memo(n,vector<int>(2*sum+1,-1));
        return targetSumWays(nums,target,0,sum,memo);
        
    }
};
