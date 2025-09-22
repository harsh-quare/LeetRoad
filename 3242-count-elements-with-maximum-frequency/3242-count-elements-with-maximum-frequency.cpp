class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mxFreq = 0;
        int totalFreq = 0;
        for(int x: nums){
            mp[x]++;

            int curFreq = mp[x];
            if(curFreq > mxFreq){
                mxFreq = curFreq;
                totalFreq = curFreq;
            }
            else if(curFreq == mxFreq){
                totalFreq += curFreq;
            }
        }

        return totalFreq;
    }
};