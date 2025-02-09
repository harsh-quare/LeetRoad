class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long totalPairs = (long long)n*(n+1)/2 - n;   // or n*(n-1)/2

        // To count how many bad pairs are there, we can count number of good pairs and then subtract it from totalPairs
        // condn for pair to be good
        // j-i == nums[j]-nums[i]
        // nums[i] - i == nums[j] - j
        // so, count the freq of nums[i]-i, for each i
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++){
            freq[nums[i] - i]++;
        }

        for(auto& it: freq){
            int f = it.second;
            if(f > 1){
                long long totalSuchPairs = (long long)f*(f-1)/2;
                totalPairs -= totalSuchPairs;
            }
        }

        return totalPairs;
    }
};