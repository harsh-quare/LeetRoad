class Solution {
public:
    const int n = 1000000;
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(n+1, true);
        prime[1] = false;

        for(int p = 2; p*p <= n; p++){
            if(prime[p] == true){
                for(int i = p*p; i <= n; i+=p){
                    prime[i] = false;
                }
            }
        }

        vector<int> ans = {-1, -1};
        int prev = -1;
        int diff = INT_MAX;
        for(int i = left; i <= right; i++){
            if(prime[i] == true){
                if(prev == -1) prev = i;
                else if(i - prev < diff){
                    diff = i - prev;
                    ans = {prev, i};
                    prev = i;
                }
                else{ // got a new number but the pair is not with lesser difference
                    prev = i;
                }
            }
        }

        return ans;
    }
};