class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // for(auto& x: nums){
        //     cout << x << " ";
        // }
        // cout << endl;

        if(k < nums[0]){
            return (long long)k*(k+1)/2;
        }

        //pahle nums[0] se saare numbers le lo, agar k ho gye to balle balle or otherwise saare le lo & aage ka dekhenge
        // k > nums[0]: pahle jitne nums[0] se chhote mil skte h, le lo
        k -= nums[0] - 1;
        int val = nums[0] - 1;
        ans += (long long)val*(val+1)/2;

        // cout << k << " " << ans << endl;

        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1] + 1 || nums[i] == nums[i-1]) continue;
            else{
                int start = nums[i-1];
                int upto = nums[i-1] + min(k, nums[i]-nums[i-1]-1);

                // cout << "start: " << start << ", " << "upto: " << upto << endl;

                long long s1 = (long long)start*(start + 1)/2;
                long long s2 = (long long)upto*(upto + 1)/2;

                ans += (s2 - s1);
                k -= min(k, nums[i]-nums[i-1]-1);
                if(k == 0) break;
            }
            
        }

        // cout << k << " " << ans << endl;

        if(k > 0){
            int start = nums[n-1];
            int end = start + k;

            // cout << start << " " << end << endl;

            long long s1 = (long long)start*(start + 1)/2;
            long long s2 = (long long)end*(end + 1)/2;

            ans += (s2-s1);
        }

        return ans;
    }
};