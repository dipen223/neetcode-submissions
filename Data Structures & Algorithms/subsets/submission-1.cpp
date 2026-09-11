class Solution {
public:
    void subsetHelper(vector<int>&nums,vector<vector<int>>&ans,vector<int>&curr,int i){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        subsetHelper(nums,ans,curr,i+1);
        curr.pop_back();
        subsetHelper(nums,ans,curr,i+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>curr;
        subsetHelper(nums,ans,curr,0);
        return ans;
    }
};
