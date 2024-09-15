class TrieNode{
public:
    TrieNode* child[26];
    TrieNode(){
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* temp = root;
        for(char c: word){
            int id = c - 'a';
            if(temp->child[id] == NULL){
                temp->child[id] = new TrieNode();
            }
            temp = temp->child[id];
        }
    }

    int solve(int id, string &tar, vector<int>& dp, int n){
        if(id == n) return 0;

        TrieNode* node = root;
        if(dp[id] != -1) return dp[id];

        int ans = 1e6;
        for(int i = id; i < n; i++){
            char ch = tar[i];
            int index = ch-'a';
            if(node->child[index] == NULL) break;

            ans = min(ans, 1 + solve(i+1, tar, dp, n));
            node = node->child[index];
        }

        return dp[id] = ans;
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        Trie t;
        for(string w: words){
            t.insert(w);
        }

        int n = target.size();
        vector<int> dp(n, -1);
        int ans = t.solve(0, target, dp, n);
        if(ans >= 1e6) return -1;
        return ans;
    }
};