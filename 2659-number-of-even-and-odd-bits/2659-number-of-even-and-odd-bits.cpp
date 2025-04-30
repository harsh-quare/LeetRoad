class Solution {
public:
    vector<int> evenOddBit(int n) {
        int odds = 0;
        int evens = 0;
        int i = 0;
        while(n){
            if((n & 1) == 1){
                if(i % 2 == 0) evens++;
                else odds++;
            }
            i++;
            n >>= 1;
        }

        return {evens, odds};
    }
};