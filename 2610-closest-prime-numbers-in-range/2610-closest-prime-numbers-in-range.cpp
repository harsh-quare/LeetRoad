class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(right+1, true);
        prime[1] = false;

        for(int p = 2; p*p <= right; p++){
            if(prime[p] == true){
                for(int i = p*p; i <= right; i+=p){
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