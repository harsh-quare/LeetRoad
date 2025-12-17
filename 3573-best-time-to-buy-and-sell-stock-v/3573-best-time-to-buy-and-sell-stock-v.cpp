class Solution {
public:
    long long solve(int id, int transType, vector<int>& prices, int k, vector<vector<vector<long long>>>& dp){
        // base case
        if(id >= prices.size() || k == 0){
            if(transType == 0) return 0;
            else return LLONG_MIN/2;  // invalidate this path
        }

        if(dp[id][transType][k] != -1) return dp[id][transType][k];
        
        // option-1: skip
        long long ans = solve(id+1, transType, prices, k, dp);

        // option-2: Buy
        if(transType == 0){   
            // no active tranasction => Begin Normal transaction
            ans = max(ans, -prices[id] + solve(id + 1, 1, prices, k, dp));
            // no active tranasction => Begin Short selling transaction
            ans = max(ans, prices[id] + solve(id + 1, 2, prices, k, dp));
        }
        else if(transType == 2){   // active transaction => Short selling transaction => buy and complete the transaction
            ans = max(ans, -prices[id] + solve(id + 1, 0, prices, k-1, dp));
        }

        // option-3: Sell
        // if(transType == 0){   // no active tranasction => Begin Short selling transaction
        //     ans = max(ans, prices[id] + solve(id + 1, 2, prices, k, dp));
        // }
        else if(transType == 1){   // active transaction => Normal transaction => Sell and finish the transaction
            ans = max(ans, prices[id] + solve(id + 1, 0, prices, k-1, dp));
        }

        return dp[id][transType][k] = ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(3, vector<long long>(k+1, -1)));
        return solve(0, 0, prices, k, dp);  // index, transType{0: no active, 1: normal tx, 2: short selling txn}
    }
};

// k transaction
// profit = selling price - buying price

// At each index => I have 3 options

// 1. Skip it
// 2. Buy -> if no active tranasction => Normal transaction
//           else -> active transaction => Short selling transaction
// 3. Sell -> if no active transaction => Short selling transaction
//            else -> active transaction => Normal transaction

// 1. index
// 2. transOccured
// 3. transType