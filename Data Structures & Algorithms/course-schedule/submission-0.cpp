class Solution {
public:
    bool isCycle(int src,vector<vector<int>>&adj, vector<bool>&vis,vector<bool>&recPath){
        vis[src] = true;
        recPath[src] = true;
        for(auto v:adj[src]){
            if(!vis[v]){
                if(isCycle(v,adj,vis,recPath)){
                    return true;
                }
            }else if(recPath[v]){
                return true;
            }
        }
        recPath[src] = false;

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         int v = numCourses;
         vector<bool> vis(v,false);
         vector<bool>recPath(v,false);
         vector<vector<int>> adj(v);
         for(auto edge:prerequisites){
            int prereq = edge[1];
            int course = edge[0];
            adj[prereq].push_back(course);
         }


         for(int i=0; i<v; i++){
            if(!vis[i]){
                if (isCycle(i,adj,vis,recPath)){
                    return false;
                }
            }
         }

       return true;

    }
};
