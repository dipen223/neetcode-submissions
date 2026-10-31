class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &edge:flights){
            int src = edge[0];
            int dst = edge[1];
            int price = edge[2];
            adj[src].push_back({dst,price});
        }

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,greater<>>pq;
        pq.push({0,src,0});
        vector<int> minStops(n, INT_MAX);

        while(!pq.empty()){
            auto [price,node,stops] = pq.top();
            pq.pop();
            if(node == dst){
                return price;
            }

            if(stops >= minStops[node]) continue;
            minStops[node] = stops;

            if(stops == k+1) continue;


            for(auto [neigh,cost] :adj[node]){
                pq.push({price+cost,neigh,stops+1});
            }
        }
        return -1;
    }
};
