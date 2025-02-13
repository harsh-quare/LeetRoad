class Solution {
public:
    int brokenCalc(int startValue, int target) {
        // start from target and go to start, bcz while multiplying we don't know where will our number end up
        // but we can know when we divide, its even or odd

        // Now the valid operations are: val /= 2 and val += 1

        int ans = 0;
        while(target > startValue){
            if(target % 2 == 1){
                target += 1;
                ans++;
            }
            while(target % 2 == 0 && target > startValue){
                target /= 2;
                ans++;
            }

            if(target == startValue) return ans;
        }

        // Now target <= startValue
        ans += (startValue - target);

        return ans;
    }
};