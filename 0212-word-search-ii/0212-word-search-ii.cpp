#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (const string& word : words) {
            trie.insert(word);
        }

        unordered_set<string> result;
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, trie.root, "", result);
            }
        }

        return vector<string>(result.begin(), result.end());
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, string currentWord, unordered_set<string>& result) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#') {
            return;
        }

        char ch = board[i][j];
        int index = ch - 'a';
        if (!node->children[index]) {
            return;
        }

        node = node->children[index];
        currentWord += ch;

        if (node->isEnd) {
            result.insert(currentWord);
        }

        // Mark the cell as visited
        board[i][j] = '#';

        // Explore all four directions
        dfs(board, i + 1, j, node, currentWord, result);
        dfs(board, i - 1, j, node, currentWord, result);
        dfs(board, i, j + 1, node, currentWord, result);
        dfs(board, i, j - 1, node, currentWord, result);

        // Backtrack: unmark the cell
        board[i][j] = ch;
    }
};

