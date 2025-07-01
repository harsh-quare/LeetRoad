class Solution {
public:
    int possibleStringCount(string word) {
        // the answer is 1(original string itself) + x(how many continouously repeated characters are there in original string, each one might be typed unintentionally)
        int ans = 1;
        int curRep = 0;
        for(int i = 1; i < word.size(); i++){
            if(word[i] != word[i-1]){
                ans += curRep;
                curRep = 0;
            }
            else{
                curRep++;
            }
        }

        ans += curRep;  // last sprint

        return ans;
    }
};