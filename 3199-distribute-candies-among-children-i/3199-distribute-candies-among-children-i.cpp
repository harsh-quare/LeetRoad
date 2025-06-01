class Solution {
public:
    int solve(int n, int lim, int child){
        if(n < 0) return 0;  // no more candies left

        if(child == 1){  // last child left
            if(n <= lim) return 1;  // and remaining candies are under limit, one way
            else return 0;
        }

        int cnt = 0;
        for(int i = 0; i <= lim; i++){
            cnt += solve(n - i, lim, child-1);
        }

        return cnt;
    }
    int distributeCandies(int n, int limit) {
        return solve(n, limit, 3);
    }
};