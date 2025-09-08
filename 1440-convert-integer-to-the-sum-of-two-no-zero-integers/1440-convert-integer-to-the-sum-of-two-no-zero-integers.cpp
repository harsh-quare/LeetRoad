class Solution {
public:
    bool has_0(int x){
        while(x){
            if(x % 10 == 0){
                return true;
            }
            x /= 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        int b = n-a;

        while(has_0(a) || has_0(b)){
            a++;
            b--;
        }

        return {a,b};
    }
};