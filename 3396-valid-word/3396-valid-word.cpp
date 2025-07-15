class Solution {
public:
    bool checkVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    
    bool isValid(string word) {
        int n = word.length();
        if(n < 3) return false;

        bool isVowel = false, isCons = false;
        // bool small = false, cap = false, dig = false;

        for(char c: word){
            if(c >= '0' && c <= '9') continue;  // koi dikkat nhi h, check krte rho
            else if(c >= 'a' && c <= 'z') {
                if(checkVowel(c)) isVowel = true;
                else isCons = true;
            }
            else if(c >= 'A' && c <= 'Z') {
                if(checkVowel(c)) isVowel = true;
                else isCons = true;
            }
            else return false;
        }

        if(isVowel == true && isCons == true) return true;
        else return false;
    }
};