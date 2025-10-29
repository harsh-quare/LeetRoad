class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        
        int nines = sum / 9;
        sum = sum % 9;

        if(num == nines && sum != 0) return "";
        if(nines > num) return "";

        while(ans.length() < num && nines--){
            ans.push_back('9');
        }

        if(sum != 0) ans = ans + to_string(sum);

        while(ans.length() < num){
            ans.push_back('0');
        }

        return ans;
    }
};