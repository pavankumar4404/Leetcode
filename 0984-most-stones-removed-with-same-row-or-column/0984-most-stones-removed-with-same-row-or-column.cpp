class DS{
public:
    vector<int> size;
    vector<int> parent;
    DS(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void Union(int u, int v){
        int up_u = findPar(u);
        int up_v = findPar(v);
        if(up_u == up_v) return;

        if(size[up_u] < size[up_v]){
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else{
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(auto it:stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DS ds(maxRow + maxCol + 1);
        for(auto it: stones){
            int r = it[0];
            int c = it[1] + maxRow + 1;
            ds.Union(r, c);
        }
        int comp = 0;
        for(int i=0; i<maxRow+maxCol+1; i++){
            if(ds.parent[i] == i and ds.size[i]>1){
                comp++;
            }
        }
        return n-comp;
    }
};