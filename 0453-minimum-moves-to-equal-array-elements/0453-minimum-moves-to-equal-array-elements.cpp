class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int mini = INT_MAX;

        for(int i = 0; i < nums.size(); i++) mini = min(mini, nums[i]);
        for(int i = 0; i < nums.size(); i++) ans += (nums[i] - mini);

        return ans;
    }
};

//Visualize it
//Let's say you need to make all value equal, and that equal value is x
//[3,7,5,10,1]
// 3 will be going from 3 -> x => x-3-1 steps
// 7 will be going from 7 -> x => x-7-1 steps
// 5 will be going from 5 -> x => x-5-1 setps
// 10 will be going from 10 -> x => x-10-1 steps
// 1 will be going from 1 -> x => x-1-1 steps

//Now if I sort them up
//[1,3,5,7,10]
//Greedily we will be needin all x steps for 1, bcz 1 is the smallest and it will be the last one to reach the target x
// for 1, x steps
// for 3, x-2 steps
// for 5, x-4 steps
// for 7, x-6 steps
// for 10, x-9 steps

//So if we sum them up, the required steps will be 21, and that's the correct answer