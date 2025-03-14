class Solution {
public:
    bool isValid(string temp_s, string p){
        int i = 0, j = 0;
        while(i < temp_s.length()){
            if(temp_s[i] == p[j]){
                j++;
            }

            if(j == p.length()) return true;
            i++;
        }

        return false;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        // Try different number of removals and, after performing that many removable operations, try to validate that the 'p' is still a subseq of 's' using two pointers, if its valid, low = mid + 1, try more removals.

        int low = 0;
        int high = removable.size(); //try all removals
        int res = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            string temp = s;
            for(int i = 0; i < mid; i++){
                temp[removable[i]] = '_';  //put a placeholder at that index which needs to be removed, and then check
            }

            if(isValid(temp, p)){
                res = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }   
        
        return res;
    }
};