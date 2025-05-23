class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        long long sum = 0;

        // again the concept is same, we can xor any pair of nodes in the graph.

        vector<int> profit;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            profit.push_back((nums[i] ^ k) - nums[i]);  // positive and negative dono honge
            cout << (nums[i] ^ k) - nums[i] << endl;
        }

        sort(profit.rbegin(), profit.rend());  // all profitable nodes will shift towards start

        int m = profit.size();

        // take nodes pairwise, and see if you can take 
        for(int i = 0; i < m-1; i += 2){
            long long pairSum = profit[i] + profit[i+1];  // we can only xor in pair

            if(pairSum > 0){
                sum += pairSum;
            }
        }

        return sum;
    }
};