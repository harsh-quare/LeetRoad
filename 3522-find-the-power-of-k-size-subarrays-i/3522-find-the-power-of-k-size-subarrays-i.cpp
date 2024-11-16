class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1, -1);

        int consCnt = 1;
        //process first window : (0...k-1)
        for(int i = 1; i < k; i++){
            if(nums[i] == nums[i-1] + 1){
                consCnt++;
            }
            else{
                consCnt = 1;
            }
        }
        if(consCnt >= k){
            ans[0] = nums[k-1];
        }
        
        //process remaining windows by sliding the window
        int i = 1, j = k;
        while(j < n){
            if(nums[j] == nums[j-1] + 1){
                consCnt++;
            }
            else{
                consCnt = 1; //reset the consCnt
            }

            if(consCnt >= k) ans[i] = nums[j];  // agar consecutive window h to window ka last element hi maximum element hoga
            i++;
            j++;
        }
        return ans;
    }
};