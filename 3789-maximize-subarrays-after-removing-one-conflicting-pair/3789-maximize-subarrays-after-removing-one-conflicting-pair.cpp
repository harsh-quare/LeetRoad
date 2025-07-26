class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        // for every [a,b] pair in conflicting pairs, I will store all the available startPoints(a) for each endPoint(b)
        vector<vector<int>> lefts(n+1);
        for(auto& p: conflictingPairs){
            int a = min(p[0], p[1]);
            int b = max(p[0], p[1]);

            // 'b' me 'a' ko start point daal do
            lefts[b].push_back(a);
        }

        // for each b, we try to find the max value of 'a', [1,4] and [2,4] => for '4', '2' will be more stricter, bcz it will be part of more subarrays that will be lost
        // so, we just get the total ans while considering all the conflicting pairs
        // and simultaneously calculate what bonus extra we can get, if we remove the strictest value of 'a' for each 'b'
        // and finally, Bcz I can only remove one pair, so I will remove the one which is giving me maximum bonus value

        long long ans = 0;
        long long max_a1 = 0, max_a2 = 0;  // 'max_a1' is the strictest 'a' (the largest), 'max_a2' is the second largest 'a'
        vector<long long> bonus(n+1);

        // looping through each end point
        for(int b = 1; b <= n; b++){
            for(auto a: lefts[b] ){
                if(a > max_a1){  // new strictest(max) mil gya
                    max_a2 = max_a1;  // prev_max ko 2nd max bna do
                    max_a1 = a;   //and new max ko first max
                }
                else if(a > max_a2){  // between a1 and a2 h, to only a2 ko update krdo
                    max_a2 = a;
                }
            }

            // this is the number of subarrayarrays, while considering the strictest 'a'
            ans += (b - max_a1);  // This represents how many subarrays can be formed that include 'b' but exclude 'max_a1'

            //if max_a1 is greater than 0, we can consider removing it and calculate the bonus
            if(max_a1 > 0){   // remove the stricter criteria
                bonus[max_a1] += (max_a1 - max_a2);  //the bonus is the diff bw 'max_a1' and 'max_a2' since removing 'max_a1' will allow subarrays that were previously blocked by 'max_a1' to be included
            }
        }

        //find the maximum bonus that can be obtained by removing the strictest 'a' for any 'b'
        long long maxBonus = 0;
        for(auto bns: bonus) maxBonus = max(maxBonus, bns);

        //return the total answer plus the maximum bonus we can get by removing the strictest 'a'
        return ans + maxBonus;
    }
};