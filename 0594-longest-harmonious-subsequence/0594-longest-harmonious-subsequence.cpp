class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = 0;
        int i = 0;
        for(int j = 0; j < n; j++){
            if(nums[j] - nums[i] == 1){   // agar diff = 1 h, to bs length update krte rho har baar, bs j bdhta rahega
                ans = max(ans, j-i+1);
            }
            // else agar diff > 1 h, to tb tk i ko bdhate rho jb tk ye diff<=1 na ho jaye
            while(nums[j] - nums[i] > 1){
                i++;
            }
            // else diff < 1 h to obv j pointer bdhta rahega only 
        }

        return ans;
    }
};