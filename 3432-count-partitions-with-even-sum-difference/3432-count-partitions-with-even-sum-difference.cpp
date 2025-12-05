class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0;
        for(int x: nums) total += x;

        int cnt = 0;
        int pref = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(abs(pref - total + pref) % 2 == 0) cnt++;
        }

        return cnt;
    }
};