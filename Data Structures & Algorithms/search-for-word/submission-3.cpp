class Solution {
vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>>visited(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    string curr="";
                    curr.push_back(word[0]);
                    visited[i][j]=1;
                    if(search(board,i,j,curr,word,visited)){
                        return true;
                    }
                    visited[i][j]=0;
                }
            }
        } 
        return false;
    }
    bool search(vector<vector<char>>&board,int i,int j,string curr,string target,
    vector<vector<int>>&visited){
        if((curr==target)){
            return true;
        }
        if(curr.length()>target.length()){
            return false;
        }
        int len=curr.length();
        for(auto it:dir){
            int new_i=i+it.first;
            int new_j=j+it.second;
            if(0<=new_i&&new_i<board.size()&&0<=new_j&&new_j<board[0].size()
            &&!visited[new_i][new_j]){
                if(board[new_i][new_j]==target[len]){
                    visited[new_i][new_j]=1;
                    curr.push_back(board[new_i][new_j]);
                    if(search(board,new_i,new_j,curr,target,visited)){
                        return true;
                    }
                    curr.pop_back();
                    visited[new_i][new_j]=0;
                }
            }
        }
        return false;
    }
};
