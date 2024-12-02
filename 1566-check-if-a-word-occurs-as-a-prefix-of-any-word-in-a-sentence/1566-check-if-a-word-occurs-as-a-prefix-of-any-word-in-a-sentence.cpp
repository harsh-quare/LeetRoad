class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);  //create a stringstream object
        string word;  //variable to hold each word
        int idx = 1;

        //extract words from the sentence
        while(ss >> word){
            //check prefix on the go
            if(word.find(searchWord) == 0) return idx;

            idx++;
        }

        return -1;
    }
};