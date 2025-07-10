class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> breaks(1, startTime[0]);
        for(int i = 1; i < n; i++){
            breaks.push_back(startTime[i] - endTime[i-1]);
        }
        breaks.push_back(eventTime - endTime[n-1]); // last break

        vector<int> largestRight(breaks.size(), 0);  // suffixMax
        for(int i = breaks.size() - 2; i >= 0; i--){
            largestRight[i] = max(largestRight[i+1], breaks[i+1]);
        }

        vector<int> largestLeft(breaks.size(), 0);  // prefixMax
        for(int i = 2; i < breaks.size(); i++){
            largestLeft[i] = max(largestLeft[i-1], breaks[i-2]);
        }

        int maxFree = 0;
        for(int i = 1; i < breaks.size(); i++){
            int eventDuration = endTime[i-1] - startTime[i-1]; // event on left, for current break
            if(eventDuration <= max(largestLeft[i], largestRight[i])){
                maxFree = max(maxFree, breaks[i-1] + breaks[i] + eventDuration);
            }

            maxFree = max(maxFree, breaks[i-1] + breaks[i]);
        }

        return maxFree;
    }
};