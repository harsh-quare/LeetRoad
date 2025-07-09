class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> breaks(1, startTime[0]);
        for(int i = 1; i < n; i++){
            int curBreak = startTime[i] - endTime[i-1];
            breaks.push_back(curBreak);  // we need to consider all the breaks, even if it's 0, bcz we are merging consecutive breaks together
        }
        // final wala break
        breaks.push_back(eventTime - endTime[n-1]);

        // sliding window of (k+1) size
        int ans = 0;
        int curLen = 0;
        for(int i = 0; i < breaks.size(); i++){
            curLen += breaks[i] - ((i >= k+1) ? breaks[i-(k+1)] : 0);
            ans = max(ans, curLen);
        }

        return ans;
    }
};
