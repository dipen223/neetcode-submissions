class Solution {
   public:
    void dfs(unordered_map<string,vector<string>>&adj,vector<string>&ans,string curr){
        while(!adj[curr].empty()){
            string next = adj[curr].back();
            adj[curr].pop_back();
            dfs(adj,ans,next);
        }
        ans.push_back(curr);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.rbegin(), tickets.rend());
        unordered_map<string, vector<string>> adj;
        for (auto& edge : tickets) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<string>ans;
        dfs(adj,ans,"JFK");

        reverse(ans.begin(),ans.end());
        return ans; 

    }
};
