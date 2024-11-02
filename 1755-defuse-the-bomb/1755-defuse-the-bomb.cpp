class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            int sum = 0;

            if(k > 0){       // when k > 0, sum the next k elements
                for(int j = 1; j <= k; j++){
                    sum += code[(i + j) % n];
                }
            }
            else if(k < 0){  // when k < 0, sum the previous abs(k) elements
                for(int j = 1; j <= abs(k); j++){
                    sum += code[(i - j + n) % n];
                }
            }

            ans[i] = sum;
        }

        return ans;
    }
};
