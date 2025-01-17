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

// derived array: 
// Even size: d[0], d[1], d[2], d[3] => o[0]^o[1], o[1]^o[2], o[2]^o[3], o[3]^o[0] => Now we can see, what's interesting
// If we xor all elements of derived: o[0]^o[1]^o[1]^o[2]^o[2]^o[3]^o[3]^o[0] => Everything will cancel out each other => 0
// Similarly for odd size, Here the parity of the size doesn't matter because we are taking adjacent elements and also circular array, which
// will result in all elements appearing twice => Hence resulting in xor = 0;