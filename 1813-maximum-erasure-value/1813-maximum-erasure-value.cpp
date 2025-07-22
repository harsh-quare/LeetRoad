class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefSum(n, 0);
        prefSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefSum[i] += (prefSum[i-1] + nums[i]);
        }

        int maxUnqSum = 0;
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        while(j < n){
            mp[nums[j]]++;

            while(i < n && mp.size() < (j-i+1)){   // jb tk mp size curWindowLen se chhota h, tb tk shrink krte jao
                // left se shrink krte jao
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }

            int curUnqSum = (i > 0) ? (prefSum[j] - prefSum[i-1]) : (prefSum[j] - 0);
            // cout << "i: " << i << "; j: " << j << "; curSum: " << curUnqSum << endl;
            maxUnqSum = max(maxUnqSum, curUnqSum);
            j++;
        }
        
        return maxUnqSum;
    }
};