class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> breaks;
        breaks.push_back(startTime[0]);
        for(int i = 1; i < startTime.size(); i++){
            breaks.push_back(startTime[i] - endTime[i-1]);
        }
        breaks.push_back(eventTime - endTime[endTime.size() - 1]);

        int n = breaks.size();
        vector<int> maxRightFree(n, 0);
        vector<int> maxLeftFree(n, 0);

        for(int i = n-2; i >= 0; i--){
            maxRightFree[i] = max(maxRightFree[i+1], breaks[i+1]);
        }

        for(int i = 1; i < n; i++){
            maxLeftFree[i] = max(maxLeftFree[i-1], breaks[i-1]);
        }

        int ans = 0;
        for(int i=1; i < n; i++){
            int curEventTime = endTime[i-1] - startTime[i-1]; // duration of current event

            // case-1: moving completely out
            if(curEventTime <= max(maxLeftFree[i-1], maxRightFree[i])){
                ans = max(ans, breaks[i-1] + curEventTime + breaks[i]);
            }

            // case-2: shift left or right
            ans = max(ans, breaks[i-1] + breaks[i]);
        }

        return ans;
    }
};