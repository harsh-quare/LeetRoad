class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> mp;

        //first window process
        long long runSum = 0;
        for(int i = 0; i < k; i++){
            mp[nums[i]]++;
            runSum += nums[i];
        }

        if(mp.size() == k) ans = max(ans, runSum);
        
        //process remaining windows
        int i = 1, j = k;
        while(j < nums.size()){
            runSum -= nums[i-1];
            runSum += nums[j];

            mp[nums[i-1]]--;
            mp[nums[j]]++;
            if(mp[nums[i-1]] == 0) mp.erase(nums[i-1]);

            if(mp.size() == k) ans = max(ans, runSum);

            i++;
            j++;
        }

        return ans;
    }
};