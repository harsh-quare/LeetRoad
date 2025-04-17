class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        unordered_map<int, vector<int>> idxMap;
        for(int i = 0; i < n; i++){
            idxMap[nums[i]].push_back(i);
        }

        // find out all the divisors of k
        // k = 36 => 1, 2, 3, 4, 6, 6, 9, 12, 18, 36
        unordered_set<int> div;  // to avoid duplicates, like 6,6
        for(int f = 1; f*f <= k; f++){  // O(sqrt(k))
            if(k % f == 0){
                div.insert(f); // {1, 2, 3, 4, 6}
                div.insert(k/f);  // the remaining divisors => 1 -> 36, 2 -> 18, 3->12
            }
        }


        // traverse the indices, and try to calculate the answer
        // for i*j to be divisible by k, j must be divisible by k/gcd(i,k)
        // j will hold that divisor which i couldn't get to be divisible by k 

        // O(n * (log(k) + sqrt(k)))
        for(auto& [val, indices]: idxMap){
            unordered_map<int, int> factorsMap;
            for(int i: indices){
                int GCD = gcd(i, k);  // t.c.: log(k)
                int j = k / GCD;

                ans += factorsMap[j];

                for(int f: div){  // for future indices
                    if(i % f == 0){
                        factorsMap[f]++;
                    }
                }
            }
        }

        return ans;
    }
};