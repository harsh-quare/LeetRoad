class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int oldVal = nums[i];
            int newVal = nums[nums[i]] % n;
            int q = n;

            nums[i] = oldVal + q*(newVal);
        }

        for(int i = 0; i < n; i++){
            nums[i] /= n;
        }

        return nums;
    }
};

// we want to modify it inplace, but if we do, we will lose the real values
// means we want to represrnt each number in such a way that it stores both the old value and the new value
// means something like: a = bq + r => a = 4*100 + 5
// here, a is the umber with which we will represent it
// b it the new number
// q is some qoutient, which can be number >= n, bcz all the numbers are in the range [0,n-1]

// to get the old value from the representing number => a % q => oldVal
// a / q = newVal
