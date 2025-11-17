class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int dist = -1;
        for(int x: nums){
            if(x == 0){
                if(dist == -1) continue;
                else dist++;
            }
            else{
                if(dist == -1 || dist >= k){
                    dist = 0;
                }
                else return false;
            }
        }

        return true;
    }
};