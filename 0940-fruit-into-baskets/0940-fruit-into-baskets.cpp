class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxLen = 0;
        unordered_map<int, int> mp;  // fruit type -> freq

        int i = 0, j = 0;

        while(j < n){
            mp[fruits[j]]++;

            while(i < n && mp.size() > 2){
                // means more than 2 types at a time
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }

            // now, the mp size is 2, update the answer
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};