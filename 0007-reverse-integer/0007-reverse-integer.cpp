class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while(x){
            int dig = x % 10;

            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && dig > 7)) return 0;
            if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && dig < -8)) return 0;

            ans = ans*10 + dig;
            x /= 10;
        }

        return ans;
    }
};

// If temp=rev⋅10+pop causes overflow, then it must be that rev ≥ INTMAX / 10
// If rev > INTMAX / 10, then temp=rev⋅10+pop is guaranteed to overflow.
// If rev == INTMAX, then temp=rev⋅10+pop will overflow if and only if pop > 7