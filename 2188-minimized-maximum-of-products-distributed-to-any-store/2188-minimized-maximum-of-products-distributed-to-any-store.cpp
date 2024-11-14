class Solution {
public:
    bool isPossibleToDistribute(int mid, int shops, vector<int>& q){
        for(auto& prods: q){
            shops -= (prods + mid - 1) / mid;

            if(shops < 0) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());

        int res;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(isPossibleToDistribute(mid, n, quantities)){  //check if you can distribute products into n stores taking max of 'mid' number of products at a time
                res = mid;
                high = mid-1;  //try smaller value, bcz larger values are valid, but not minimum
            }
            else{
                low = mid+1;
            }
        }

        return res;
    }
};