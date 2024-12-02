class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);  //create a stringstream object
        string word;  //variable to hold each word
        vector<string> words;

        //extract words from the sentence
        while(ss >> word){
            words.push_back(word);  //add the word to vector
        }

        for(int i = 0; i < words.size(); i++){
            if(words[i][0] != searchWord[0] || words[i].size() < searchWord.size()) continue;
            else if(words[i][0] == searchWord[0]){
                if(words[i].substr(0, searchWord.size()) == searchWord) return i+1;
            }
        }

        return -1;
    }
};