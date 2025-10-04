class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;

        int maxWater = 0;
        while(l <= r){
            int minHt = min(height[l], height[r]);
            int curWater = (r-l) * minHt;
            maxWater = max(maxWater, curWater);

            if(height[l] < height[r]){
                l++;
            }
            else if(height[l] > height[r]){
                r--;
            }
            else{
                l++;
                r--;
            }
        }

        return maxWater;
    }
};