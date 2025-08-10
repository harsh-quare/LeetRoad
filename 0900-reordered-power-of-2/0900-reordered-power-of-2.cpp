class Solution {
public:
    int getNumberCountFormat(int x){
        int num = 0;

        while(x){
            int dig = x % 10;
            num += pow(10, dig);

            x /= 10;
        }

        return num;
    }
    bool reorderedPowerOf2(int n) {
        int cur = getNumberCountFormat(n);

        for(int p = 0; p <= 30; p++){
            if(cur == getNumberCountFormat(1 << p)){
                return true;
            }
        }

        return false;
    }
};