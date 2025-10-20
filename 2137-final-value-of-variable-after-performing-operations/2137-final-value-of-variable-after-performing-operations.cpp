class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(string& ops: operations){
            if(ops[0] == 'X'){
                if(ops[2] == '-') ans--;
                else ans++;
            }
            else if(ops[2] == 'X'){
                if(ops[0] == '-') ans--;
                else ans++;
            }
        }

        return ans;
    }
};