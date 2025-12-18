class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        long long ans = LLONG_MIN;
        long long total = 0;

        vector<long long> pref(n+1, 0);
        vector<long long> prefPrices(n+1, 0);

        for(int i = 0; i < n; i++){
            prefPrices[i+1] = prefPrices[i] + prices[i];
            total += (long long)prices[i] * strategy[i];
            pref[i+1] = total;
            cout << prefPrices[i] << ", ";
        }
        cout << prefPrices[n] << endl;
        ans = max(ans, total);

        for(int i = k-1; i < n; i++){
            long long cur = total - (pref[i+1] - pref[i-k+1]);

            // the sum for last k/2 values in prices
            // op1
            // for(int j = i-k/2 + 1; j <= i; j++){
            //     cur += prices[j] * 1;
            // }

            // op2 => using prefix sum  => entire subarray => [i-k+1, i]  => 1st half is 0 => second half => [i-k/2 + 1, i]
            cur += (prefPrices[i+1] - prefPrices[i-k/2+1]);  // 1-based indexing

            ans = max(ans, cur);
        }

        return ans;
    }
};
