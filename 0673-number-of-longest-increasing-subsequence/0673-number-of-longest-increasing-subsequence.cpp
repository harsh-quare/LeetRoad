class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> lis(n, 1);
        vector<int> ways(n, 1);

        int maxLen = 1;

        for(int i = 0; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                if(nums[j] < nums[i]){
                    if(lis[j] + 1 > lis[i]){
                        lis[i] = lis[j] + 1;
                        ways[i] = ways[j];
                    }
                    else if(lis[i] == lis[j] + 1){
                        //we found another subseq with same length as the one ending at i
                        ways[i] += ways[j];  //we have multiple ways to form subseq with same length
                    }
                }
            }
            maxLen = max(maxLen, lis[i]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(lis[i] == maxLen){
                ans += ways[i];
            }
        }

        return ans;
    }
};