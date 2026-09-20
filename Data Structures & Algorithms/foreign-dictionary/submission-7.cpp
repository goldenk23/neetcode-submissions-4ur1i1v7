class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        if (words.size() == 1) {
            return words[0];
        }
        vector<int> letters(26, 0);
        for (auto it : words) {
            for (auto it1 : it) {
                letters[it1 - 'a'] = 1;
            }
        }
        vector<vector<int>> graph(26);
        vector<int> indegree(26, 0);
        for (int i = 1; i < words.size(); i++) {
            int j = 0;
            int n = words[i - 1].length();
            int m = words[i].length();
            while (j < n && j < m) {
                if (words[i - 1][j] == words[i][j]) {
                    j++;
                } else {
                    break;
                }
            }
            if (j == m && n > m) {
                return "";
            }
            if (j < n && j < m) {
                int u = words[i - 1][j] - 'a';
                int v = words[i][j] - 'a';
                graph[u].push_back(v);
                indegree[v]++;
            }
        }
        string ans = "";
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (letters[i] && indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node + 'a');
            for (auto next_node : graph[node]) {
                indegree[next_node]--;
                if (indegree[next_node] == 0) {
                    q.push(next_node);
                }
            }
        }
        if (ans == "") {
            return "";
        }
        int total_letters = 0;
        for (int i = 0; i < 26; i++) {
            if (letters[i]) {
                total_letters++;
            }
        }
        if (ans.length() != total_letters) {
            return "";
        }
        return ans;
    }
};
