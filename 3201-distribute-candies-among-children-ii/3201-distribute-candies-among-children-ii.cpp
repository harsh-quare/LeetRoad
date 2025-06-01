class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        if(limit*3 < n) return 0;
        // one thing is for sure, 0 <= i,j,k <= limit
        // we nned to somehow reduce the time coplexity to linear
        // Let's try that.
        // We only loop i from 0 to limit
        // that means now I have 2 other variables to make a decision upon
        for(int i = 0; i <= min(limit, n); i++){  // one kid is done
            long long remaining_candies = n - i;  // let's call it 'x'
            // Now I have to distribut it between j and k, the two other kids
            // I have to divide 'x' bw two kids, who also have their conditions 0 <= j,k <= limit
            // that means
            // if x = 10, limit = 6
            // j       k
            // 0       10   => k > limit
            // 1       9    => k > limit 
            // 2       8    => k > limit
            // 3       7    => k > limit
            // 4       6    => valid
            // 5       5    => valid
            // 6       4    => valid
            // 7       3    => j > limit
            // 8       2    => j > limit
            // 9       1    => j > limit
            // 10      0    => j > limit

            // but we know, they both only allow values in the range [0,limit]
            // so we can see only 3 guys are valid
            // for j, that ranges from: (x-limit) -> limit
            // for k, that ranges from: limit -> (x-limit)
            // so total combinations = 6-4+1 => limit - (x - limit) + 1

            // and another thing we noticed is that, if here, limit < x/2 or limit*2 < x => then no possible way to make a combo
            // for example, take x = 10, and limit = {0,1,2,3,4} => they can make 0 valid pairs

            if(limit >= remaining_candies){   // limit >= x
                ans += remaining_candies + 1;  // j => [0, candies_left], k[candies_left, 0]
            }
            else{
                long long numCnt = limit - (remaining_candies - limit) + 1;
                ans += max(numCnt, 0LL);
            }

            // cout << i << " " << ans << endl;
        }

        return ans;
    }
};

// Brute force: O(n^3)
// long long cnt = 0;
// for(int i = 0; i <= limit; i++){
//     for(int j = 0; j <= limit; j++){
//         for(int k = 0; k <= limit; k++){
//             if(i+j+k == n) cnt++;
//         }
//     }
// }

// Better: O(n^2)
// long long cnt = 0;
// for(int i = 0; i <= limit; i++){
//     for(int j = 0; j <= limit; j++){
//         int k = n - i - j;
//         if(k >= 0 && k <= limit) cnt++;
//     }
// }