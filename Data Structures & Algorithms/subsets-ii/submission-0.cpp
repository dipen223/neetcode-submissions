class Solution {
public:
    void subsetsHelper(vector<int>& nums,vector<vector<int>>&ans,vector<int>&curr,int i){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        subsetsHelper(nums,ans,curr,i+1);
        curr.pop_back();
        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        subsetsHelper(nums,ans,curr,i+1);
    }
    

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>>ans;
       sort(nums.begin(),nums.end());
       vector<int>curr;
       subsetsHelper(nums,ans,curr,0);
       return ans; 
    }
};
