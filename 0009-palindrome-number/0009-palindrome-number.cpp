class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int num = x;
        int revNum = 0;
        while(num){
            int dig = num%10;
            if(revNum < INT_MAX/10) revNum = revNum*10 + dig;
            num /= 10;
        }
        return (revNum == x);
    }
};