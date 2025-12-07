class Solution {
public:
    int countOdds(int low, int high) {
        int lmod = low % 2, hmod = high % 2;
        if(lmod == 0 && hmod == 0) return (high - low) / 2; 
        return (high - low)/2 + 1;
    }
};