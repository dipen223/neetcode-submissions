class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int>m;
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

        for(auto it:m){
            pq.push({it.second,it.first});
        }

        for(int i=0; i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
        

        

   
    }
};
