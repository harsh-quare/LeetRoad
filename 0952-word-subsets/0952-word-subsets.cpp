class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int maxFreq[26] = {0};
        for(string &word : words2){
            int freq[26] = {0};
            for(char c : word){
                freq[c - 'a']++;
            }
            for(int i = 0; i < 26; ++i){
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        vector<string> res;

        for(string &word : words1){
            int freq[26] = {0};
            for(char c : word){
                freq[c - 'a']++;
            }

            bool valid = true;
            for(int i = 0; i < 26; ++i){
                if(freq[i] < maxFreq[i]){
                    valid = false;
                    break;
                }
            }

            if(valid) res.push_back(word);
        }

        return res;
    }
};