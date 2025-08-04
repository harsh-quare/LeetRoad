class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;

        // expand window to right while adding fruits
        // and shrink from left only if you get more than 2 type of fruits

        unordered_map<int, int> curTypes;
        int i = 0;
        int j = 0;
        while(j < fruits.size()){

            curTypes[fruits[j]]++;

            while(curTypes.size() > 2){
                // remove the left one
                curTypes[fruits[i]]--;
                if(curTypes[fruits[i]] == 0) curTypes.erase(fruits[i]);
                i++;
            }

            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};