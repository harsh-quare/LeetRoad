class Solution {
public:
    bool checkPowersOfThree(int n) {
        // Divide by 3 krte jao
        // agar kahi pe bhi remainder 2 aa rha h, then return false, qki ham kisi bhi condn me power of 3 wale koi value 
        // ko remainder 2 wali nhi bana skte
        // Only remainder 0 and 1 wale possible h: 0 when completely divisible by 3, and 1 when 3^0 ka koi positive coeff h

        while(n){
            if(n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};