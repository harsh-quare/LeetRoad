class Solution {
public:
    bool isOkay(vector<int>& nums, long long mid, int tot){
        long long trips= 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            trips += mid / nums[i];

            if(trips >= tot) return true;
        }

        return trips >= tot;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long low = 0;
        long long high = 1e14;

        long long res = -1;

        while(low <= high){
            long long mid = (high + low) / 2;

            if(isOkay(time, mid, totalTrips)){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return res;
    }
};