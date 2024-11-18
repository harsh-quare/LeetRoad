class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if(k == 0) return ans;
        else if(k > 0){
            int windowSum = accumulate(code.begin() + 1, code.begin() + k + 1, 0);
            ans[0] = windowSum;
            for(int l = 1, r = k+1; l < n; r++, l++){
                windowSum += code[r % n] - code[l]; //kinda prefix
                ans[l] = windowSum;
            }

            return ans;
        }

        //k < 0
        k = -k;
        int windowSum = accumulate(code.end()-k, code.end(), 0);
        ans[0] = windowSum;
        for(int r = 0, l = n-k; r < n-1; r++, l++){
            windowSum += code[r] - code[l % n];
            ans[r + 1] = windowSum;
        }

        return ans;
    }
};