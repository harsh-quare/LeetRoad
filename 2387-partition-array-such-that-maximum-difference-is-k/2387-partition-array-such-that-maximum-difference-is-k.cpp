class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // we don't have to create those subseqs, we just need to know about how many subseqs we would need, based on the condn that max and min element diff can't be more than k
        // we are just grouping the elements which fall between its maxi and mini element and maxi-mini <= k

        // so what we do is, sort the array, and then count how many would we need
        sort(nums.begin(), nums.end());
        int cnt = 1, i = 0;
        int n = nums.size();
        int mx = nums[i], mn = nums[i];

        while(i < n){
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);

            if(mx - mn <= k){
                i++;
            }
            else{
                // first guy, jo ab current grp ka part nhi ban skta
                // isi ko min, and isi ko max bana do
                mx = nums[i];
                mn = nums[i];
                cnt++;
            }
        }

        return cnt;
    }
};