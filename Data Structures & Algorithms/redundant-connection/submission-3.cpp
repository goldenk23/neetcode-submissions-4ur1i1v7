class Solution {
private:
    vector<int> parent;
    
    // Find function with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    // Union function (not strictly needed as separate function)
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        
        // Initialize: each node is its own parent
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        // Process edges in order
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            int rootU = find(u);
            int rootV = find(v);
            
            // If already connected, this edge creates a cycle
            if (rootU == rootV) {
                return edge;
            }
            
            // Union: connect the two components
            parent[rootU] = rootV;
        }
        
        return {}; // Should never reach here
    }
};