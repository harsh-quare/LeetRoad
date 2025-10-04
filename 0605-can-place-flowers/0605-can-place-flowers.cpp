class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        if(sz == 1 && flowerbed[0] == 0) return n<=1;

        for(int i = 0; i < sz; i++){
            if(flowerbed[i] == 1) continue;

            if((i == 0 && flowerbed[i+1] == 0) || (i == sz-1 && flowerbed[i-1] == 0) || (i > 0 && i < sz-1 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0)){
                cout << i << endl;
                n--;
                flowerbed[i] = 1;
            }

            if(n == 0) return true;
        }
        return n <= 0;
    }
};