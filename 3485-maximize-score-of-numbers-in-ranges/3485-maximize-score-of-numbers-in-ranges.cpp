class Solution {
public:
    bool isOkay(int diff, vector<int>& start, int d){
        int n = start.size();
        long long prev = start[0];

        for(int i = 1; i<n; i++){
            long long next = max((long long)start[i], prev + diff);
            if(next > start[i] + d) return false;
            prev = next;
        }

        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        //maximize the minimum
        //binarysearch
        
        sort(start.begin(), start.end());
        int n = start.size();
        int low = 0;
        int high = (start[n-1]+d) - start[0];
        int ans = -1;

        while(low <= high){
            // int mid = low + (high-low)/2;
            long long mid = low + (high-low)/2;
            
            if(isOkay(mid, start, d)){
                ans = mid;
                low = mid + 1; //higher diff
            }
            else high = mid-1;
        }

        return ans;
    }
};