class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& meetings){
        vector<vector<int>> mts;
        vector<int> cur = meetings[0];

        for(int i = 1; i < meetings.size(); i++){
            vector<int> nxt = meetings[i];
            if(cur[1] >= nxt[0]){
                cur[1] = max(cur[1], nxt[1]);
            }
            else{
                mts.push_back(cur);
                cur = nxt;
            }
        }
        mts.push_back(cur);  // last interval bhi daal do

        return mts;
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        // step-1: sort the intervals
        // step-2: merge the intervals
        // step-3: count numbers in between intervals

        sort(meetings.begin(), meetings.end());

        vector<vector<int>> mtgs = mergeIntervals(meetings);

        for(int i = 0; i < mtgs.size(); i++){
            cout << mtgs[i][0] << " " << mtgs[i][1] << endl;
        }

        int cnt = 0;
        int m = mtgs.size();
        cnt += mtgs[0][0] - 1;  // initial point se pahle kitne points h
        for(int i = 1; i < m; i++){
            cnt += mtgs[i][0] - mtgs[i-1][1] - 1;  // cur[0] - prev[1] - 1;
        }

        // once all meetings done, count remaining days
        cnt += days - mtgs[m-1][1];

        return cnt;
    }
};