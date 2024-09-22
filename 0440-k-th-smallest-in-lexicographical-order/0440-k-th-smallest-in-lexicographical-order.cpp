class Solution {
public:
    int solve(long cur, long nxt, int n){
        int cntNum = 0;

        while(cur <= n){
            cntNum += (nxt-cur);  //number of elements in the same level between nxt and cur
            
            //go deeper
            cur*=10;
            nxt*=10;

            nxt = min(nxt, long(n+1));
        }

        return cntNum;
    }
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--; // 1 is already used, k-1 left

        while(k > 0){
            int cnt = solve(cur, cur+1, n);

            if(cnt <= k){
                //mtlb iss prefix ko lene se k tk nhi pahuch paa rhe, to next prefix(1,2,3,4,...9) pe chale jao
                cur++;
                k -= cnt;  //and current prefix tree wale bnde skip krdo
            }
            else{
                //same prefix tree me deeper jaana padega
                cur *= 10;
                k--; //har ek level se ek bnda hi aayega, qki deeper jaate ja rhe h, only root consider hoga
            }
        }

        return cur;
    }
};