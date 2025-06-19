class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(dividend == INT_MAX && divisor == 1) return INT_MAX;
        if(dividend == INT_MAX && divisor == -1) return INT_MIN + 1;
        int q = 0;
        bool isNeg = false;
        if((dividend < 0 && divisor > 0) ||(dividend > 0 && divisor < 0)) isNeg = true;

        long divd = dividend;
        long divs = divisor;

        divd = (divd < 0) ? (-divd) : divd;
        divs = (divs < 0) ? (-divs) : divs;

        while(divd - divs >= 0){
            divd -= divs;
            if(q >= INT_MAX - 1) return isNeg ? INT_MIN : INT_MAX;
            else q++;
        }

        return isNeg ? -q : q;
    }
};