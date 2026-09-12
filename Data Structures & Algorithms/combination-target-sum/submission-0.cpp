class Solution {
public:
    void combinationSumHelper(vector<int>&nums,vector<vector<int>>&ans,vector<int>&curr,int target,int i){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
         if (target < 0 || i >= nums.size()) {
            return;
        }

        curr.push_back(nums[i]);
        combinationSumHelper(nums,ans,curr,target-nums[i],i);
        curr.pop_back();
        combinationSumHelper(nums,ans,curr,target,i+1);
        
    }
    

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        int sum = 0;
        combinationSumHelper(nums,ans,curr,target,0);
        return ans;

    }
};
