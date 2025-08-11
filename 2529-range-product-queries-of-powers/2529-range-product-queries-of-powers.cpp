class Solution {
public:
    const int mod = 1e9 + 7;

    //function to compute the modular inverse using Fermat's Little Theorem
    int modInverse(int a, int m){
        return power(a, m - 2, m); // a^(m-2) % m
    }

    // Function to compute (base^exp) % mod
    int power(int base, int exp, int m){
        int result = 1;
        while(exp > 0){
            if(exp % 2 == 1){
                result = (1LL * result * base) % m;
            }
            base = (1LL * base * base) % m;
            exp /= 2;
        }
        return result;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int pos = 0;
        while (n){
            if ((n & 1) == 1) powers.push_back(1 << pos);
            pos++;
            n >>= 1;
        }

        //precomputing prefix product array
        int m = powers.size();
        vector<int> prefMul(m);
        prefMul[0] = powers[0];

        for(int i = 1; i < m; i++){
            prefMul[i] = (1LL * prefMul[i - 1] * powers[i]) % mod;
        }

        //processing each query
        vector<int> ans;
        for(auto& q : queries){
            int l = q[0], r = q[1];
            int cur = prefMul[r];

            //if l > 0, we need to divide by prefMul[l-1]
            if(l > 0){
                //using modular inverse to perform division
                cur = (1LL * cur * modInverse(prefMul[l - 1], mod)) % mod;
            }

            ans.push_back(cur);
        }

        return ans;
    }
};
