class Solution {
public:
    #define ll long long
    int countf(ll curr, ll nxt, int n){
        int cnt = 0;
        while(curr <= n){
            cnt += min(nxt, (ll)n+1) - curr;  // nxt ki max value = curr(max) + 1 => n+1
            
            // next level me chale jao
            curr *= 10;
            nxt *= 10;
        }

        return cnt;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;  // current number
        k -= 1;  // 1 le liya, to isko skip kr do

        while(k > 0){
            int cntNum = countf(curr, curr + 1, n);  // we want to know about numbers starting with prefix "curr" => numbers between curr and curr + 1

            if(cntNum <= k){
                curr++;  // next prefix me chale jao, 1 se 2 me...
                k -= cntNum;  // itne number skip kr diye
            }
            else{  // since the numbers are more, means the answer starts with this prefix only, so I need to go deeper in the tree to find the number
                curr *= 10;  // go deeper, qki hamara answer isi prefix subtree me h, qki iss prefix subtree ke saare bnde lene se cnt > k ho rha h
                k--;  // current element le liya, to isko count kr lo
            }
        }

        return curr;
    }
};