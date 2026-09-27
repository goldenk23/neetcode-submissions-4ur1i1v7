class Solution {
    bool solve(vector<vector<int>>& graph, vector<int>& visited, int node, int parent) {
        visited[node] = 1;
        bool ans = true;
        for (auto next_node : graph[node]) {
            if (visited[next_node]) {
                if (next_node != parent) {
                    return false;
                }
            } else {
                ans = ans && solve(graph, visited, next_node, node);
            }
        }
        return ans;
    }

   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n, 0);
        if (!solve(graph, visited, 0, -1)) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                // graph is unconnected
                return false;
            }
        }
        return true;
    }
};
