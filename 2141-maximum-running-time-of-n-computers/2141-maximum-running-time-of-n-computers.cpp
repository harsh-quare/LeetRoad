class Solution {
public:
    //check if it is possible for n computers to run for 'midMins' minutes using the given batteries.
    bool isValid(long long midMins, int n, vector<int>& nums){
        //can you run each battery for midMins???
        // in total you will need n*midMins for that purpose

        long long targetMins = (long long)midMins * n;

        for(int i = 0; i < nums.size(); i++){
            targetMins -= min(midMins, (long long)nums[i]);

            if(targetMins <= 0) return true;  //We have already collected enough total battery time to run all n computers for midMins minutes.
        }

        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        // it might be the case that the number you are calculating optimistically, that everyone can run for this much time, isn't available to one of the computers.
        // The total/n can be large because of one battery being too large and other being too small.
        // so for that, we now know that the low can be 0 and high can be this total / n => use binary search on answer to get the correct fit.
        long long total = 0;
        for(int x: batteries) {
            total += x;
        }

        long long low = 0;
        long long high = total / n;
        long long ans = 0;

        while(low <= high){
            long long mid = low + (high - low) / 2;
            // mid is the number of minutes each battery runs

            if(isValid(mid, n, batteries)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid-1;
        }
        return ans;
    }
};