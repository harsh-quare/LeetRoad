class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();

        vector<int> maxValue(n, 0);
        maxValue[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; --i) {
            maxValue[i] = max(maxValue[i + 1], events[i][2]);
        }

        int result = 0;

        for(int i = 0; i < n; ++i){
            int currValue = events[i][2];
            result = max(result, currValue);

            int low = i + 1, high = n - 1, nextEvent = -1;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(events[mid][0] > events[i][1]){
                    nextEvent = mid;
                    high = mid - 1;
                } 
                else{
                    low = mid + 1;
                }
            }

            if(nextEvent != -1){
                result = max(result, currValue + maxValue[nextEvent]);
            }
        }

        return result;
    }
};