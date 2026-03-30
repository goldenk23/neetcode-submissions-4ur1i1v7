class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        
        // Initialize: each node is its own parent
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        // Find with path compression
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };
        
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