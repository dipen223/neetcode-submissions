class Solution {
public:
    vector<int> parent; 
                       

    int find(int x) {
        if (parent[x] != x)              // x isn't a leader
            parent[x] = find(parent[x]); // find the real leader, then point straight at it
        return parent[x];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);            // nodes are labeled 1..n, so size n+1
        for (int i = 0; i <= n; i++)
            parent[i] = i;               // everyone starts as their own leader

        for (const auto& edge : edges) {
            int a = find(edge[0]);  // leader of first node
            int b = find(edge[1]);        // leader of second node
            if (a == b) return edge;        // same group already, so this edge is redundant
            parent[a] = b;               // merge: a's leader now follows b's leader
        }
        return {};
    }
};