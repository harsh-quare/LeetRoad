class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<int>> getTransformationMatrix(const vector<int>& nums){
        vector<vector<int>> T(26, vector<int>(26, 0));
        for(int i = 0; i < nums.size(); i++){
            for(int step = 1; step <= nums[i]; step++){
                T[i][(i + step) % 26]++;
            }
        }

        return T;
    }

    vector<vector<int>> matrixMult(vector<vector<int>>& A, vector<vector<int>>& B){
        int sz = A.size();
        vector<vector<int>> C(26, vector<int>(26, 0));
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                for(int k = 0; k < 26; k++){
                    C[i][j] = (C[i][j] + (1LL*A[i][k]*B[k][j]) % mod) % mod;
                }
            }
        }

        return C;
    }

    vector<vector<int>> matrixExponentiation(vector<vector<int>>& M, int t){
        vector<vector<int>> I(26, vector<int>(26, 0));  // Identity matrix of size 26
        for(int i = 0; i < 26; i++){
            I[i][i] = 1;
        }

        vector<vector<int>> res = I;
        while(t){
            if(t % 2 == 1){
                res = matrixMult(M, res);
            }
            M = matrixMult(M, M);
            t /= 2;
        }

        return res;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<int>> trans_matrix = getTransformationMatrix(nums);
        vector<vector<int>> powered_trans_matrix = matrixExponentiation(trans_matrix, t);  // M^t => t is the degree of recurrence relation
        vector<int> inpt(26, 0);
        vector<int> opt(26, 0);

        for(char c: s){
            inpt[c-'a']++;
        }

        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                opt[j] = (opt[j] + 1LL*inpt[i]*powered_trans_matrix[i][j] % mod) % mod;
            }
        }

        int ans = 0;
        for(int x: opt){
            ans = (ans + x) % mod;
        }

        return ans;
    }
};