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
        for(char c: word){
            int id = c-'a';
            if(temp->children[id] == NULL){
                temp->children[id] = new TrieNode();
            }
            temp = temp->children[id];
            temp->prefCnt++;  //increment the prefix count for each node
        }
        temp->isEnd = true;
    }
    
    //calculate the score for a word based on its prefix counts in the Trie
    int count(const string& word){
        //count how many strings are there with 'word' as prefix
        TrieNode* temp = root;
        int cnt = 0;
        for(char c: word){
            int id = c-'a';
            if(temp->children[id] == NULL){
                break; //if the prefix doesn't exist, no need to continue
            }
            temp = temp->children[id];
            cnt += temp->prefCnt;
        }
        return cnt;
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

        for(int j = 0; j < n; j++){
            ans[j] = t.count(words[j]);
        }

        return ans;
    }
};