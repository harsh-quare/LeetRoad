class Solution {
public:
    deque<string> splitWords(const string& sentence) {
        stringstream ss(sentence);
        string word;
        deque<string> words;
        
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
        
        deque<string> deq1 = splitWords(sentence1);
        deque<string> deq2 = splitWords(sentence2);
        
        while(!deq1.empty() && !deq2.empty() && deq1.front() == deq2.front()){
            deq1.pop_front();
            deq2.pop_front();
        }

        while(!deq1.empty() && !deq2.empty() && deq1.back() == deq2.back()){
            deq1.pop_back();
            deq2.pop_back();
        }
        
        return deq2.empty();
    }
};