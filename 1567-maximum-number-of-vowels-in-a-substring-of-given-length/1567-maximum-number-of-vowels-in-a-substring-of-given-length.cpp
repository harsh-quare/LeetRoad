class Solution {
public:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int ans = 0;
        int curr = 0;

        // process first window of k size
        for(int i = 0; i < k; i++){
            if(isVowel(s[i])) curr++;
        }

        ans = max(ans, curr);

        int i = k;
        while(i < n){
            curr += (isVowel(s[i]));
            curr -= (isVowel(s[i-k]));

            ans = max(ans, curr);
            i++;
        }

        return ans;
    }
};