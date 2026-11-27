class TrieNode {
   public:
    TrieNode* children[26];
    bool isEndOfWord;  // help locate if we have sucessfully travesed a word in tree
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};
class Trie {
   private:
    TrieNode* root;

   public:
    Trie() { root = new TrieNode(); }
    void insert(string word) {
        TrieNode* node = root;
        for (auto c : word) {
            int indx = c - 'a';
            if (!node->children[indx]) {
                node->children[indx] = new TrieNode();
            }
            node = node->children[indx];
        }
        node->isEndOfWord = true;
    }
    TrieNode* getRoot() { return root; }
};
class Solution {
    vector<string> ans;
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& board, int x, int y, TrieNode* node, string& word,
             vector<vector<int>>& visited) {
        if (node->isEndOfWord) {
            ans.push_back(word);
            node->isEndOfWord=false;
        }
        for (auto it : dir) {
            int new_x = x + it.first;
            int new_y = y + it.second;
            if (0 <= new_x && new_x < board.size() && 0 <= new_y && new_y < board[0].size() &&
                !visited[new_x][new_y]) {
                int indx = board[new_x][new_y] - 'a';
                if (node->children[indx]) {
                    visited[new_x][new_y] = 1;
                    word.push_back(board[new_x][new_y]);
                    dfs(board, new_x, new_y, node->children[indx], word, visited);
                    visited[new_x][new_y] = 0;
                    word.pop_back();
                }
            }
        }
        return;
    }

   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for (auto word : words) {
            t.insert(word);
        }
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        string word = "";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int indx = board[i][j] - 'a';
                TrieNode* node = t.getRoot()->children[indx];
                if (node) {
                    visited[i][j] = 1;
                    word.push_back(board[i][j]);
                    dfs(board, i, j, node, word, visited);
                    visited[i][j] = 0;
                    word.pop_back();
                }
            }
        }
        return ans;
    }
};
