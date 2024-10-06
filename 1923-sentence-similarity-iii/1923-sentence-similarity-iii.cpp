class Solution {
public:
    vector<string> splitWords(const string& sentence) {
        stringstream ss(sentence);
        string word;
        vector<string> words;
        
        while(ss >> word){
            words.push_back(word);
        }
        return words;
    }
    
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // agar chhoti wali string beech me h, means no matching prefix or suffix for it in the longer string, to false
        
        if(sentence1.size() < sentence2.size()){
            swap(sentence1, sentence2);
        }
        
        vector<string> words1 = splitWords(sentence1);
        vector<string> words2 = splitWords(sentence2);
        
        int n = words1.size();
        int m = words2.size();
        
        int lcp = 0;
        while(lcp < m && words1[lcp] == words2[lcp]){
            lcp++;
        }
        
        int lcs = 0;
        while(lcs < m && words1[n - 1 - lcs] == words2[m - 1 - lcs]){
            lcs++;
        }
        
        //checking if the entire shorter sentence is matched in either prefix or suffix
        if(lcp + lcs >= m){
            return true;
        }
        
        return false;
    }
};