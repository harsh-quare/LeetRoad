class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mxFreq = 0;
        for(int x: nums){
            mp[x]++;
            mxFreq = max(mxFreq, mp[x]);
        }

        int mxGuys = 0;
        for(auto& [x, f]: mp){
            if(f == mxFreq) mxGuys++;
        }

        return mxGuys * mxFreq;
    }
};