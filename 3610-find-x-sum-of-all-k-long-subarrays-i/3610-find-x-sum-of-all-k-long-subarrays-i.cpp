class Solution {
public:
    int findXsum(map<int, int>& mp, int x){
        priority_queue<pair<int, int>> pq;  // freq, nums
        for(auto it: mp){
            pq.push({it.second, it.first});
        }
        int sum = 0;

        while(x-- && !pq.empty()){
            auto it = pq.top();
            pq.pop();
            int freq = it.first;
  		    // Add all occurrences of this number to the sum
            sum += freq * it.second;
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        map<int, int> mp;
        vector<int> v;
        int l = 0, r = 0;
        while(r < nums.size()){
            mp[nums[r]]++;
            while(l < r && r-l+1 > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            if(r-l+1 == k){
                v.push_back(findXsum(mp, x));
            }
            r++;
        }
        return v;
    }
};