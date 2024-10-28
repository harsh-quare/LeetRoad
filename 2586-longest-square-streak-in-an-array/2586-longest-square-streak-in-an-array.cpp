class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxLen = 0;
        for(auto& x: nums){
            long long cur = x;
            int len = 0;
            while(st.find(cur) != st.end()){
                len++;
                
                if(cur*cur > 1e5) break;

                cur = cur*cur;
            }
            maxLen = max(maxLen, len);
        }

        return maxLen < 2 ? -1 : maxLen;
    }
};
// T.C. : For every number, we are running the while loop.
// It might look like O(n^2), but after looking closely, and analyzing
// Take the worst case scenario: 2 -> 4 -> 16 -> 256 -> 65536 -> 4294967296 (out of bound, num <= 1e5)
// So, the while loop will run for at max 5 times, So the worst case T.C. for this problem is O(n*5).  ********