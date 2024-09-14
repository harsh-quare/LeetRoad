class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // int maxEle = nums[0];
        // int maxLen = 1;
        // int curLen = 1;

        // for(int i = 1; i<nums.size(); i++){
        //     if(nums[i] > maxEle){
        //         //agar ek greater element mil gya, to purana wale ka contribution matter nhi krta isliye maxLen ko update nhi krenge
        //         //maxLen = max(maxLen, curLen);
        //         curLen = 1;
        //         maxEle = nums[i];
        //         // cout << "i" << endl;
        //     }
        //     else if(nums[i] == maxEle){
        //         curLen++;
        //         // cout << "ei" << endl;
        //     }
        //     else{
        //         maxLen = max(maxLen, curLen);
        //         curLen = 1;
        //         // cout << "e" << endl;
        //     }
        // }

        // maxLen = max(maxLen, curLen);

        // return maxLen;

        int maxi = *max_element(nums.begin(), nums.end());
        cout << maxi << endl;
        int maxLen = 0;
        int curLen = 0;
        for(int i = 0; i<nums.size(); i++){
            if(maxi == nums[i]){
                curLen++;
            }
            else{
                maxLen = max(maxLen, curLen);
                curLen = 0;
            }
        }

        maxLen = max(maxLen, curLen); //for last subarray

        return maxLen;
    }
};