class Solution {
public:
    char kthCharacter(int k) {
        // Number of shifts == count of set bits in binday representation of (k-1)
        int shifts= __builtin_popcount(k-1);
        return 'a' + shifts;
    }
};