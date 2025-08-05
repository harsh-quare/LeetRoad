class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int allotted = 0;

        for(int i = 0; i < n; i++){
            int f = fruits[i];

            for(int j = 0; j < n; j++){
                if(baskets[j] >= f){
                    baskets[j] = -1;  // mark used
                    allotted++;
                    break;
                }
            }
        }

        return n - allotted;
    }
};