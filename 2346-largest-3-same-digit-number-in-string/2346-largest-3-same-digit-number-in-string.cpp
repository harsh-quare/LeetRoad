class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int ans_id = -1;

        for(int i = 1; i < n-1; i++){
            if(num[i-1] == num[i] && num[i] == num[i+1]){
                if(ans_id == -1){
                    ans_id = i;
                }
                else if(num[i] > num[ans_id]){
                    ans_id = i; // update answer mid point
                }
            }
        }

        if(ans_id == -1) return "";
        string ans = num.substr(ans_id-1, 3);
        return ans;
    }
};