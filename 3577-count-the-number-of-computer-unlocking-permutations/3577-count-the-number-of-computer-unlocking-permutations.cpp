class Solution {
public:
    const int mod = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();

        long long ans = 1;
        for(int i = 1; i < n; i++){
            if(complexity[i] <= complexity[0]) return 0;
            else ans = (1LL * ans * i) % mod;
        }

        return ans % mod;
    }
};

// 0 is already decrypted, freed
// for any computer to unlock, we need some previously unlocked computer
// for unlocking computer[i], we need a computer j (j < i) and complexity[j] < complexity[i], and j should be unlocked


// 0, 1,2, 4, 3


// 1,2,3
// 0,1,2 
// 0 -> 1,2
// 1 -> 2


// 3,3,3,4,4,4
// 0,1,2,3,4,5
// 0 -> 3,4,5
// 1 -> 3,4,5
// 2 -> 3,4,5
// 3 -> 
// 4 -> 
// 5 ->


// 1,2,2,4,3
// 0,1,2,3,4

// 0th -> 0 -> 1
// 1st -> 2,2,4,3 -> 4
// 2nd -> 4,3,2-> 3
// 3rd -> 4,3 -> 2
// 4th -> 4 -> 1


// _, _, _, ..., _  => n places
// we need to put n elements in n places
// 0th -> 0 -> 1
// 1st -> 1,2 -> 2
// 2nd -> 2,1 -> 1

