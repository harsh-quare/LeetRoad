class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        bool isNeg = false;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) isNeg = true;

        long divd = abs((long)dividend);
        long divs = abs((long)divisor);

        long q = 0;
        while(divd >= divs){
            int maxPow2 = 0;
            
            while(divd >= (divs << (maxPow2 + 1)) ){   // divd >= divs*2^x
                maxPow2 = maxPow2 + 1;
            }

            divd -= (divs << (maxPow2));
            q += (1 << (maxPow2));
        }

        if(q == (1 << 31) && isNeg == false) return INT_MAX;
        if(q == (1 << 31) && isNeg == true) return INT_MIN;

        return isNeg ? -q : q;
    }
};

// what we did earlier was a naive soln, which just subtracts divisor from dividend until no more operations could be performed. And some part of hard code too
// But now we want to optimize the soln by using concepts from bit manipulation.
// we know that each integer can be represented in the combination of powers of 2 => 7 => 2^2 + 2^1 + 2^0

// and that makes our way easier. Bcz now, what we will do is, we try and subtract the maximum multiple of divisor which is power of 2 => if divd = 22, divs = 3 => that means we can do 7*3 = 21, 7 can be represented in 2^2 + 2^1 + 2^0.
// now one by one we try and subtract maximum power of 2 guy from divd, to reduce the number of operations
// 22 -= 3*2^2 => 10, ans += 2^2 => 4
// 10 -= 3*2^1 => 4, ans += 2^1 => 6
// 4 -= 3*2^0 => 1, ans += 2^0 => 7
// now divd < divs => return ans