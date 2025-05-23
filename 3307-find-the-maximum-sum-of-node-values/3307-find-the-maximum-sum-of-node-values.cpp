class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();

        // The thing to notice here is, we can xor any two nodes in the graph
        // means, xor can be propagated between any two nodes, bcz they are connected in the same component
        // we just try to maximize sum by xoring only those nodes, which are incremented after xoring
        // and if those nodes are in pair of even nodes(even no. of such nodes), then we don't need to do anything extra
        // but if we have such nodes odd number of times, means we have to either do one extra xor operation, which will reduce it's paired number (we will minimize it), or else we will not do one extra xor operation, which will remove the effect of that one incrementing node's extra contribution (which we will again minimize), bcz we want to leave the least one

        long long ans = 0;
        int cnt = 0;
        int minNuksan = INT_MAX;

        for(int& num: nums){
            // we add maximum value for each node, (num^k) or (num) whichever is greater
            if((num ^ k) > num){
                cnt++;
                ans += (num ^ k);
            }
            else{
                ans += num;
            }

            minNuksan = min(minNuksan, abs((num^k) - num));
        }

        if(cnt % 2 == 0) return ans;

        return ans - minNuksan;
    }
};