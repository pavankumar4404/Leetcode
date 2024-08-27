class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int dest) {
        
        vector<vector<pair<int, double>>> adj(n);
        for(int j=0; j<edges.size(); j++){
            auto i = edges[j];
            int u = i[0];
            int v = i[1];
            adj[u].push_back({v, succProb[j]});
            adj[v].push_back({u, succProb[j]});
        }

        vector<double> prob(n, 0);
        prob[src] = 1;

        priority_queue<pair<double, int>> pq;
        pq.push({1, src});
        while(!pq.empty()){
            int node = pq.top().second;
            double p = pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                double pr = it.second;
                int adjNode = it.first;
                if(prob[adjNode] < pr*p){
                    pq.push({pr * p, adjNode});
                    prob[adjNode] = pr * p;
                }
            }
        }
        return prob[dest];
    }
};