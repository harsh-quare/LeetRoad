class Solution {
public:
    // bool isPossible(vector<int>& nums, long long k, int mid, int total){
    //     if((long long)(k*mid) > total) return false;
    //     for(int i =0 ;i<nums.size(); i++){
    //         if(nums[i] < mid) return false;  //har pile ko kam se kam mid ke barabar to hona bnta h
    //     }
    //     return true;
    // }

    //Its not that we need to distribute in all candies, and thats why above function is wrong
    //we just want that we have k guys with equal piles across all piles available, You might also miss a candy entirely and divide another into 2-3 equal subpiles to satisfy that answer.
    bool isPossible(vector<int>& nums, long long k, int mid){
        long long cnt = 0;

        for(int p: nums){
            cnt += p/mid;  //jitne divisions possible h, utne le lo, this cnt is counting number of children with mid number of piles

            if(cnt >= k) return true;  //agar number of children wlaready k ho gye to congrats, ham valid distribution kr rhe h
        }

        return cnt >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        long long total = accumulate(candies.begin(), candies.end(), 0LL);

        if(total < k) return 0;

        int ans = 0;

        while(low <= high){
            long long mid = low + (high - low) / 2;

            //kya mai, mid ko max element maanke sab candies me se mid number of piles la skta hu?
            if(isPossible(candies, k, mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return ans;
    }
};