class Solution {
public:
    bool subSetHelper(vector<int>&nums,int i,int target,int currSum,vector<vector<int>>&memo){
        if(currSum == target) return true;
        if(i == nums.size() ||  currSum >target){
            return false;
        }
        if(memo[i][currSum] != -1){
            return memo[i][currSum];
        }



        return memo[i][currSum] =  subSetHelper(nums,i+1,target,currSum+nums[i],memo) || 
        subSetHelper(nums,i+1,target,currSum,memo);

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum+= nums[i];
        }
        if(sum % 2 != 0) return false;




        int target = sum / 2;
        vector<vector<int>>memo(n,vector<int>(target+1,-1));
        return subSetHelper(nums,0,target,0,memo);
        
    }
};
