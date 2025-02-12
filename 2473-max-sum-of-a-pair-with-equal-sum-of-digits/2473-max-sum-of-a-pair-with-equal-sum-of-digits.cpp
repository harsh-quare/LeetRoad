class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        unordered_map<int, int> mp;  // sum of digits -> maximum guy having that sum

        for(int i = 0; i < n; i++){
            int val = nums[i];
            int sumDig = 0;
            while(val){
                sumDig += val % 10;
                val /= 10;
            }

            if(mp.find(sumDig) == mp.end()){
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