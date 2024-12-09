class Solution {
public:
    int n;
    int dp[100001][3];

    //upper_bound
    int binarySearch(vector<vector<int>>& eve, int end){
        int l = 0, r = n-1;
        int res = n;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(eve[mid][0] > end){
                res = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return res;
    }

    int solve(int id, vector<vector<int>>& eve, int cnt){
        if(id >= n || cnt == 2){  //ya to 2 events le liye, ya fir out of bound chale gye, ab to 0 milega
            return 0;  
        }

        if(dp[id][cnt] != -1) return dp[id][cnt];

        // take current id
        int nextValidIdx = binarySearch(eve, eve[id][1]);  //upper_bound on the startTime which is just greater than current endTime
        int take = eve[id][2] + solve(nextValidIdx, eve, cnt + 1);

        //skip
        int notTake = solve(id + 1, eve, cnt);

        return dp[id][cnt] = max(take, notTake);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), events.end());  //so that it's easier to find next min valid idx for each event

        int cnt = 0;
        memset(dp, -1, sizeof(dp));
        return solve(0, events, cnt);
    }
};