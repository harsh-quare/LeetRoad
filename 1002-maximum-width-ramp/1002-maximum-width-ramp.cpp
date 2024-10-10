class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n= nums.size();

        vector<int> maxToRight(n);
        maxToRight[n-1] = nums[n-1];
        // storing values in decreasing order in stack
        for(int i = n-2; i >= 0; i--){
            maxToRight[i] = max(maxToRight[i+1], nums[i]);
        }

        int i = 0; 
        int j = 0;  //maxToRight array me traverse
        int ans = 0; 
        while(j < n){  //j ek baar khatam ho gya to hame or better answer nahi mil payega
            while(nums[i] > maxToRight[j]){
                i++;
            }
            ans = max(ans, j-i);
            j++;
        }

        return ans;
    }
};