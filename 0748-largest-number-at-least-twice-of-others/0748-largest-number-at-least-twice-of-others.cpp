class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = nums[0];
        int second_largest = INT_MIN;
        int id_largest = 0;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] >= largest){
                second_largest = largest;
                largest = nums[i];
                id_largest = i;
            }
            else if(nums[i] >= second_largest){
                second_largest = nums[i];
            }
        }

        if(second_largest * 2 <= largest){
            return id_largest;
        }
        else return -1;
    }
};