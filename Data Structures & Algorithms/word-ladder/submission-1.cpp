class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>>graph;
        for(auto it:wordList){
            for(int i=0;i<it.length();i++){
              string pattern=it;
              pattern[i]='*';
              graph[pattern].push_back(it);
            }
        }
        queue<pair<string,int>>q;
        unordered_map<string,int>visited;
        q.push({beginWord,1});
        visited[beginWord]=1;
        int ans=INT_MAX;
        while(!q.empty()){
            string word=q.front().first;
            int count=q.front().second;
            q.pop();
            if(word==endWord){ans=min(ans,count);continue;}
            for(int i=0;i<word.length();i++){
                char c=word[i];
                word[i]='*';
                for(auto next_word:graph[word]){
                    if(!visited[next_word]){
                        visited[next_word]=1;
                        q.push({next_word,count+1});
                    }
                }
                word[i]=c;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};
