class TrieNode{
public:
    TrieNode* child[26];  //trieNode* data type ka array child jiska size = 26
    TrieNode(){  //constructor: node ke 26 children, and sab children initially null h
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
};

class Trie{
public:
    TrieNode* root; //trie create krni h, to pahle ek rootnode bana di trienode type ki
    Trie(){
        root = new TrieNode();  //initialise kr do iss root node ko
    }

    void insert(string word){
        TrieNode* temp = root;  //pointer
        for(char c: word){
            int id = c-'a';
            if(temp->child[id] == NULL){
                temp->child[id] = new TrieNode();
            }
            temp = temp->child[id];
        }
    }

    int solve(int id, string& target, vector<int>& dp){
        if(id == target.size()) return 0;

        TrieNode* temp = root;

        if(dp[id] != -1) return dp[id];

        int ans = 1e6;
        for(int i= id; i < target.size(); i++){
            char ch = target[i];
            int indx = ch-'a';
            if(temp->child[indx] == NULL) break;

            ans = min(ans, 1 + solve(i+1, target, dp));
            temp = temp->child[indx];
        }   

        return dp[id] = ans;     
    }
};
class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        Trie t;
        for(auto w: words){
            t.insert(w);
        }
        
        int n = target.size();
        vector<int> dp(n, -1);

        int ans= t.solve(0, target, dp);

        if(ans >= 1e6) return -1;
        return ans;
    }
};