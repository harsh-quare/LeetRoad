class Solution {
public:
    string solve(int n){
        if(n == 1){
            return "1";
        }

        string prev = solve(n-1);

        // Now process this string to get the current one
        string ans = "";
        int i = 0, j = 0;
        while(j < prev.size()){
            if(prev[j] != prev[i]){
                // different character encountered
                //find out the length of latest consecutive stream of characters, & add in ans
                int len = j - i;
                char ch = prev[i];

                ans = ans + to_string(len) + ch;

                // move i pointer to the start of this new string
                i = j;
            }
            j++;
        }

        // processing the last sequence
        int len = j - i;
        char ch = prev[i];

        ans = ans + to_string(len) + ch;
        
        return ans;
    }
    string countAndSay(int n) {
        return solve(n);
    }
};