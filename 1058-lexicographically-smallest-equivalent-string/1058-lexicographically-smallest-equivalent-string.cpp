class Solution {
public:
    char dfsFindMinChar(unordered_map<char, vector<char>>& adj, char ch, vector<int>& vis){
        vis[ch-'a'] = 1;

        char minChar = ch;
        for(auto& it: adj[ch]){
            if(!vis[it-'a']){
                minChar = min(minChar, dfsFindMinChar(adj, it, vis));
            }
        }

        return minChar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();

        unordered_map<char, vector<char>> adj;
        for(int i = 0; i < n; i++){
            char u = s1[i];
            char v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string ans;
        for(int i = 0; i < baseStr.size(); i++){
            char ch = baseStr[i];

            vector<int> vis(26, 0);
            char minChar = dfsFindMinChar(adj, ch, vis);

            ans.push_back(minChar);
        }

        return ans;
    }
};