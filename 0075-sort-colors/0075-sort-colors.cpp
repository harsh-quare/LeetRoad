class Solution {
public:
    void sortColors(vector<int>& nums) {
        // dutch national flag algorithm
        
        int n = nums.size();
        int low = 0, high = n-1;

        int i = 0;
        while(i <= high){
            cout << nums[i] << endl;
            if(nums[i] == 0){
                swap(nums[i], nums[low]);
                low++;
                i++;
            }
            else if(nums[i] == 2){
                swap(nums[i], nums[high]);
                high--;
            }
            else if(nums[i] == 1){
                i++;
            }
        }
    }
};