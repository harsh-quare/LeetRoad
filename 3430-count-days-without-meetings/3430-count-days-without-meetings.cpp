class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // step-1: sort the intervals
        // step-2: count numbers in between intervals

        sort(meetings.begin(), meetings.end());
        int n = meetings.size();

        int cnt = 0;
        cnt += meetings[0][0] - 1;
        int prevEnd = meetings[0][1];
        for(int i = 1; i < n; i++){
            vector<int> cur = meetings[i];

            if(cur[0] > prevEnd){
                cnt += cur[0] - prevEnd - 1;
            }

            prevEnd = max(prevEnd, cur[1]);
        }

        cnt += days - prevEnd;

        return cnt;
    }
};