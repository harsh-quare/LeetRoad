class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        sort(queries.begin(), queries.end());  //sort queries by starting indices
        priority_queue<int> available;  //max heap for taking the max/furthest guys for each index: end of queries
        priority_queue<int, vector<int>, greater<int>> active;  //min heap for active queries' end indices
        int cnt = 0;   //count of queries successfully used

        int j = 0;  //tracks current query being processed 
        //process each position in nums
        for(int i = 0; i < n; i++){
            // all the queries who are starting from current index, put their ending index in available queue
            while(j < queries.size() && queries[j][0] == i){
                available.push(queries[j][1]);
                j++;
            }

            //adjust the current number by subtracting the count of currently active queries
            nums[i] -= active.size();  //we need to reduce nums[i] by nums[i] times to reduce it to 0
            //so in this step, we reduce it to the active elements count

            //Use candidate queries to fulfill the current position's requirements
            while(nums[i] > 0 && !available.empty() && available.top() >= i){
                cnt++;
                active.push(available.top());
                available.pop();
                nums[i]--;
            }

            if(nums[i] > 0) return -1;  //if the current position can't be zeroed out, return -1

            //remove expired queries from the active/chosen queue
            while(!active.empty() && active.top() == i){
                active.pop();
            }
        }

        return queries.size() - cnt;
    }
};