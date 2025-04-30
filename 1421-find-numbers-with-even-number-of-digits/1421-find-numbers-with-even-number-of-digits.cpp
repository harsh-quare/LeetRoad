class Solution {
public:
    int countDig(int x){
        int cnt = 0;
        while(x){
            x /= 10;
            cnt++;
        }
        return cnt;
    }
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(int x: nums){
            if(countDig(x) % 2 == 0) cnt++;
        }
        return cnt;
    }
};