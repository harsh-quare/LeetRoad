class Solution {
public:
    vector<int> getVectorCountFormat(int n){
        vector<int> v(10, 0);  // 10 digits

        while(n){
            v[n%10]++;
            n /= 10;
        }

        return v;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> cur = getVectorCountFormat(n);

        for(int p = 0; p <= 30; p++){
            if(cur == getVectorCountFormat(1 << p)){
                return true;
            }
        }

        return false;
    }
};