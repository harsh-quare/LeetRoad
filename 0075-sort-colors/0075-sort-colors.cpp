class Solution {
public:
    void sortColors(vector<int>& nums) {
        // dutch national flag algorithm
        // [0,l-1] => 0  => I'll be putting 0's at 'l' pointer
        // [l, mid-1] => 1
        // [mid, r-1] => {0,1,2} => unsorted part
        // [r, n-1] => 2
        
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