class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++){
          if(i > 0 && nums[i] == nums[i-1]) continue;

            int result = -nums[i];

            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                if(nums[left] + nums[right] == result){
                    ans.push_back({-result,nums[left],nums[right]});
                    left++,right--;
            while(left < right && nums[left-1] == nums[left]) left++;
            while(left < right && nums[right] == nums[right+1]) right--;

                }
                else if(nums[left] + nums[right] < result){
                    left++;
                }else{
                    right--;;
                }
               
            }

        }

        return ans;
    }
};

