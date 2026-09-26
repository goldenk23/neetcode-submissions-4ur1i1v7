class TrieNode {
   public:
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
class Trie {
   public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int indx = c - 'a';
            if (!node->children[indx]) {
                node->children[indx] = new TrieNode();
            }
            {
                node = node->children[indx];
            }
        }
        node->isEndOfWord = true;
    }
};
class Solution {
    vector<string> ans;
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& board, int x, int y, string& word, vector<vector<int>>& visited,
             TrieNode*& node) {
        if (node->isEndOfWord) {
            ans.push_back(word);
            node->isEndOfWord = false;
        }
        for (auto it : dir) {
            int new_x = x + it.first;
            int new_y = y + it.second;
            if (0 <= new_x && new_x < board.size() && 0 <= new_y && new_y < board[0].size() &&
                !visited[new_x][new_y]) {
                int indx = board[new_x][new_y] - 'a';
                if (node->children[indx]) {
                    visited[new_x][new_y] = 1;
                    word += board[new_x][new_y];
                    TrieNode* prev = node;
                    node = node->children[indx];
                    dfs(board, new_x, new_y, word, visited, node);
                    visited[new_x][new_y] = 0;
                    word.pop_back();
                    node = prev;
                }
            }
        }
    }

   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        Trie t;
        for (auto word : words) {
            t.insert(word);
        }
        TrieNode* root = t.root;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                TrieNode* node = root;
                int indx = board[i][j] - 'a';
                if (node->children[indx]) {
                    node = node->children[indx];
                    visited[i][j] = 1;
                    string s = "";
                    s += board[i][j];
                    dfs(board, i, j, s, visited, node);
                    visited[i][j] = 0;
                }
            }
        }
        return ans;
    }
};
