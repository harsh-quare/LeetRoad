class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 || k == 1) return 0;
        if(n == 2) return k == 1 ? 0 : 1;

        //if k lies in the first half
        if(k <= (1 << (n-2))){
            return kthGrammar(n-1, k);
        }
        //if k lies in the second half, look at the corresponding element in the first half and flip the result
        else{
            return !kthGrammar(n-1, k - (1 << (n-2)));
        }

    }
};