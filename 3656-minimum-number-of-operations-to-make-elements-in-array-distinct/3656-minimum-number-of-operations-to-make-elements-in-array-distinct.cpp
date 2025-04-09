class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> st;
        // while traversing from back of the array, the first time when we encounter a guy repeating, we need to remove all the triplets behind this => index / 3 + 1

        for(int i = nums.size() - 1; i >= 0; i--){
            if(st.find(nums[i]) != st.end()){
                return i/3 + 1;
            }
            st.insert(nums[i]);
        }

        return 0;
    }
};