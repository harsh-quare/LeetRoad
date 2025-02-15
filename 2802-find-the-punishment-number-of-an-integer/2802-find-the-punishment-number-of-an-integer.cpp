class Solution {
public:
    bool isValid(string x, int num, int i, int curSum){
        if(i == x.length()){
            return curSum == num;
        }

        if(curSum > num) return false;

        bool possible = false;

        for(int j = i; j < x.size(); j++){
            string sub = x.substr(i, j-i+1);
            int val = stoi(sub);

            possible = possible || isValid(x, num, j+1, curSum + val);

            if(possible == true) return true;
        }

        return possible;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++){
            string x = to_string(i*i);
            if(isValid(x, i, 0, 0)){
                ans += i*i;
            }
        }

        return ans;
    }
};