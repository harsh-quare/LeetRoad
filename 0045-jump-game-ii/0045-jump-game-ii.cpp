class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;  //if there's only one element, no jump is needed
        
        int res = 0;  //count of jumps
        int maxReach = nums[0];  //the farthest index we can reach
        int steps = nums[0];  //steps we can take with the current jump
        
        for(int i = 1; i < n; i++){
            //if we have reached the last index, return the result
            if(i == n - 1){
                return res + 1;
            }
            
            //update the farthest we can reach from this point
            maxReach = max(maxReach, i + nums[i]);
            
            //use one step to move forward
            steps--;
            
            // If no more steps left, we must make another jump
            if(steps == 0){
                res++;  //increment jump count
                steps = maxReach - i;  //reset steps to the remaining steps to the farthest reachable index
            }
        }
        
        return res;
    }
};