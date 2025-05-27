class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum = n*(n+1)/2;
        int num1 = 0;
        for(int i = 1; i <= n; i++){
            if(i % m != 0) num1 += i;
        }

        // num2 = totalSum - num1;
        // num1 - num2 = 2*num1 - totalSum;

        return 2*num1 - totalSum; 
    }
};