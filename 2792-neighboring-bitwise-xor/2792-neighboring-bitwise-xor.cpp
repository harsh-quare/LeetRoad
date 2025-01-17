class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // If the derived array is valid, its will follow the condition: der[0]^der[1]^...der[n-2]^der[n-1] == 0
        int xorVal = 0;
        for(int x: derived){
            xorVal ^= x;
        }

        return xorVal == 0;
    }
};