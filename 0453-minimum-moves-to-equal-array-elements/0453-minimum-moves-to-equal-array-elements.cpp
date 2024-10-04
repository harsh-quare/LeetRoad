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
// 3 will be going from 3 -> x => x-3+1 steps
// 7 will be going from 7 -> x => x-7+1 steps
// 5 will be going from 5 -> x => x-5+1 setps
// 10 will be going from 10 -> x => x-10+1 steps
// 1 will be going from 1 -> x => x-1+1 steps

//Now if I sort them up
//[1,3,5,7,10]
//Greedily we will be needin all x steps for 1, bcz 1 is the smallest and it will be the last one to reach the target x
// for 1, x steps
// for 3, x-2 steps
// for 5, x-4 steps
// for 7, x-6 steps
// for 10, x-9 steps

//So if we sum them up, the required steps will be 21, and that's the correct answer

// We have to increment n-1 elements by 1 to make them equal. This is equal to decrementing only 1 element by 1. 
//Since we need to make all the elements equal we can consider he given problem to be equal to decrementing all the elements by 1 in each move until they are equal to the minimum element in the array.
// For example- [5,6,7,8] can be made equal if we decrement number 8, three times and 7, two times and 6 one times. Decrementing 8 by 1 is equal to adding 1 to all the other elements.
// Conclusion - We are just reversing the problem to make it simpler.