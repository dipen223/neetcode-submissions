class Solution {
public:
    void topoSort(int u, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& s) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) topoSort(v, adj, vis, s);
        }
        s.push(u);
    }

    bool isCycle(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& recPath) {
        vis[u] = true;
        recPath[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) {
                if (isCycle(v, adj, vis, recPath)) return true;
            } else if (recPath[v]) {
                return true;
            }
        }
        recPath[u] = false;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(numCourses, false), recPath(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i] && isCycle(i, adj, vis, recPath)) return {};
        }

        vector<bool> vis2(numCourses, false);
        stack<int> s;
        for (int i = 0; i < numCourses; i++) {
            if (!vis2[i]) topoSort(i, adj, vis2, s);
        }

        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};