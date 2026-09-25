class Solution {
public:
    void dfs(int src,vector<vector<int>>&adj,vector<bool>&vis){
        vis[src] = true;

        for(int v:adj[src]){
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }


    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }  
        vector<bool>vis(n,false);
        int count = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                count++;
            }
        }
        return count;
    }
};
