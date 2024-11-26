class Solution {
public:
    int gcd(int a, int b){
        if(a == 0) return b;

        return gcd(b%a, a);
    }
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] % k != 0) continue;

            for(int j = i; j < n; j++){

                int res = nums[i];
                for(int k = i+1; k <= j; k++){
                    res = gcd(nums[k], res);
                }

                if(res == k) cnt++;
            }
        }

        return cnt;
    }
};