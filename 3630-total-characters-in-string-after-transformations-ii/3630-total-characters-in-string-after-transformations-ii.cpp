class Solution {
public:
    typedef vector<vector<int>> Mat;
    const int mod = 1e9+7;

    Mat matrixMult(Mat& A, Mat& B){
        Mat C(26, vector<int>(26, 0));
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                for(int k = 0; k < 26; k++){
                    C[i][j] = (C[i][j] + (1LL*A[i][k]*B[k][j]) % mod) % mod;
                }
            }
        }

        return C;
    }

    Mat matrixExponentiation(Mat& T, int t){
        Mat I(26, vector<int>(26, 0));
        for(int i = 0; i < 26; i++){
            I[i][i] = 1;
        }
        if(t == 0){
            return I;
        }

        Mat half = matrixExponentiation(T, t/2);
        Mat res = matrixMult(half, half);

        if(t % 2 == 1){
            res = matrixMult(res, T);
        }

        return res;

        // Iteratively
        // Mat res = I;
        // while(t){
        //     if(t%2 == 1) res = matrixMult(T, res);
        //     T = matrixMult(T, T);
        //     t /= 2;
        // }

        // return res;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // Formula:     final_freq_state = T^t * initial_freq_state

        vector<int> init_freq(26, 0);
        for(char& ch: s){
            init_freq[ch-'a']++;
        }

        // Now form the T matrix
        Mat T(26, vector<int>(26, 0));  // degree of recurrence is 26, bcz any character can be achieved using 26 characters in worst case acc to the nums condition given. SO, size of T becomes 26*26
        for(int i = 0; i < 26; i++){
            for(int add = 1; add <= nums[i]; add++){
                T[(i+add) % 26][i]++;  // 'a' can result in characters upto 'a' + add;  %26 is to wrap around
            }
        }

        // Finding T^t
        Mat trx = matrixExponentiation(T, t);

        vector<int> final_freq(26, 0);
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                final_freq[i] = (final_freq[i] + (1LL*trx[i][j]*init_freq[j] % mod)) % mod;  // matrix multiplication()
            }
        } 

        int ans = 0;
        for(int i = 0; i < 26; i++){
            ans = (ans + final_freq[i]) % mod;
        }

        return ans;
    }
};