class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        sort(queries.begin(), queries.end());

        priority_queue<int> mh; // stroing the furthest point we can reach from each index
        priority_queue<int, vector<int>, greater<int>> pastQs;  // to keep track of past used queries, and min heap bcz we need to know which smallest ones are there, to compare it with current and then remove smaller ones

        int j = 0;  // points to queries
        int usedQs = 0;

        for(int i = 0; i < n; i++){
            while(j < q && queries[j][0] == i){  // same starting point
                mh.push(queries[j][1]);  // store their ending points, furthest will be on top
                j++;
            }

            nums[i] -= pastQs.size();  // first checking if we can impact current i with any past query used

            while(nums[i] > 0 && !mh.empty() && mh.top() >= i){  // this query can impact current index
                int end = mh.top();
                mh.pop();  // use it
                pastQs.push(end);  // send it to past used
                usedQs++;
                nums[i] -= 1;  // reduce by 1, as it's > 0 currently
            }

            if(nums[i] > 0) return -1;  // if it is still not zero, it can't be done

            while(!pastQs.empty() && pastQs.top() <= i){
                pastQs.pop();
            }
        }

        return q - usedQs;
    }
};