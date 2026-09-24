class Solution {
public:
    void dfs(int src,int &count,vector<vector<int>>&adj,vector<bool>&vis){
        vis[src] = true;
        count++;
        for(int v:adj[src]){
            if(!vis[v]){
                dfs(v,count,adj,vis);
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1){
            return false;
        }

        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool>vis(n,false);
        int count = 0;
        dfs(0,count,adj,vis);

        return count == n;
    }
};

