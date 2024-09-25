class TrieNode{
public:
    TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
};

class WordDictionary{
public:
    TrieNode* root;

    WordDictionary(){
        root = new TrieNode();
    }

    void addWord(string word){
        TrieNode* temp = root;
        for(char c: word){
            int id = c-'a';
            if(temp->child[id] == NULL){
                temp->child[id] = new TrieNode();
            }
            temp = temp->child[id];
        }
        temp->isEnd = true;
    }

    //helper function to search in the Trie with support for '.'
    bool searchInNode(string &word, TrieNode* node, int id){
        //if we've reached the end of the string
        if(id == word.size()){
            return node->isEnd;
        }

        char c = word[id];

        //if the character is a '.', we must check all possible children
        if(c == '.'){
            for(int i = 0; i < 26; i++){
                if(node->child[i] != NULL){
                    //recursively search in each non-null child node
                    if (searchInNode(word, node->child[i], id + 1)) {
                        return true;
                    }
                }
            }
            return false;  //if none match, return false
        } 
        else{
            //if it's a regular character, follow the corresponding child node
            int i = c - 'a';
            if(node->child[i] == NULL){
                return false;  //if the path doesn't exist, return false
            }
            return searchInNode(word, node->child[i], id + 1);
        }
    }

    //function to search for a word in the Trie
    bool search(string word) {
        return searchInNode(word, root, 0);
    }
};


/**
 * Example usage:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord("hello");
 * bool result = obj->search("h.llo");  // returns true
 */
