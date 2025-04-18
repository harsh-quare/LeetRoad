class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string prev = "1";
        
        for(int i = 2; i <= n; i++){

            string cur = "";
            int cnt = 1;
            char ele = prev[0];
            for(int j = 1; j < prev.size(); j++){
                if(prev[j] == ele){
                    cnt++;
                }
                else{
                    cur += to_string(cnt) + ele;
                    ele = prev[j];
                    cnt = 1;
                }
            }

            // processing last sequence of the string
            cur += to_string(cnt) + ele;

            prev = cur;
        }

        return prev;
    }
};