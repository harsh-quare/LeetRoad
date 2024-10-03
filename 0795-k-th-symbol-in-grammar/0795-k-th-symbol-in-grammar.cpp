class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;

        int par = kthGrammar(n-1, (k+1)/2);
        // agar k odd h, to hamare paas 2 options h, ya to ye 0 ke child(01) me odd bana ho means 0 answer
        // and if ye 1 ke child(10) me odd bana ho, means answer is 1
        bool isOdd = k%2 == 1;

        if(par == 1) return isOdd ? 1 : 0;
        else return isOdd ? 0 : 1;
    }
};