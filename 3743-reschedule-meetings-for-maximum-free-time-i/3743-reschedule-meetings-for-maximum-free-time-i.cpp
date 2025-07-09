class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> breaks;
        breaks.push_back(startTime[0]);

        for(int i = 1; i < n; i++){
            int curBreak = startTime[i] - endTime[i-1];
            breaks.push_back(curBreak);  // we need to consider all the breaks, even if it's 0
        }
        // final wala break
        breaks.push_back(eventTime - endTime[n-1]);

        // sliding window of (k+1) size
        int ans = 0;
        int curLen = 0;
        for(int i = 0; i < min(k+1, (int)breaks.size()); i++){ // first k+1 size window processed
            curLen += breaks[i];
        }
        ans = max(ans, curLen);

        if(breaks.size() <= k) return ans;

        int i = k+1;
        while(i < breaks.size()){
            curLen += breaks[i];
            curLen -= breaks[i-k-1];
            ans = max(ans, curLen);
            i++;
        }

        return ans;
    }
};

// we can always get at max (k+1) breaks together
// so we just calculate all the breaks length and find out the max length in (k+1) window size of the breaks array