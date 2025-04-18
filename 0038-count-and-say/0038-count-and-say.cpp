class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string prev = "1";
        
        string ans = "";
        for(int i = 2; i <= n; i++){

            string cur = "";
            int j = 0, k = 0;
            while(k < prev.size()){
                if(prev[k] != prev[j]){
                    int len = k - j;
                    char ch = prev[j];

                    cur = cur + to_string(len) + ch;

                    j = k;
                }
                k++;
            }

            // processing last sequence of the string
            int len = k - j;
            char ch = prev[j];

            cur = cur + to_string(len) + ch;

            prev = cur;
            ans = cur;
        }

        return ans;
    }
};