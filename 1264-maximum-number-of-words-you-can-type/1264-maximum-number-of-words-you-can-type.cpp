class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0;
        vector<int> br(26, 0);
        for(auto& ch: brokenLetters){
            br[ch-'a']++;
        }

        int i = 0;
        while(i < text.size()){
            
            int j = i;
            bool valid = true;
            while(j < text.size() && text[j] != ' '){
                if(br[text[j] - 'a'] != 0) valid = false;
                j++;
            }

            if(valid == true) ans++;

            i = j+1;
        }

        return ans;
    }
};