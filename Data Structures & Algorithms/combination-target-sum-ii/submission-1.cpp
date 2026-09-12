class Solution {
public:
    void combinationHelper(vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>&curr, int i){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(target < 0 || i == candidates.size()){
            return;
        }
        curr.push_back(candidates[i]);
        combinationHelper(candidates,target-candidates[i],ans,curr,i+1);
        curr.pop_back();
        int next = i+1;
        while(next < candidates.size() && candidates[i] == candidates[next]) next++;
        combinationHelper(candidates,target,ans,curr,next);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         sort(candidates.begin(), candidates.end()); 
        vector<vector<int>>ans;
        vector<int>curr;
        combinationHelper(candidates,target,ans,curr,0);
        return ans;
    }
};
