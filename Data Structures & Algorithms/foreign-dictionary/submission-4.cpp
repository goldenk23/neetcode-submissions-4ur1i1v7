// class Solution {
// public:
//     string foreignDictionary(vector<string>& words) {
//         vector<vector<int>>graph(26,vector<int>(26,0));
//         vector<int>indegree(26,0);
//         vector<int>present(26,0);
//         for(auto it:words){
//             for(auto c:it){
//                 present[c-'a']=1;
//             }
//         }
//         for(int i=0;i<words.size()-1;i++){
//             string word1=words[i];
//             string word2=words[i+1];
//             int len=min(word1.length(),word2.length());
//             int indx=0;
//             while(indx< len){
//                 if(word1[indx]!=word2[indx]){
//                     if(graph[word1[indx]-'a'][word2[indx]-'a']==0){
//                       graph[word1[indx]-'a'][word2[indx]-'a']=1;
//                       indegree[word2[indx]-'a']++;
//                       break;  
//                     }
//                 }
//                 indx++;
//             }
//              if(indx == len && word1.length() > word2.length())
//                 return "";
//         }
//         queue<int>q;
//         for(int i=0;i<26;i++){
//             if(indegree[i]==0&&present[i]){
//                 q.push(i);
//             }
//         }
//         vector<int>topo;
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             topo.push_back(node);
//             for(int i=0;i<26;i++){
//                 if(graph[node][i]){
//                     indegree[i]--;
//                     if(indegree[i]==0&&present[i]){
//                         q.push(i);
//                     }
//                 }
//             }
//         }
//         int cnt=0;
//         for(auto it:present){if(it){cnt++;}}
//         if(topo.size()!=cnt){return "";}
//         string ans="";
//         for(auto it:topo){
//             ans+=(it+'a');
//         }
//         return ans;
//     }
// };


class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> graph(26, vector<int>(26, 0));
        vector<int> indegree(26, 0);
        vector<int> present(26, 0);

        for (auto it : words) {
            for (auto c : it) {
                present[c - 'a'] = 1;
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            int len = min(word1.length(), word2.length());
            int indx = 0;

            while (indx < len) {
                if (word1[indx] != word2[indx]) {
                    if (graph[word1[indx] - 'a'][word2[indx] - 'a'] == 0) {
                        graph[word1[indx] - 'a'][word2[indx] - 'a'] = 1;
                        indegree[word2[indx] - 'a']++;
                    }
                    break;
                }
                indx++;
            }

            if (indx == len && word1.length() > word2.length())
                return "";
        }

        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0 && present[i]) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int i = 0; i < 26; i++) {
                if (graph[node][i]) {
                    indegree[i]--;
                    if (indegree[i] == 0 && present[i]) {  // ✅ FIX
                        q.push(i);
                    }
                }
            }
        }

        int cnt = 0;
        for (auto it : present) if (it) cnt++;
        if (topo.size() != cnt) return "";

        string ans = "";
        for (auto it : topo) {
            ans += (it + 'a');
        }
        return ans;
    }
};

