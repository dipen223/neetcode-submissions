class Solution {
public:
    bool canJumpHelper(vector<int>&nums,int i,int steps){
        if (i == 0) return steps == 1;
        if(nums[i-1] >= steps){
            return canJumpHelper(nums,i-1,1);
        }else{
            return canJumpHelper(nums,i-1,steps+1);
        }

        return false;


    }
    bool canJump(vector<int>& nums) {
        return canJumpHelper(nums,nums.size()-1,1);
    }
};
