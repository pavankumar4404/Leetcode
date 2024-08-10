class Solution {
public:
    vector<int> size;
    vector<int> parent;
    int count;
    int findparent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findparent(parent[node]);
    }
    void connect(int u, int v) {
        u = findparent(u);
        v = findparent(v);
        if (u != v) {
            if (size[u] < size[v]){
                parent[u] = v;
                size[v] += size[u];
            }
            else{
                parent[v] = u;
                size[u] += size[v];
            }
        } else {
            count++;
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int dots = n + 1;

        parent = vector<int>(dots * dots + 1);
        size = vector<int>(dots * dots + 1, 1);
        count = 1;

        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }

        for (int i = 0; i < dots; i++) {
            for (int j = 0; j < dots; j++) {
                if (i == 0 or j == 0 or i == dots - 1 or j == dots - 1) {
                    int cellno = i * dots + j;
                    if (cellno != 0)
                        connect(0, cellno);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    int cellno1 = i * dots + (j + 1);
                    int cellno2 = (i + 1) * dots + j;
                    connect(cellno1, cellno2);
                } 
                else if (grid[i][j] == '\\') {
                    int cellno1 = i * dots + j;
                    int cellno2 = (i + 1) * dots + (j + 1);

                    connect(cellno1, cellno2);
                }
            }
        }
        return count;
    }
};