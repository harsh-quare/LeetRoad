class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;
    int prefCnt;

    TrieNode(){
        isEnd = false;
        prefCnt = 0;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
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
        for(auto c: word){
            int idx = c-'a';
            if(temp->children[idx] == NULL){
                temp->children[idx] = new TrieNode();
            }
            temp = temp->children[idx];
            temp->prefCnt++;
        }
        temp->isEnd = true;
    }

    int getScore(string word){
        int score = 0;
        TrieNode* temp = root;

        for(auto c: word){
            int id= c-'a';
            if(temp->children[id] == NULL){
                break;
            }
            temp = temp->children[id];
            score += temp->prefCnt;
        }

        return score;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int> ans(n);
        Trie t;
        for(auto& s: words){
            t.insert(s);
        }

        for(int i = 0; i<n; i++){
            ans[i] = t.getScore(words[i]);
        }

        return ans;
    }
};