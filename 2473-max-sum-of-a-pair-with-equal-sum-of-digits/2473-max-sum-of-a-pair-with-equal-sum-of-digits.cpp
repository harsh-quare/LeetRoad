class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        vector<int> mp(82, 0);  // sum of digits -> maximum guy having that sum ; 82, bcz max can be 999999999 => 81 sum

        for(int i = 0; i < n; i++){
            int val = nums[i];
            int sumDig = 0;
            while(val){
                sumDig += val % 10;
                val /= 10;
            }

            if(mp[sumDig] == 0){
                mp[sumDig] = nums[i];
            }
            else{
                // already koi number mila hua h, to ek to answer find krne ka try kro and 
                // dusra update krte time max value save kro

                ans = max(ans, nums[i] + mp[sumDig]);
                mp[sumDig] = max(mp[sumDig], nums[i]);
            }
        }

        return ans;
    }
};