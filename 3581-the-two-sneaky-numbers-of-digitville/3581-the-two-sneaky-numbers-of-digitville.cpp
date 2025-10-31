class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        int actualSize = n-2;

        vector<int> ans;
        vector<int> freq(n-2, 0);
        for(int& x: nums){
            freq[x]++;

            if(freq[x] == 2){
                ans.push_back(x);
            }
        }

        return ans;


    }
};