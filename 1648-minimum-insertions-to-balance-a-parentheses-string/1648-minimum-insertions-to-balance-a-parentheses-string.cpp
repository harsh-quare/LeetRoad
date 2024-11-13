class Solution {
public:
    int minInsertions(string s) {
        int op = 0;
        int cnt = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='('){
                op++;
            }
            else{
                if(s[i+1]==')'){
                    i++;
                }
                else{
                    cnt++;
                }
                if(op==0){
                    cnt++;
                }
                else op--;
            }
        }
        cnt += 2*op;
        return cnt;
    }
};