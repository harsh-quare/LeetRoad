class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++){
            if(arr.back() != nums[i]) {  // skip same values => part of same valley or hill
                arr.push_back(nums[i]);
            }
        }
        int cnt = 0;
        for(int i = 1; i < arr.size()-1; i++){
            if( (arr[i] < arr[i-1] && arr[i] < arr[i+1]) || 
                (arr[i] > arr[i-1] && arr[i] > arr[i+1])){
                cnt++;
            }
        }
        return cnt;
    }
};