class Solution {
public:
    int brokenCalc(int startValue, int target) {
        // start from target and go to start, bcz while multiplying we don't know where will our number end up
        // but we can know when we divide, its even or odd

        // Now the valid operations are: val /= 2 and val += 1

        int ops = 0;

        while(target > startValue){
            if(target % 2 != 0){
                target += 1;
                ops++;
            }
            target /= 2;
            ops++;
        }

        return ops + (startValue - target);
    }
};