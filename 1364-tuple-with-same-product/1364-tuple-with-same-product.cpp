class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        
        // generate all products
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int prod = nums[i] * nums[j];
                mp[prod]++;
            }
        }

        int ans = 0;
        for(auto& [prod, freq]: mp){
            if(freq > 1 ){
                ans += (freq * (freq - 1))/2 * 8;
            }
        }

        return ans;
    }
};