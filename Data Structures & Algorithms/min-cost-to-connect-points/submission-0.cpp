class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<bool> mst(V, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        int minCost = 0;

        while (!pq.empty()) {
            int cost = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (mst[u]) continue;
            mst[u] = true;
            minCost += cost;

            for (int v = 0; v < V; v++) {
                if (!mst[v]) {
                    int wt = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    pq.push({wt, v});
                }
            }
        }
        return minCost;
    }
};