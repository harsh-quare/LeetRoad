class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.length() < k){
            string x = "";
            for(auto c: s){
                char newCh = (c == 'z') ? 'a' : c+1;
                x = x + newCh;
            }
            s = s + x;
        }

        return s[k-1];
    }
};