class Solution {
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

   public:
    bool search(vector<vector<char>>& board, int x, int y, int indx, string& word,
                vector<vector<int>>& visited) {
        if (indx == word.length()) {
            return true;
        }
        for (auto it : dir) {
            int new_x = x + it.first;
            int new_y = y + it.second;
            if (0 <= new_x && new_x < board.size() && 0 <= new_y && new_y < board[0].size() &&
                !visited[new_x][new_y] && board[new_x][new_y] == word[indx]) {
                visited[new_x][new_y] = 1;
                if (search(board, new_x, new_y, indx + 1, word, visited)) {
                    return true;
                }
                visited[new_x][new_y] = 0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j]=1;
                    if (search(board, i, j, 1, word, visited)) {
                        return true;
                    }
                    visited[i][j]=0;
                }
            }
        }
        return false;
    }
};
