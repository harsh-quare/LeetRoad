class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n, 0);
        for(auto q: bookings){
            int l = q[0]-1; // convert to 0-indexed
            int r = q[1]-1; // convert to 0-indexed
            int x = q[2];

            diff[l] += x;
            if(r+1 < n) diff[r+1] -= x;
        }

        for(int i = 1; i < n; i++){
            diff[i] += diff[i-1];
        }

        return diff;
    }
};