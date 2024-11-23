class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10) return false;
        int i = 10;
        bool alice = 1;
        while(n-i >= 0){
            n -= i;
            i--;
            alice = 1 - alice;
        }

        if(alice == true) return false;
        return true;
    }
};