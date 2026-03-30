class Solution {
     unordered_map<string,multiset<string>>graph;
      vector<string>ans;
public:
      void dfs(string curr){
        while(!graph[curr].empty()){
            auto it=*graph[curr].begin();
            graph[curr].erase(graph[curr].begin());
            dfs(it);
        }
        ans.push_back(curr);
      }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
     for(auto it:tickets){
        graph[it[0]].insert(it[1]);
     }
     dfs("JFK");
     reverse(ans.begin(),ans.end());
     return ans;
    }
};
