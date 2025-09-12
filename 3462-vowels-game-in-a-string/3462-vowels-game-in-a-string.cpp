class Solution {
public:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    bool doesAliceWin(string s) {
        int vowels = 0;
        for(char c: s){
            if(isVowel(c)) vowels++;
        }

        return vowels > 0;
    }
};