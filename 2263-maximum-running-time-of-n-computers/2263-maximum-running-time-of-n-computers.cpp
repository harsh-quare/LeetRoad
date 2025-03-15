class Solution {
public:
    bool isValid(long long midMins, vector<int>& b, int n){
        long long targetMins = n * midMins;  // n batteries simultaneously running for 'midMins' number of minutes

        for(int i = 0; i < b.size(); i++){
            targetMins -= min((long long)b[i], (long long)midMins);

            if(targetMins <= 0) return true;
        }

        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {        
        long long low = 0;
        long long high = accumulate(batteries.begin(), batteries.end(), 0LL) / n;

        long long res = 0;

        while(low <= high){
            long long mid = low + (high - low) / 2;  // we need to operate all the computers for 'mid' number of minutes
            
            if(isValid(mid, batteries, n)){
                res = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }

        return res;
    }
};