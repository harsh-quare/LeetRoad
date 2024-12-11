class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // each num in nums affects the range num-k to num+k.
        // mark starting of interval with +1 and ending with -1
        //Sweep line algorithm

        int n = nums.size();

        vector<pair<int, int>> events;
        for(int& x: nums){
            events.emplace_back(x - k, 1);  //start of range
            events.emplace_back(x + k + 1, -1);  //end of range
        }

        sort(events.begin(), events.end());

        int active = 0;
        int ans = INT_MIN;

        //sweep line over sorted events
        for(auto [posn, type]: events){
            active += type;
            ans = max(ans, active);
        }

        return ans;
    }
};